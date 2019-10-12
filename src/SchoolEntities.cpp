//
//  SchoolEntities.cpp
//  TestMockStub
//
//  Created by Alex Usachov on 9/23/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#include "SchoolEntities.hpp"

cSchool::cSchool(std::shared_ptr<IPaySchoolLogic> _payLogic) :
    mPayLogic(_payLogic)
{}
    
bool
cSchool::AcceptNewPupil(std::shared_ptr<IPupil> _pupil)
{
    if (mPayLogic->MakeStartPayment(_pupil))
    {
        mPupils.emplace_back(_pupil);
        return true;
    }
    else
    {
        return false;
    }
}
    
void
cSchool::PassExams()
{
    
}

const std::vector<std::shared_ptr<IPupil>> &
cSchool::GetPupils() const
{
    return mPupils;
}

int
IPaySchoolLogic::GetPaymentValue() const
{
    return 50;
}

bool
cGeniusFreeStudyPaymentLogic::MakeStartPayment(std::shared_ptr<IPupil> _pupil) const
{
    
    if (_pupil->PayFromGeniusConditions(GetPaymentValue()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool
cFreePaymentLogic::MakeStartPayment(std::shared_ptr<IPupil> _pupil) const
{
    return true;
}

IPupil::IPupil(const int _cash) :
    mCash(_cash)
{
}

bool
IPupil::PayForStudy(const int _sumOfPay)
{
    if (mCash >= _sumOfPay)
    {
        mCash -= _sumOfPay;
        return true;
    }
    else
    {
        return false;
    }
}

bool
IPupil::PayFromGeniusConditions(const int _sumOfPay)
{
    return PayForStudy(_sumOfPay);
}

int
IPupil::GetCash() const
{
    return mCash;
}

bool
cGeniusPupil::PayFromGeniusConditions(const int _sumOfPay)
{
    return true;
}

eSchoolMark
cGeniusPupil::PassExam()
{
    return eSchoolMark::Five;
}

eSchoolMark
cCleverPupil::PassExam()
{
    return eSchoolMark::Four;
}

eSchoolMark
cForgetfulPupil::PassExam()
{
    return eSchoolMark::Three;
}

std::shared_ptr<IPupil>
cGeniusPupil::Create(const int _cash)
{
    return std::make_shared<cGeniusPupil>(_cash);
}

std::shared_ptr<IPupil>
cCleverPupil::Create(const int _cash)
{
    return std::make_shared<cCleverPupil>(_cash);
}

std::shared_ptr<IPupil>
cForgetfulPupil::Create(const int _cash)
{
    return std::make_shared<cForgetfulPupil>(_cash);
}

cGeniusPupil::cGeniusPupil(const int _cash) :
    IPupil(_cash)
{}

cCleverPupil::cCleverPupil(const int _cash) :
    IPupil(_cash)
{}

cForgetfulPupil::cForgetfulPupil(const int _cash) :
    IPupil(_cash)
{}
