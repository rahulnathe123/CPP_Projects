#ifndef FAN_HPP
#define FAN_HPP

#include "Device.hpp"

class Fan:public Device
{
    private:
        int speed_;
    public:
        Fan(const std::string& name , int speed = 1);
        ~Fan()override;

        void setSpeed(int speed);
        int getSpeed()const;

        void turnOn()override;
        void turnOff()override;
};

#endif