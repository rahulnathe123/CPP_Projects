#include "Light.hpp"
#include "HomeController.hpp"

#include<iostream>

Light::Light(const std::string& name , int brightness)
    :Device(name),brightness_(brightness)
{

}

Light::~Light()
{

}

void Light::setBrightness(int level)
{
    brightness_ = level;
    if(auto ctrl = controller_.lock())
    {
        ctrl->log(name_ + " brightness set to " + std::to_string(level));
    }
}

int Light::getBrightness() const
{
    return brightness_;
}

void Light::turnOn()
{
    on_ = true;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ + " turned ON");
}

void Light::turnOff()
{
    on_ = false;
    if(auto ctrl = controller_.lock())
        ctrl->log(name_ +" turned Off");
}