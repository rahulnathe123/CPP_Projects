#ifndef DOORLOCK_HPP
#define DOORLOCK_HPP

#include "Device.hpp"

class DoorLock:public Device
{
    private:
        bool locked_;

    public:
        DoorLock(const std::string& name);
        ~DoorLock()override;

        void lock();
        void unlock();
        void turnOn()override;
        void turnOff()override;
};
#endif


