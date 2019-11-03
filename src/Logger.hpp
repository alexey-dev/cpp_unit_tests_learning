//
//  Logger.hpp
//  TestMockStub
//
//  Created by Alex Usachov on 11/3/19.
//  Copyright © 2019 Alex Usachov. All rights reserved.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <stdio.h>
#include <string>

class ILogger
{
    public:
        virtual ~ILogger() = default;
        virtual void Message(const std::string & _msg) = 0;
};

class cFileLogger : public ILogger
{
    public:
        virtual ~cFileLogger() = default;
        virtual void Message(const std::string & _msg) override;
};


#endif
