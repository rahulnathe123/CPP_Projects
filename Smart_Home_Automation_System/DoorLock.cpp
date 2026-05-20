#include "DoorLock.hpp"
#include "HomeController.hpp"

DoorLock::DoorLock(const std::string& name)
    :Device(name),locked_(true)
{

}

DoorLock::~DoorLock()
{

}

void DoorLock::lock()
{
    locked_ = true;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + " locked");
}

void DoorLock::unlock()
{
    locked_ = false;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + " unlocked");
}

void DoorLock::turnOn()
{
    unlock();
}

void DoorLock::turnOff()
{
    lock();
}
