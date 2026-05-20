#include "Fan.hpp"
#include "HomeController.hpp"

Fan::Fan(const std::string& name,int speed)
    :Device(name),speed_(speed)
{

}

Fan::~Fan()
{

}

void Fan::setSpeed(int speed)
{
    speed_ = speed;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + " speed set to " + std::to_string(speed));
}

int Fan::getSpeed()const
{
    return speed_;
}

void Fan::turnOn()
{
    on_ = true;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + " turned ON");
}

void Fan::turnOff()
{
    on_ = false;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + "turned OFF");
}

