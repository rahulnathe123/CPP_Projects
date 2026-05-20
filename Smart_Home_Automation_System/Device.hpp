#ifndef _DEVICE_HPP
#define _DEVICE_HPP

#include<string>
#include<memory>

class HomeController; //forward declaration

class Device
{
    protected:
        std::string name_;
        bool on_;
        std::weak_ptr<HomeController> controller_;
    public:
        Device(const std::string& name);
        virtual ~Device();

        const std::string& getName()const;
        bool isOn()const;

        //controller is stored as weak_ptr to avoid cycle
        void setController(const std::shared_ptr<HomeController>& controller);

        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
};


#endif