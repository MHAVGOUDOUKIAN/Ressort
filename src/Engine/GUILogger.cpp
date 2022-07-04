#include <Engine/GUILogger.hpp>

GUIConsole* GUILogger::_console = nullptr;

void GUILogger::log(const std::string& msg) {
    _console->addLine(msg);
    std::cout << msg << std::endl;
}

void GUILogger::attachGUIConsole(GUIConsole& console) {
    _console = &console;
}