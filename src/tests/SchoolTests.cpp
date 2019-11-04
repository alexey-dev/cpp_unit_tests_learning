//
//  SchoolEntities.cpp
//  TestMockStub
//
//  Created by Alex Usachov on 9/23/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#include "SchoolEntities.hpp"
#include "CppUTest/TestHarness.h"
#include "Logger.hpp"
#include "Notifier.hpp"

class cFakeLogger : public ILogger
{
    public:
        virtual ~cFakeLogger() = default;
        virtual void Message(const std::string & _msg) override
        {
            //Fake logger message that does nothing
        }
};

class cFakeNotifier : public INotifier
{
    public:
        virtual void Notify(const eNotifyMsg & _notifyMsg) override
        {
            mLastMsg = _notifyMsg;
        }
};

TEST_GROUP(SchoolGroup)
{
};

TEST(SchoolGroup, AcceptNewPupil_AnyPupil_ReturnsTrueAndPupilsListIncreased)
{
    std::shared_ptr<ILogger>   StubLogger(new cFakeLogger);
    std::shared_ptr<INotifier> StubNotifier(new cFakeNotifier);
    cSchool                    School(std::make_shared<cGeniusFreeStudyPaymentLogic>(), StubLogger, StubNotifier);
    std::shared_ptr<IPupil>    Pupil = cGeniusPupil::Create();

    const bool RetVal = School.AcceptNewPupil(Pupil);

    CHECK_TRUE(RetVal && (School.GetPupils().size() == 1));
}

TEST(SchoolGroup, AcceptNewPupil_AnyPupilNotAcceptable_ReturnsFalseAndPupilsListSameSize)
{
    std::shared_ptr<ILogger>         StubLogger(new cFakeLogger);
    std::shared_ptr<INotifier>       StubNotifier(new cFakeNotifier);
    std::shared_ptr<IPaySchoolLogic> PaymentLogic = std::make_shared<cGeniusFreeStudyPaymentLogic>();
    cSchool                          School(PaymentLogic, StubLogger, StubNotifier);
    std::shared_ptr<IPupil>          Pupil = cCleverPupil::Create(PaymentLogic->GetPaymentValue() / 2);

    const bool RetVal = School.AcceptNewPupil(Pupil);

    CHECK_TRUE((RetVal == false) && School.GetPupils().empty());
}

TEST(SchoolGroup, AcceptNewPupil_NullLoggerInitialized_ReturnsFalseAndPupilsListSameSize)
{
    std::shared_ptr<ILogger>         NullLogger = nullptr;
    std::shared_ptr<INotifier>       StubNotifier(new cFakeNotifier);
    std::shared_ptr<IPaySchoolLogic> PaymentLogic = std::make_shared<cGeniusFreeStudyPaymentLogic>();
    cSchool                          School(PaymentLogic, NullLogger, StubNotifier);
    std::shared_ptr<IPupil>          Pupil = cGeniusPupil::Create();

    const bool RetVal = School.AcceptNewPupil(Pupil);

    CHECK_TRUE((RetVal == false) && School.GetPupils().empty());
}

TEST(SchoolGroup, AcceptNewPupil_NullNotifierInitialized_ReturnsFalseAndPupilsListSameSize)
{
    std::shared_ptr<ILogger>         StubLogger(new cFakeLogger);
    std::shared_ptr<INotifier>       NullNotifier = nullptr;
    std::shared_ptr<IPaySchoolLogic> PaymentLogic = std::make_shared<cGeniusFreeStudyPaymentLogic>();
    cSchool                          School(PaymentLogic, StubLogger, NullNotifier);
    std::shared_ptr<IPupil>          Pupil = cGeniusPupil::Create();

    const bool RetVal = School.AcceptNewPupil(Pupil);

    CHECK_TRUE((RetVal == false) && School.GetPupils().empty());
}

TEST(SchoolGroup, AcceptNewPupil_PassPupilThatAccepts_CallsNotifyOfNotifier)
{
    std::shared_ptr<ILogger>         StubLogger(new cFakeLogger);
    std::shared_ptr<INotifier>       MockNotifier(new cFakeNotifier);
    std::shared_ptr<IPaySchoolLogic> PaymentLogic = std::make_shared<cGeniusFreeStudyPaymentLogic>();
    cSchool                          School(PaymentLogic, StubLogger, MockNotifier);
    std::shared_ptr<IPupil>          Pupil = cGeniusPupil::Create();

    School.AcceptNewPupil(Pupil);

    CHECK_TRUE(MockNotifier->GetLastNotifyMsg() == eNotifyMsg::PUPIL_ACCEPTED);
}
