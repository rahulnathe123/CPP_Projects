#include "Device.hpp"
#include "HomeController.hpp"
#include<iostream>

Device::Device(const std::string& name)
    :name_(name),on_(false)
    {

    }

Device::~Device()
{

}

const std::string& Device::getName()const
{
    return name_;
}

bool Device::isOn()const
{
    return on_;
}

void Device::setController(const std::shared_ptr<HomeController>& controller)
{
    controller_ = controller;
}

