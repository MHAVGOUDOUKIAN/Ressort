#ifndef RESOLVER_HPP
#define RESOLVER_HPP

#include <SFML/Graphics.hpp>
#include <Application/Masse.hpp>
#include <Application/Support.hpp>
#include <Engine/GUILogger.hpp>
#include <glm/glm.hpp>

class Resolver {
    public:
        static void resolve(Masse&, const Support&, sf::Time);
};

#endif