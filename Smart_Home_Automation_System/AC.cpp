#include "AC.hpp"
#include "HomeController.hpp"

AC::AC(const std::string& name,int temperature)
    :Device(name),temperature_(temperature)
{

}

AC::~AC()
{

}

void AC::setTemperature(int t)
{
    this->temperature_ = t;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + " temperature set to " + std::to_string(t));

}

int AC::getTemperature()const
{
    return temperature_;
}

void AC::turnOn()
{
    on_ = true;
    if(auto ctrl = controller_.lock())
    {
        ctrl->log(name_ + " turned ON");
    }
}

void AC::turnOff()
{
    on_ = false;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + " turned OFF");
}