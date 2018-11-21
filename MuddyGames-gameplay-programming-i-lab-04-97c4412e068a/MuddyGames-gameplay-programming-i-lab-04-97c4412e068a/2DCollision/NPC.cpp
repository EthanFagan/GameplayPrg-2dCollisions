#include <iostream>
#include <NPC.h>
#include <Idle.h>
#include <Debug.h>

NPC::NPC() : GameObject()
{
	m_player_fsm.setCurrent(new Idle());
	m_player_fsm.setPrevious(new Idle());
}

NPC::NPC(const AnimatedSprite& s, const AnimatedSprite& s1, const AnimatedSprite& s2, const AnimatedSprite& s3, const AnimatedSprite& s4) : GameObject(s,s1,s2,s3,s4)
{
	m_player_fsm.setCurrent(new Idle());
	m_player_fsm.setPrevious(new Idle());
}

NPC::~NPC()
{
}

AnimatedSprite& NPC::getAnimatedSprite()
{
	if (shape == SQUARE)
	{
		int frame = m_animated_square.getCurrentFrame();
		m_animated_square.setTextureRect(m_animated_square.getFrame(frame));
		return m_animated_square;
	}
	else if (shape == POLY)
	{
		int frame = m_animated_poly.getCurrentFrame();
		m_animated_poly.setTextureRect(m_animated_poly.getFrame(frame));
		return m_animated_poly;
	}
	else if (shape == CIRCLE)
	{
		int frame = m_animated_circle.getCurrentFrame();
		m_animated_circle.setTextureRect(m_animated_circle.getFrame(frame));
		return m_animated_circle;
	}
	else if (shape == CAPSULE)
	{
		int frame = m_animated_capsule.getCurrentFrame();
		m_animated_capsule.setTextureRect(m_animated_capsule.getFrame(frame));
		return m_animated_capsule;
	}
	else if (shape == RAY)
	{
		int frame = m_animated_ray.getCurrentFrame();
		m_animated_ray.setTextureRect(m_animated_ray.getFrame(frame));
		return m_animated_ray;
	}
}

void NPC::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	shape = in.getCurrent();
}

void NPC::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_poly.update();
	m_animated_capsule.update();
	m_animated_circle.update();
	m_animated_ray.update();
	m_animated_square.update();
}