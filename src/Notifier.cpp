//
//  Notifier.cpp
//  Main.o
//
//  Created by Alex Usachov on 11/4/19.
//

#include "Notifier.hpp"

INotifier::INotifier() :
    mLastMsg(eNotifyMsg::EMPTY)
{}

const eNotifyMsg &
INotifier::GetLastNotifyMsg() const
{
    return mLastMsg;
}

void
cConditionalNotifier::Notify(const eNotifyMsg & _notifyMsg)
{
    //TODO: finish later
}
