#ifndef AC_HPP
#define AC_HPP

#include "Device.hpp"

class AC:public Device
{
    private:
        int temperature_;
    public:
        AC(const std::string& name , int temperature=24);
        ~AC() override;

        void setTemperature(int t);
        int getTemperature()const;

        void turnOn() override;
        void turnOff() override;
};
#endif