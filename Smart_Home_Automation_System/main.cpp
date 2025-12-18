#include "HomeController.hpp"
#include "AC.hpp"
#include "Light.hpp"
#include "Fan.hpp"
#include "DoorLock.hpp"


#include<memory>
#include<iostream>

int main(void)
{
    const char* line = "-----------------------------------------\n";
    std::cout<<"----Entered : Smart Home Automation Demo----"<<std::endl;

    auto controller = std::make_shared<HomeController>();

    auto livingLight  = std::make_shared<Light>("Living Room Light");
    auto bedFan   = std::make_shared<Fan>("Bedroom Fan");
    auto mainAC  = std::make_shared<AC>("mainAC");
    auto frontDoor = std::make_shared<DoorLock>("front Door");

    controller->addDevice(livingLight);
    controller->addDevice(bedFan);
    controller->addDevice(mainAC);
    controller->addDevice(frontDoor);
    std::cout<<std::endl<<line;

    controller->listDevices();
    std::cout<<std::endl<<line;
    
    controller->turnOn("Living Room Light");
    controller->turnOn("Bedroom Fan");
    controller->turnOn("mainAC");
    std::cout<<std::endl<<line;
    
    //Device specific controls
    livingLight->setBrightness(80);
    bedFan->setSpeed(3);
    mainAC->setTemperature(22);
    std::cout<<std::endl<<line;
    
    controller->turnOff("Bedroom Fan");
    controller->turnOn("front Door");
    controller->turnOff("front Door");
    std::cout<<std::endl<<line;
    
    controller->listDevices();
    std::cout<<std::endl<<line;
    
    //Remove Device
    controller->removeDevice("mainAC");
    std::cout<<std::endl;
    
    controller->listDevices();
    std::cout<<std::endl;
    
    std::cout<<"----Leaving : Smart Home Automation Demo----"<<std::endl;
    return 0;
}
