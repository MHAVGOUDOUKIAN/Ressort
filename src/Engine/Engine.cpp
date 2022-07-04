#include <Engine/Engine.hpp>

Engine::Engine(): m_window(sf::VideoMode(800,600), "Application SFML"), m_eventHandler(EventHandler::getEventHandler()),  m_console(), m_app()
{
    srand(time(0));
    GUILogger::attachGUIConsole(m_console);

    m_timePerFrame = sf::seconds(1.f/120.f);
    m_window.setFramerateLimit(120); // Apparition de certains artefacts graphiques mais réduit l'utilisation du CPU
    m_window.setKeyRepeatEnabled(false);

    EventHandler::getEventHandler()->addKeyBoardObserver(this);
    EventHandler::getEventHandler()->addEventObserver(this);
}

void Engine::run()
{
    m_timer.add("Clock1");
    sf::Time timeSinceLastUpdate = m_timer.restart("Clock1");

    while (m_window.isOpen())
    {
        m_eventHandler->processEvents(m_window); // On détermine les actions relatives aux events à exécuter à la prochaine frame
        timeSinceLastUpdate += m_timer.restart("Clock1");
        while (timeSinceLastUpdate > m_timePerFrame)
        {
            m_eventHandler->processEvents(m_window); // On détermine les actions relatives aux events à exécuter à la prochaine frame
            timeSinceLastUpdate -= m_timePerFrame;
            update(m_timePerFrame);
        }
        render();
    }
}

void Engine::notify(sf::Keyboard::Key key, bool pressed) {
    if(key == sf::Keyboard::Escape) { m_window.close(); }
    else if(key == sf::Keyboard::Tab && pressed) { m_console.setHide(!m_console.isHide()); }
}

void Engine::notify(sf::Event m_event) {
    if(m_event.type == sf::Event::Closed) {
        m_window.close();   
    }   
    else if (m_event.type == sf::Event::Resized)
    {
        // on met à jour la vue, avec la nouvelle taille de la fenêtre
        sf::FloatRect visibleArea(0.f, 0.f, m_event.size.width, m_event.size.height);
        m_window.setView(sf::View(visibleArea));
    }
}

void Engine::update(sf::Time deltaTime)
{
    m_app.update(deltaTime);
    m_console.update();
}

void Engine::render(void)
{
    m_window.clear(sf::Color::White);
    m_window.draw(m_app);
    m_window.draw(m_console);
    m_window.display();
}

Engine::~Engine(){}