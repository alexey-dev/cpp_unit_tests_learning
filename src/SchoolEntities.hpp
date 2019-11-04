//
//  SchoolEntities.hpp
//  TestMockStub
//
//  Created by Alex Usachov on 9/23/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#ifndef SchoolEntities_hpp
#define SchoolEntities_hpp

#include <stdio.h>
#include <memory>
#include <vector>
#include "Logger.hpp"
#include "Notifier.hpp"

enum class eSchoolMark : uint8_t
{
    Five = 5,
    Four = 4,
    Three = 3,
    Two = 2,
    One = 1
};

class IPupil
{
public:
    virtual ~IPupil() = default;
    IPupil(const int _cash);

    virtual eSchoolMark PassExam() = 0;

    virtual bool PayForStudy(const int _sumOfPay);

    virtual bool PayFromGeniusConditions(const int _sumOfPay);
    
    int GetCash() const;
    
protected:
    int mCash;
};

class IPaySchoolLogic
{
public:
    virtual ~IPaySchoolLogic() = default;
    
    virtual bool MakeStartPayment(std::shared_ptr<IPupil>) const = 0;
    
    int GetPaymentValue() const;
    
};

class cSchool
{
public:
    cSchool(std::shared_ptr<IPaySchoolLogic>, std::shared_ptr<ILogger>, std::shared_ptr<INotifier>);
    
    bool AcceptNewPupil(std::shared_ptr<IPupil>);
    
    void PassExams();
    
    const std::vector<std::shared_ptr<IPupil>> & GetPupils() const;
    
private:
    std::shared_ptr<IPaySchoolLogic>     mPayLogic;
    std::shared_ptr<ILogger>             mLogger;
    std::shared_ptr<INotifier>           mNotifier;
    std::vector<std::shared_ptr<IPupil>> mPupils;
};

class cGeniusFreeStudyPaymentLogic : public IPaySchoolLogic
{
public:
    virtual bool MakeStartPayment(std::shared_ptr<IPupil>) const override;
};

class cFreePaymentLogic : public IPaySchoolLogic
{
public:
    virtual bool MakeStartPayment(std::shared_ptr<IPupil>) const override;
};

class cGeniusPupil : public IPupil
{
public:
    static std::shared_ptr<IPupil> Create(const int _cash = 100);

    cGeniusPupil(const int _cash);
    virtual eSchoolMark PassExam() override;
    virtual bool PayFromGeniusConditions(const int _sumOfPay) override;
};

class cCleverPupil : public IPupil
{
public:
    static std::shared_ptr<IPupil> Create(const int _cash = 100);
    
    cCleverPupil(const int _cash);
    virtual eSchoolMark PassExam() override;
};

class cForgetfulPupil : public IPupil
{
public:
    static std::shared_ptr<IPupil> Create(const int _cash = 100);
    
    cForgetfulPupil(const int _cash);
    virtual eSchoolMark PassExam() override;
};



#endif
