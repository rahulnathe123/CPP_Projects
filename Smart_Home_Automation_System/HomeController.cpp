#include "HomeController.hpp"
#include "Device.hpp"
#include "Logger.hpp"

#include<algorithm>
#include<iostream>

HomeController::HomeController()
    :logger_(std::make_unique<Logger>(""))
{

}

HomeController::HomeController(const std::string& logFile)
    : logger_(std::make_unique<Logger>(logFile))
{

}

HomeController::~HomeController()
{
    //logger_ will destruct automatically
}

void HomeController::addDevice(const std::shared_ptr<Device>& device)
{
    //set weak_ptr to this controller
    device->setController(shared_from_this());
    devices_.push_back(device);
    log("Device added : "+device->getName());
}

void HomeController::removeDevice(const std::string& name)
{
    devices_.erase(std::remove_if(devices_.begin(),devices_.end(),
        [&](const std::shared_ptr<Device>&d)
       {
            if(d->getName() == name)
            {
                log("Device removed : "+name);
                return true;
            }
            return false;
        }),devices_.end()
    );
}

std::shared_ptr<Device> HomeController::findDevice(const std::string& name)
{
    for(auto& d : devices_)
    {
        if(d->getName() == name)
            return d;
    }
    return nullptr;
}
void HomeController::turnOn(const std::string& name)
{
    if(auto d = findDevice(name))
    {
        d->turnOn();
    }
    else
    {
        log("turnOn : Device not found : "+ name);
    }
}

void HomeController::turnOff(const std::string& name)
{
    if(auto d = findDevice(name))
    {
        d->turnOff();
    }
    else
    {
        log("turnOn:Device not found : "+name);
    }
}

void HomeController::listDevices()const{
    std::cout<<"Devices("<<devices_.size()<<"):\n";
    for(const auto& d:devices_)
    {
        std::cout<<" - "<<d->getName()<<(d->isOn() ? " [ON]" : " [OFF]")<<"\n";
    }
}

void HomeController::log(const std::string& message)
{
    if(logger_)
        logger_->log(message);
}

