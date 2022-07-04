#ifndef GUICONSOLE_HPP
#define GUICONSOLE_HPP

#include <SFML/Graphics.hpp>
#include <deque>

class GUIConsole : public sf::Drawable{    
    friend class Engine;
    friend class GUILogger;

    private:
        GUIConsole();
        ~GUIConsole();
        void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void addLine(const std::string& msg);
        void setHide(bool hide);
        bool isHide();

    private: 
        sf::RectangleShape m_GUIConsoleBackground;
        sf::Text m_text;
        sf::Font m_font;
        std::deque<std::string> m_lines;
        int m_maxlines;
        bool m_hide;
};

#endif