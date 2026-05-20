#include "Logger.hpp"
#include <iostream>
#include <chrono>
#include <ctime>


Logger::Logger(const std::string& filename)
            :toFile_(!filename.empty())
{
    if(toFile_)
    {
        ofs_.open(filename , std::ios::app);
    }
}

Logger::~Logger()
{
    if(ofs_.is_open())
        ofs_.close();
}

void Logger::log(const std::string& msg)
{
    //timestamp
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::string out = "[LOG]" + std::string(std::ctime(&t));

    //remove trailing newline from ctime
    if(!out.empty() && out.back() == '\n')
        out.pop_back();
    
    out += " - " + msg;

    if(toFile_ && ofs_.is_open())
    {
        ofs_<<out<<std::endl;
    }
    else{
        std::cout<<out<<std::endl;
    }
}
