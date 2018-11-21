#ifndef PLAYER_H
#define PLAYER_H

#include <GameObject.h>
#include <Input.h>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>

class Player : public GameObject
{
private:
	enum shape{SQUARE, POLY, CIRCLE, CAPSULE, RAY };
	
public:
	Player();
	~Player();
	Player(const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&, const AnimatedSprite&);
	AnimatedSprite& getAnimatedSprite();
	void handleInput(Input);
	void update();

	int shape = SQUARE;
};

#endif // !PLAYER_H
