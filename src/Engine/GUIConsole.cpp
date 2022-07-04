#include "GUIConsole.hpp"
#include <iostream>

GUIConsole::GUIConsole() : m_maxlines(10), m_hide(true){
    m_font.loadFromFile("src/assets/DS-TERM.ttf");
    
    m_text.setFont(m_font);
    m_text.setCharacterSize(14);
    m_text.setPosition(0,0);
    m_text.setFillColor(sf::Color::Black);

    m_GUIConsoleBackground.setFillColor(sf::Color(252,213,20,130));
    m_GUIConsoleBackground.setSize(sf::Vector2f(1080,145));
    m_GUIConsoleBackground.setPosition(0,0);
}

GUIConsole::~GUIConsole() {}

void GUIConsole::update() {
        int count=m_lines.size();
        std::string str="";
        std::string line="";

        str += m_lines[0];
        count--;

        while(count>0) {
            str += "\n" + m_lines[m_lines.size()-count];
            count--;
        }

        m_text.setString(str);
}

void GUIConsole::addLine(const std::string& msg) {
    if(m_lines.size() == m_maxlines) m_lines.pop_back();
    m_lines.push_front(msg);
}

void GUIConsole::setHide(bool hide) { m_hide = hide; }

bool GUIConsole::isHide() { return m_hide; }

void GUIConsole::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(!m_hide) {
        target.draw(m_GUIConsoleBackground);
        target.draw(m_text);
    }
}