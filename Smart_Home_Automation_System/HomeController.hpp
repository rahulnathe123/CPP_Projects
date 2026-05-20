#ifndef _HOMECONTROLLER_HPP
#define _HOMECONTROLLER_HPP

#include<vector>
#include<memory>
#include<string>

class Device;   //forword declaration
class Logger;   //forword declaration

class HomeController:public std::enable_shared_from_this<HomeController>
{
    private:
        std::vector<std::shared_ptr<Device>> devices_;
        std::unique_ptr<Logger> logger_;
    public:
        HomeController();
        explicit HomeController(const std::string& logFile);
        ~HomeController();

        //manage Devices
        void addDevice(const std::shared_ptr<Device>& device);
        void removeDevice(const std::string& name);
        std::shared_ptr<Device> findDevice(const std::string& name);

        void turnOn(const std::string& name);
        void turnOff(const std::string& name);

        void listDevices()const;

        //loggig API used by devices
        void log(const std::string& message);
};


#endif