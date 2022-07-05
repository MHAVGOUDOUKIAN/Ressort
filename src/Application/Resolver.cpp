#include <Application/Resolver.hpp>
#include <Application/utils.hpp>

void Resolver::resolveSpring(Spring* s){ // Suppose qu'il y a un ressort entre la masse et le support
    float angle = findAngle(s->m_m2->m_centerPos,s->m_m1->m_centerPos)+ M_PI/2;

    glm::vec2 m_m1_center =  glm::vec2(s->m_m1->m_centerPos.x, s->m_m1->m_centerPos.y);
    glm::vec2 m_m2_center =  glm::vec2(s->m_m2->m_centerPos.x, s->m_m2->m_centerPos.y);

    float long_spring = glm::length(glm::vec2(m_m1_center-m_m2_center)); // Longueur enter masse et support (en pxl, pas en m !)
    float x=long_spring-s->m_lo;

    s->m_m1->m_acc.x += -((s->m_k*x*glm::sin(angle))/s->m_m1->m_mass);
    s->m_m1->m_acc.y += -((s->m_k*x*glm::cos(angle))/s->m_m1->m_mass);

    angle = findAngle(s->m_m1->m_centerPos,s->m_m2->m_centerPos)+ M_PI/2;

    s->m_m2->m_acc.x += -((s->m_k*x*glm::sin(angle))/s->m_m2->m_mass);
    s->m_m2->m_acc.y += -((s->m_k*x*glm::cos(angle))/s->m_m2->m_mass);
}

void Resolver::resolveGravity(Masse* m) {
    float f=1.25f;
    float g=9.8f*10.f;
    m->m_acc.y += - m->m_vit.y * f ;//+g;
    m->m_acc.x += - m->m_vit.x * f;
}