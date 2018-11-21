#ifndef NPC_H
#define NPC_H

#include <GameObject.h>
#include <Input.h>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>

class NPC : public GameObject
{
private:
	enum shape{ SQUARE, POLY, CIRCLE, CAPSULE, RAY };
	
public:
	NPC();
	~NPC();
	NPC(const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&);
	AnimatedSprite& getAnimatedSprite();
	void handleInput(Input);
	void update();

	int shape = SQUARE;
};

#endif // !NPC_H
