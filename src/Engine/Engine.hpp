#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <Engine/EventHandler.hpp>
#include <Engine/TimeManager.hpp>
#include <Application/App.hpp>
#include <Engine/Observer.hpp>
#include <Engine/GUIConsole.hpp>
#include <Engine/GUILogger.hpp>

class Engine : public KeyBoardObserver, public EventObserver
{
    public:
        Engine();
        virtual ~Engine();

        void run();
        void update(sf::Time deltaTime);
        void render();

        virtual void notify(sf::Keyboard::Key key, bool pressed);
        virtual void notify(sf::Event m_event);

        void addEventListerner();

    private:
        sf::RenderWindow m_window;
        sf::Time m_timePerFrame;

        TimeManager m_timer;
        EventHandler* m_eventHandler;

        GUIConsole m_console;
        App m_app;
        
};

#endif
