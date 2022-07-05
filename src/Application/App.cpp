#include <Application/App.hpp>
#include <Engine/GUILogger.hpp>
#include <glm/glm.hpp>

App::App() { 
    EventHandler::getEventHandler()->addMouseObserver(this); 
    EventHandler::getEventHandler()->addKeyBoardObserver(this);
    m_ms.push_back(new Masse(50,50,5,5,100));
    m_ms.push_back(new Masse(100,50,5,5,100));
    m_ms.push_back(new Masse(100,100,5,5,100));
    m_ms.push_back(new Masse(50,100,5,5,100));
    
    m_ss.push_back(new Spring(m_ms[0],m_ms[1],10000, 10));
    m_ss.push_back(new Spring(m_ms[1],m_ms[2],10000, 10));
    m_ss.push_back(new Spring(m_ms[2],m_ms[3],10000, 10));
    m_ss.push_back(new Spring(m_ms[3],m_ms[0],10000, 10));
    m_ss.push_back(new Spring(m_ms[0],m_ms[2],10000, 10));
    m_ss.push_back(new Spring(m_ms[3],m_ms[1],10000, 10));
}

App::~App() {}

void App::update(sf::Time deltaTime) {
    for(int i=0; i<m_ss.size(); i++) Resolver::resolveSpring(m_ss[i]);
    for(int i=0; i<m_ms.size(); i++) Resolver::resolveGravity(m_ms[i]);
    for(int i=0; i<m_ms.size(); i++) m_ms[i]->update(deltaTime);
    for(int i=0; i<m_ss.size(); i++) m_ss[i]->update(deltaTime);
}

void App::notify(sf::Mouse::Button mouse, sf::Vector2i& pos, bool clicked) {
    if(mouse == sf::Mouse::Button::Left && clicked) {
        m_ms[0]->m_pos.x = float(pos.x);
        m_ms[0]->m_pos.y = float(pos.y);
        m_ms[0]->m_vit.x = 0;
        m_ms[0]->m_vit.y = 0;
        m_ms[0]->m_centerPos.x= m_ms[0]->m_pos.x + m_ms[0]->m_shape.getSize().x/2;
        m_ms[0]->m_centerPos.y= m_ms[0]->m_pos.y + m_ms[0]->m_shape.getSize().y/2;
        m_ms[0]->m_acc.x = 0;
        m_ms[0]->m_acc.y = 0;
    }
}

void App::notify(sf::Keyboard::Key key, bool pressed) {}

void App::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(int i=0; i<m_ss.size(); i++) target.draw(*m_ss[i]);
    for(int i=0; i<m_ms.size(); i++) target.draw(*m_ms[i]);    
}