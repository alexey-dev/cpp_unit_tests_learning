//
//  main.cpp
//  TestMockStub
//
//  Created by Alex Usachov on 9/23/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#include <iostream>
#include "SchoolEntities.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
//    cSchool SchoolFree(std::shared_ptr<IPaySchoolLogic>(new cFreePaymentLogic));
    cSchool SchoolFree(std::make_shared<cFreePaymentLogic>());
    SchoolFree.AcceptNewPupil(cGeniusPupil::Create());
    SchoolFree.AcceptNewPupil(cCleverPupil::Create());
    SchoolFree.AcceptNewPupil(cForgetfulPupil::Create());
    
    cSchool SchoolForGenius(std::make_shared<cGeniusFreeStudyPaymentLogic>());
    SchoolForGenius.AcceptNewPupil(cGeniusPupil::Create());
    SchoolForGenius.AcceptNewPupil(cCleverPupil::Create());
    SchoolForGenius.AcceptNewPupil(cForgetfulPupil::Create());
    
    return 0;
}
