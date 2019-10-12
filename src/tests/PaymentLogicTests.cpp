//
//  SchoolEntities.cpp
//  TestMockStub
//
//  Created by Alex Usachov on 9/23/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#include "SchoolEntities.hpp"

#include "CppUTest/TestHarness.h"

TEST_GROUP(FreePaymentLogicGroup)
{
};

TEST(FreePaymentLogicGroup, MakeStartPayment_ForGenuisPupilWithEnoughCash_ReturnsTrue)
{
   cFreePaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(Logic.GetPaymentValue());
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(FreePaymentLogicGroup, MakeStartPayment_ForGenuisPupilWithNotEnoughCash_ReturnsTrue)
{
   cFreePaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(Logic.GetPaymentValue() / 2);
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(FreePaymentLogicGroup, MakeStartPayment_ForCleverPupilWithEnoughCash_ReturnsTrue)
{
   cFreePaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(Logic.GetPaymentValue());
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(FreePaymentLogicGroup, MakeStartPayment_ForCleverPupilWithNotEnoughCash_ReturnsTrue)
{
   cFreePaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(Logic.GetPaymentValue() / 2);
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(FreePaymentLogicGroup, MakeStartPayment_ForForgetfulPupilWithEnoughCash_ReturnsTrue)
{
   cFreePaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(Logic.GetPaymentValue());
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(FreePaymentLogicGroup, MakeStartPayment_ForForgetfulPupilWithNotEnoughCash_ReturnsTrue)
{
   cFreePaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(Logic.GetPaymentValue() / 2);
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST_GROUP(GeniusFreeStudyPaymentLogicGroup)
{
};

TEST(GeniusFreeStudyPaymentLogicGroup, MakeStartPayment_ForGenuisPupilWithEnoughCash_ReturnsTrue)
{
   cGeniusFreeStudyPaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(Logic.GetPaymentValue());
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(GeniusFreeStudyPaymentLogicGroup, MakeStartPayment_ForGenuisPupilWithNotEnoughCash_ReturnsTrue)
{
   cGeniusFreeStudyPaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create(Logic.GetPaymentValue() / 2);
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(GeniusFreeStudyPaymentLogicGroup, MakeStartPayment_ForCleverPupilWithEnoughCash_ReturnsTrue)
{
   cGeniusFreeStudyPaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(Logic.GetPaymentValue());
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(GeniusFreeStudyPaymentLogicGroup, MakeStartPayment_ForCleverPupilWithNotEnoughCash_ReturnsFalse)
{
   cGeniusFreeStudyPaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(Logic.GetPaymentValue() / 2);
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_FALSE(RetVal);
}

TEST(GeniusFreeStudyPaymentLogicGroup, MakeStartPayment_ForForgetfulPupilWithEnoughCash_ReturnsTrue)
{
   cGeniusFreeStudyPaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(Logic.GetPaymentValue());
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_TRUE(RetVal);
}

TEST(GeniusFreeStudyPaymentLogicGroup, MakeStartPayment_ForForgetfulPupilWithNotEnoughCash_ReturnsFalse)
{
   cGeniusFreeStudyPaymentLogic Logic;
   std::shared_ptr<IPupil> Pupil = cForgetfulPupil::Create(Logic.GetPaymentValue() / 2);
   
   const bool RetVal = Logic.MakeStartPayment(Pupil);
   
   CHECK_FALSE(RetVal);
}
