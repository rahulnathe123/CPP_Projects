#ifndef LOGGER_HPP
#define LOGGER_HPP

#include<string>
#include<fstream>

class Logger
{
    private:
        bool toFile_;
        std::ofstream ofs_;
    public:
        explicit Logger(const std::string& filename="");
        ~Logger();

        void log(const std::string& msg);
};

#endif