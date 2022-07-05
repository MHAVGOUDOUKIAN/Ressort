#ifndef RESOLVER_HPP
#define RESOLVER_HPP

#include <SFML/Graphics.hpp>
#include <Application/Masse.hpp>
#include <Application/Support.hpp>
#include <Engine/GUILogger.hpp>
#include <glm/glm.hpp>
#include <Application/Spring.hpp>

class Resolver {
    public:
        static void resolveSpring(Spring*);
        static void resolveGravity(Masse*);
};

#endif