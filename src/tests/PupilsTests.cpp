//
//  SchoolEntities.cpp
//  TestMockStub
//
//  Created by Alex Usachov on 9/23/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#include "SchoolEntities.hpp"
#include "CppUTest/TestHarness.h"

TEST_GROUP(GeniusPupilGroup)
{
};

TEST(GeniusPupilGroup, PassExam_SimpleGetValue_ReturnsFive)
{
   std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create();
   
   const eSchoolMark RetMark = Pupil->PassExam();
   
   CHECK(RetMark == eSchoolMark::Five);
}

TEST(GeniusPupilGroup, PayFromGeniusConditions_PassEnoughCash_ReturnsTrue)
{
    constexpr int CASH = 100;
    std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayFromGeniusConditions(CASH);
   
    CHECK_TRUE(RetVal);
}

TEST(GeniusPupilGroup, PayFromGeniusConditions_PassNotEnoughCash_ReturnsTrue)
{
    constexpr int CASH = 100;
    std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(CASH / 2);
   
    const bool RetVal = Pupil->PayFromGeniusConditions(CASH);
   
    CHECK_TRUE(RetVal);
}

TEST(GeniusPupilGroup, PayForStudy_PassEnoughCash_ReturnsTrueAndSubCash)
{
    constexpr int CASH = 100;
    constexpr int PAY_SUM = CASH;
    std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayForStudy(PAY_SUM);
    const int  AwaitingCashLeft = CASH - PAY_SUM;
   
    CHECK_TRUE(RetVal && (Pupil->GetCash() == AwaitingCashLeft));
}

TEST(GeniusPupilGroup, PayForStudy_PassNotEnoughCash_ReturnsFalseAndSubCash)
{
    constexpr int CASH = 100;
    constexpr int PAY_SUM = CASH * 2;
    std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayForStudy(PAY_SUM);
    const int  AwaitingCashLeft = CASH;
   
    CHECK_TRUE((RetVal == false) && (Pupil->GetCash() == AwaitingCashLeft));
}

TEST_GROUP(CleverPupilGroup)
{
};

TEST(CleverPupilGroup, PassExam_SimpleGetValue_ReturnsFour)
{
   std::shared_ptr<IPupil> Pupil = cCleverPupil::Create();
   
   const eSchoolMark RetMark = Pupil->PassExam();
   
   CHECK(RetMark == eSchoolMark::Four);
}

TEST(CleverPupilGroup, PayFromGeniusConditions_PassEnoughCash_ReturnsTrue)
{
    constexpr int CASH = 100;
    std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayFromGeniusConditions(CASH);
   
    CHECK_TRUE(RetVal);
}

TEST(CleverPupilGroup, PayFromGeniusConditions_PassNotEnoughCash_ReturnsFalse)
{
    constexpr int CASH = 100;
    std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(CASH / 2);
   
    const bool RetVal = Pupil->PayFromGeniusConditions(CASH * 2);
   
    CHECK_FALSE(RetVal);
}

TEST(CleverPupilGroup, PayForStudy_PassEnoughCash_ReturnsTrueAndSubCash)
{
    constexpr int CASH = 100;
    constexpr int PAY_SUM = CASH;
    std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayForStudy(PAY_SUM);
    const int  AwaitingCashLeft = CASH - PAY_SUM;
   
    CHECK_TRUE(RetVal && (Pupil->GetCash() == AwaitingCashLeft));
}

TEST(CleverPupilGroup, PayForStudy_PassNotEnoughCash_ReturnsFalseAndSubCash)
{
    constexpr int CASH = 100;
    constexpr int PAY_SUM = CASH * 2;
    std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayForStudy(PAY_SUM);
    const int  AwaitingCashLeft = CASH;
   
    CHECK_TRUE((RetVal == false) && (Pupil->GetCash() == AwaitingCashLeft));
}

TEST_GROUP(ForgetfulPupilGroup)
{
};

TEST(ForgetfulPupilGroup, PassExam_SimpleGetValue_ReturnsThree)
{
   std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create();
   
   const eSchoolMark RetMark = Pupil->PassExam();
   
   CHECK(RetMark == eSchoolMark::Three);
}

TEST(ForgetfulPupilGroup, PayFromGeniusConditions_PassEnoughCash_ReturnsTrue)
{
    constexpr int CASH = 100;
    std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayFromGeniusConditions(CASH);
   
    CHECK_TRUE(RetVal);
}

TEST(ForgetfulPupilGroup, PayFromGeniusConditions_PassNotEnoughCash_ReturnsFalse)
{
    constexpr int CASH = 100;
    std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(CASH / 2);
   
    const bool RetVal = Pupil->PayFromGeniusConditions(CASH * 2);
   
    CHECK_FALSE(RetVal);
}

TEST(ForgetfulPupilGroup, PayForStudy_PassEnoughCash_ReturnsTrueAndSubCash)
{
    constexpr int CASH = 100;
    constexpr int PAY_SUM = CASH;
    std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayForStudy(PAY_SUM);
    const int  AwaitingCashLeft = CASH - PAY_SUM;
   
    CHECK_TRUE(RetVal && (Pupil->GetCash() == AwaitingCashLeft));
}

TEST(ForgetfulPupilGroup, PayForStudy_PassNotEnoughCash_ReturnsFalseAndSubCash)
{
    constexpr int CASH = 100;
    constexpr int PAY_SUM = CASH * 2;
    std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(CASH);
   
    const bool RetVal = Pupil->PayForStudy(PAY_SUM);
    const int  AwaitingCashLeft = CASH;
   
    CHECK_TRUE((RetVal == false) && (Pupil->GetCash() == AwaitingCashLeft));
}
