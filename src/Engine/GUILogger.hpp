#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <Engine/GUIConsole.hpp>
#include <iostream>
#include <fstream>

class GUILogger {
    public:
        static void log(const std::string& msg);
        static void attachGUIConsole(GUIConsole& console);

    private:
        static GUIConsole* _console;
};

#endif