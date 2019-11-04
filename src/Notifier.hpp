//
//  Notifier.hpp
//  Main.o
//
//  Created by Alex Usachov on 11/4/19.
//

#ifndef Notifier_hpp
#define Notifier_hpp

#include <stdint.h>

enum class eNotifyMsg : uint8_t
{
    PUPIL_ACCEPTED = 1,
    EMPTY          = 0
};

class INotifier
{
    public:
        INotifier();
    
        virtual ~INotifier() = default;
    
        virtual void Notify(const eNotifyMsg & _notifyMsg) = 0;
    
        const eNotifyMsg & GetLastNotifyMsg() const;
    
    protected:
        eNotifyMsg mLastMsg;
};

class cConditionalNotifier : public INotifier
{
    public:
        virtual void Notify(const eNotifyMsg & _notifyMsg) override;
};


#endif /* Notifier_hpp */
