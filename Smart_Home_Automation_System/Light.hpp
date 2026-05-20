#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Device.hpp"

class Light:public Device
{
    private:
        int brightness_;
    public:
        Light(const std::string& name , int brightness  = 100);
        ~Light()override;

        void setBrightness(int level);
        int getBrightness()const;

        void turnOn()override;
        void turnOff()override;
};


#endif