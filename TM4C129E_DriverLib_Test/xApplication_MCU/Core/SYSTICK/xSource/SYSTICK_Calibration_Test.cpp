/**
 *
 * @file SYSTICK_Calibration_Test.cpp
 * @copyright
 * @verbatim InDeviceMex 2026 @endverbatim
 *
 * @par Responsibility
 * @verbatim InDeviceMex Developers @endverbatim
 *
 * @version
 * @verbatim 1.0 @endverbatim
 *
 * @date
 * @verbatim 29 mar. 2026 @endverbatim
 *
 * @author
 * @verbatim GitHub Copilot @endverbatim
 *
 * @par Change History
 * @verbatim
 * Date           Author           Version     Description
 * 29 mar. 2026   GitHub Copilot   1.0         initial Version@endverbatim
 */

extern "C"
{
#include <xApplication_MCU/Core/SYSTICK/xHeader/SYSTICK_Calibration.h>
}

#include <tm4c129e_test/SYSTICK_CalibrationDriverMock.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;
using ::testing::StrictMock;

/**
 * @brief Validate fallback timing conversion when CALIB is not trusted.
 * @summary Confirms that the timing helper falls back to direct frequency-based
 *          conversion when the calibration data reports an inexact skew value.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetTickTimingPsFallsBackWhenCalibrationIsNotTrusted)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    uint64_t u64TickPsReg;
    uint64_t u64PeriodPsReg;

    u64TickPsReg = 0ULL;
    u64PeriodPsReg = 0ULL;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .Times(1)
        .WillRepeatedly(DoAll(SetArgPointee<1>((UBase_t) 1199999UL), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationSkew(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enSKEW_INEXACT), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationReference(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enREFERENCE_EXTERNAL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetTickTimingPs(SYSTICK_enMODULE_0, 1200UL, 120UL, &u64TickPsReg, &u64PeriodPsReg));

    EXPECT_EQ(8333ULL, u64TickPsReg);
    EXPECT_EQ(10000000ULL, u64PeriodPsReg);
}

/**
 * @brief Validate trusted timing correction from the CALIB error ratio.
 * @summary Confirms that exact reference-backed CALIB data is used as an error
 *          factor relative to the nominal PIOSC/4 basis, so the helper adjusts
 *          the SYSCLK-derived timing instead of replacing it with raw 4 MHz
 *          reference-clock timing.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetTickTimingPsUsesTrustedReferenceCalibrationWhenSystemClockDiffers)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    uint64_t u64TickPsReg;
    uint64_t u64PeriodPsReg;

    u64TickPsReg = 0ULL;
    u64PeriodPsReg = 0ULL;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .Times(1)
        .WillRepeatedly(DoAll(SetArgPointee<1>((UBase_t) 39960UL), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationSkew(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enSKEW_EXACT), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationReference(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enREFERENCE_EXTERNAL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetTickTimingPs(SYSTICK_enMODULE_0, 1200UL, 120UL, &u64TickPsReg, &u64PeriodPsReg));

    EXPECT_EQ(8341ULL, u64TickPsReg);
    EXPECT_EQ(10010010ULL, u64PeriodPsReg);
}

/**
 * @brief Validate that exact CALIB deviation remains trusted.
 * @summary Confirms that a CALIB count differing from the nominal 40000 value is
 *          still accepted when SKEW is exact and the external reference exists,
 *          because the deviation is used as the correction factor.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetTrustedCalibrationInfoAcceptsExactReferenceCountDeviation)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    SYSTICK_CALIBRATION_INFO_t stInfoReg;

    stInfoReg.uxCalibrationCount10Ms = 0UL;
    stInfoReg.uxCalibrationCount1Ms = 0UL;
    stInfoReg.u64CalibrationTickPs = 0ULL;
    stInfoReg.enSkew = SYSTICK_enSKEW_UNDEF;
    stInfoReg.enReference = SYSTICK_enREFERENCE_UNDEF;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) 39960UL), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationSkew(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enSKEW_EXACT), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationReference(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enREFERENCE_EXTERNAL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetTrustedCalibrationInfo(SYSTICK_enMODULE_0, &stInfoReg));
    EXPECT_EQ((UBase_t) 39960UL, stInfoReg.uxCalibrationCount10Ms);
}

/**
 * @brief Validate that CALIB TENMS is interpreted as a tick count.
 * @summary Confirms that the calibration info helper treats the raw 10 ms value
 *          as a direct 1..N tick count, derives the rounded 1 ms count from it,
 *          and computes tick timing from that count basis without adding one.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetCalibrationInfoTreatsTenMsValueAsTickCount)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    SYSTICK_CALIBRATION_INFO_t stInfoReg;

    stInfoReg.uxCalibrationCount10Ms = 0UL;
    stInfoReg.uxCalibrationCount1Ms = 0UL;
    stInfoReg.u64CalibrationTickPs = 0ULL;
    stInfoReg.enSkew = SYSTICK_enSKEW_UNDEF;
    stInfoReg.enReference = SYSTICK_enREFERENCE_UNDEF;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) 1200000UL), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationSkew(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enSKEW_EXACT), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationReference(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enREFERENCE_EXTERNAL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetCalibrationInfo(SYSTICK_enMODULE_0, &stInfoReg));
    EXPECT_EQ((UBase_t) 1200000UL, stInfoReg.uxCalibrationCount10Ms);
    EXPECT_EQ((UBase_t) 120000UL, stInfoReg.uxCalibrationCount1Ms);
    EXPECT_EQ(8333ULL, stInfoReg.u64CalibrationTickPs);
}

/**
 * @brief Validate the concrete 10 ms count to 1 ms reload example.
 * @summary Confirms that a raw CALIB TENMS value of 40000 is treated as 40000
 *          ticks for 10 ms and therefore produces a 1 ms SysTick reload value
 *          of 3999 through the reload-specific helper.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetCalibrationReloadUsUsesTenMsCountExample)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    UBase_t uxReloadReg;

    uxReloadReg = 0UL;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) 40000UL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetCalibrationReloadUs(SYSTICK_enMODULE_0, 1000UL, &uxReloadReg));
    EXPECT_EQ((UBase_t) 3999UL, uxReloadReg);
}

/**
 * @brief Validate the inverse reload to time example.
 * @summary Confirms that a SysTick reload value of 3999 converts back to 1000 us
 *          when the raw CALIB TENMS value is 40000 ticks for 10 ms.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetCalibrationTimeUsUsesInverseTenMsCountExample)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    UBase_t uxTimeUsReg;

    uxTimeUsReg = 0UL;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>((UBase_t) 40000UL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetCalibrationTimeUs(SYSTICK_enMODULE_0, 3999UL, &uxTimeUsReg));
    EXPECT_EQ((UBase_t) 1000UL, uxTimeUsReg);
}

/**
 * @brief Validate fallback tick-count conversion when CALIB is not trusted.
 * @summary Confirms that the microsecond conversion helper preserves the direct
 *          frequency-based count when the calibration data is present but cannot
 *          be trusted for the active clock basis.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetTickCountUsFallsBackWhenCalibrationIsNotTrusted)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    UBase_t uxTickCountReg;

    uxTickCountReg = 0UL;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .Times(1)
        .WillRepeatedly(DoAll(SetArgPointee<1>((UBase_t) 1200000UL), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationSkew(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enSKEW_INEXACT), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationReference(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enREFERENCE_EXTERNAL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetTickCountUs(SYSTICK_enMODULE_0, 1000UL, 120UL, &uxTickCountReg));
    EXPECT_EQ((UBase_t) 120000UL, uxTickCountReg);
}

/**
 * @brief Validate trusted tick-count correction for microseconds.
 * @summary Confirms that the trusted conversion path applies the CALIB ratio to
 *          the SYSCLK-derived nominal tick count instead of replacing it with a
 *          raw 4 MHz reference-clock count.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetTickCountUsUsesTrustedCalibrationConversion)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    UBase_t uxTickCountReg;

    uxTickCountReg = 0UL;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .Times(1)
        .WillRepeatedly(DoAll(SetArgPointee<1>((UBase_t) 39960UL), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationSkew(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enSKEW_EXACT), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationReference(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enREFERENCE_EXTERNAL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetTickCountUs(SYSTICK_enMODULE_0, 1000UL, 120UL, &uxTickCountReg));
    EXPECT_EQ((UBase_t) 119880UL, uxTickCountReg);
}

/**
 * @brief Validate trusted tick-count correction for a CALIB count above nominal.
 * @summary Confirms that the trusted conversion path also handles positive error
 *          direction, increasing the SYSCLK-derived nominal tick count when the
 *          exact external-reference CALIB count is above the nominal 40000 basis.
 * @param[in] None.
 * @param[out] None.
 * @return None.
 * @dependencies
 * @verbatim
 * - SYSTICK_CalibrationDriverMock bridge
 * - Original source under test: SYSTICK_Calibration.c
 * - GoogleTest / GoogleMock expectation support@endverbatim
 */
TEST(SYSTICK_CalibrationTest, GetTickCountUsUsesTrustedCalibrationConversionAboveNominal)
{
    StrictMock<SYSTICK_CalibrationDriverMock> stMock;
    SYSTICK_CalibrationDriverMockScope stMockScope(&stMock);
    UBase_t uxTickCountReg;

    uxTickCountReg = 0UL;

    EXPECT_CALL(stMock, GetCalibrationValue(SYSTICK_enMODULE_0, testing::_))
        .Times(1)
        .WillRepeatedly(DoAll(SetArgPointee<1>((UBase_t) 40040UL), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationSkew(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enSKEW_EXACT), Return(SYSTICK_enERROR_OK)));
    EXPECT_CALL(stMock, GetCalibrationReference(SYSTICK_enMODULE_0, testing::_))
        .WillOnce(DoAll(SetArgPointee<1>(SYSTICK_enREFERENCE_EXTERNAL), Return(SYSTICK_enERROR_OK)));

    EXPECT_EQ(SYSTICK_enERROR_OK,
              SYSTICK__enGetTickCountUs(SYSTICK_enMODULE_0, 1000UL, 120UL, &uxTickCountReg));
    EXPECT_EQ((UBase_t) 120120UL, uxTickCountReg);
}