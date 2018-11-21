#include <GameObject.h>
#include <Debug.h>

GameObject::GameObject() { }

GameObject::GameObject(const AnimatedSprite& as, const AnimatedSprite& as1, const AnimatedSprite& as2, const AnimatedSprite& as3, const AnimatedSprite& as4):
	m_animated_square(as),
	m_animated_poly(as1),
	m_animated_circle(as2),
	m_animated_capsule(as3),
	m_animated_ray(as4)
{ }

GameObject::~GameObject() { }