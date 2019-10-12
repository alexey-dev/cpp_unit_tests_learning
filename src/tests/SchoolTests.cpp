//
//  SchoolEntities.cpp
//  TestMockStub
//
//  Created by Alex Usachov on 9/23/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#include "SchoolEntities.hpp"

#include "CppUTest/TestHarness.h"

TEST_GROUP(SchoolGroup)
{
};

TEST(SchoolGroup, AcceptNewPupil_AnyPupil_ReturnsTrueAndPupilsListIncreased)
{
   cSchool School(std::make_shared<cGeniusFreeStudyPaymentLogic>());
   std::shared_ptr<IPupil> Pupil = cGeniusPupil::Create();
   
   const bool RetVal = School.AcceptNewPupil(Pupil);
   
   CHECK_TRUE(RetVal && (School.GetPupils().size() == 1));
}

TEST(SchoolGroup, AcceptNewPupil_AnyPupilNotAcceptable_ReturnsFalseAndPupilsListSameSize)
{
    std::shared_ptr<IPaySchoolLogic> PaymentLogic = std::make_shared<cGeniusFreeStudyPaymentLogic>();
    cSchool School(PaymentLogic);
    std::shared_ptr<IPupil> Pupil = cCleverPupil::Create(PaymentLogic->GetPaymentValue() / 2);

    const bool RetVal = School.AcceptNewPupil(Pupil);

    CHECK_TRUE((RetVal == false) && School.GetPupils().empty());
}
