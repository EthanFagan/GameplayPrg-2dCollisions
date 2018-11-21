#include <iostream>
#include <SFML/Graphics.hpp>
#define TINYC2_IMPL
#include <tinyc2.h>
#include <AnimatedSprite.h>
#include <GameObject.h>
#include <Player.h>
#include <NPC.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	int shapeSelect = 0;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a NPC's sprites to display
	sf::Texture npc_texture;
	if (!npc_texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Load a mouse texture to display
	sf::Texture player_texture;
	if (!player_texture.loadFromFile("assets\\player.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup NPC's Default Animated Sprite
	AnimatedSprite npc_animated_square(npc_texture);
	npc_animated_square.addFrame(sf::IntRect(3, 3, 84, 84));
	npc_animated_square.addFrame(sf::IntRect(88, 3, 84, 84));
	npc_animated_square.addFrame(sf::IntRect(173, 3, 84, 84));
	npc_animated_square.addFrame(sf::IntRect(258, 3, 84, 84));
	npc_animated_square.addFrame(sf::IntRect(343, 3, 84, 84));
	npc_animated_square.addFrame(sf::IntRect(428, 3, 84, 84));

	// Setup NPC's Poly Sprite
	AnimatedSprite npc_poly_animation(npc_texture);
	npc_poly_animation.addFrame(sf::IntRect(3, 88, 84, 84));
	npc_poly_animation.addFrame(sf::IntRect(88, 88, 84, 84));
	npc_poly_animation.addFrame(sf::IntRect(173, 88, 84, 84));
	npc_poly_animation.addFrame(sf::IntRect(258, 88, 84, 84));
	npc_poly_animation.addFrame(sf::IntRect(343, 88, 84, 84));
	npc_poly_animation.addFrame(sf::IntRect(428, 88, 84, 84));

	// Setup NPC's Circle Sprite
	AnimatedSprite npc_circle_animation(npc_texture);
	npc_circle_animation.addFrame(sf::IntRect(3, 173, 84, 84));
	npc_circle_animation.addFrame(sf::IntRect(88, 173, 84, 84));
	npc_circle_animation.addFrame(sf::IntRect(173, 173, 84, 84));
	npc_circle_animation.addFrame(sf::IntRect(258, 173, 84, 84));
	npc_circle_animation.addFrame(sf::IntRect(343, 173, 84, 84));
	npc_circle_animation.addFrame(sf::IntRect(428, 173, 84, 84));

	// Setup NPC's Capsule Sprite
	AnimatedSprite npc_capsule_animation(npc_texture);
	npc_capsule_animation.addFrame(sf::IntRect(3, 258, 84, 84));
	npc_capsule_animation.addFrame(sf::IntRect(88, 258, 84, 84));
	npc_capsule_animation.addFrame(sf::IntRect(173, 258, 84, 84));
	npc_capsule_animation.addFrame(sf::IntRect(258, 258, 84, 84));
	npc_capsule_animation.addFrame(sf::IntRect(343, 258, 84, 84));
	npc_capsule_animation.addFrame(sf::IntRect(428, 258, 84, 84));

	// Setup NPC's Ray Sprite
	AnimatedSprite npc_ray_animation(npc_texture);
	npc_ray_animation.addFrame(sf::IntRect(3, 343, 84, 84));
	npc_ray_animation.addFrame(sf::IntRect(88, 343, 84, 84));
	npc_ray_animation.addFrame(sf::IntRect(173, 343, 84, 84));
	npc_ray_animation.addFrame(sf::IntRect(258, 343, 84, 84));
	npc_ray_animation.addFrame(sf::IntRect(343, 343, 84, 84));
	npc_ray_animation.addFrame(sf::IntRect(428, 343, 84, 84));

	//-------------------------------------------------------------------------------------------

	// Setup Players Default Animated Sprite
	AnimatedSprite player_animated_square(npc_texture);
	player_animated_square.addFrame(sf::IntRect(3, 3, 84, 84));
	player_animated_square.addFrame(sf::IntRect(88, 3, 84, 84));
	player_animated_square.addFrame(sf::IntRect(173, 3, 84, 84));
	player_animated_square.addFrame(sf::IntRect(258, 3, 84, 84));
	player_animated_square.addFrame(sf::IntRect(343, 3, 84, 84));
	player_animated_square.addFrame(sf::IntRect(428, 3, 84, 84));

	// Setup Players Poly sprite
	AnimatedSprite player_poly_animation(npc_texture);
	player_poly_animation.addFrame(sf::IntRect(3, 88, 84, 84));
	player_poly_animation.addFrame(sf::IntRect(88, 88, 84, 84));
	player_poly_animation.addFrame(sf::IntRect(173, 88, 84, 84));
	player_poly_animation.addFrame(sf::IntRect(258, 88, 84, 84));
	player_poly_animation.addFrame(sf::IntRect(343, 88, 84, 84));
	player_poly_animation.addFrame(sf::IntRect(428, 88, 84, 84));

	// Setup Players Circle sprite
	AnimatedSprite player_circle_animation(npc_texture);
	player_circle_animation.addFrame(sf::IntRect(3, 173, 84, 84));
	player_circle_animation.addFrame(sf::IntRect(88, 173, 84, 84));
	player_circle_animation.addFrame(sf::IntRect(173, 173, 84, 84));
	player_circle_animation.addFrame(sf::IntRect(258, 173, 84, 84));
	player_circle_animation.addFrame(sf::IntRect(343, 173, 84, 84));
	player_circle_animation.addFrame(sf::IntRect(428, 173, 84, 84));

	// Setup Players Capsule sprite
	AnimatedSprite player_capsule_animation(npc_texture);
	player_capsule_animation.addFrame(sf::IntRect(3, 258, 84, 84));
	player_capsule_animation.addFrame(sf::IntRect(88, 258, 84, 84));
	player_capsule_animation.addFrame(sf::IntRect(173, 258, 84, 84));
	player_capsule_animation.addFrame(sf::IntRect(258, 258, 84, 84));
	player_capsule_animation.addFrame(sf::IntRect(343, 258, 84, 84));
	player_capsule_animation.addFrame(sf::IntRect(428, 258, 84, 84));

	// Setup Players ray sprite
	AnimatedSprite player_ray_animation(npc_texture);
	player_ray_animation.addFrame(sf::IntRect(3, 343, 84, 84));
	player_ray_animation.addFrame(sf::IntRect(88, 343, 84, 84));
	player_ray_animation.addFrame(sf::IntRect(173, 343, 84, 84));
	player_ray_animation.addFrame(sf::IntRect(258, 343, 84, 84));
	player_ray_animation.addFrame(sf::IntRect(343, 343, 84, 84));
	player_ray_animation.addFrame(sf::IntRect(428, 343, 84, 84));



	
	// Setup the NPC
	npc_animated_square.setPosition(sf::Vector2f(600, 250));
	npc_poly_animation.setPosition(sf::Vector2f(600, 250));
	npc_circle_animation.setPosition(sf::Vector2f(600, 250));
	npc_capsule_animation.setPosition(sf::Vector2f(600, 250));
	npc_ray_animation.setPosition(sf::Vector2f(600, 250));

	NPC &npc = NPC(npc_animated_square,npc_poly_animation,npc_circle_animation,npc_capsule_animation,npc_ray_animation);
	
	// Setup the Player
	Player &player = Player(player_animated_square,player_poly_animation,player_circle_animation,player_capsule_animation,player_ray_animation);

	//Setup NPC AABB
	c2AABB aabb_npc;
	aabb_npc.min = c2V(npc.getAnimatedSprite().getPosition().x, npc.getAnimatedSprite().getPosition().y);
	aabb_npc.max = c2V(
		npc.getAnimatedSprite().getPosition().x +
		npc.getAnimatedSprite().getGlobalBounds().width, 
		npc.getAnimatedSprite().getPosition().y +
		npc.getAnimatedSprite().getGlobalBounds().height);

	//Setup Player AABB
	c2AABB aabb_player;
	aabb_player.min = c2V(player.getAnimatedSprite().getPosition().x, player.getAnimatedSprite().getPosition().y);
	aabb_player.max = c2V(player.getAnimatedSprite().getGlobalBounds().width / 6, player.getAnimatedSprite().getGlobalBounds().width / 6);

	//Setup Player Circle
	c2Circle circle_Player;
	circle_Player.p = c2V(player.getAnimatedSprite().getPosition().x  , player.getAnimatedSprite().getPosition().y );
	circle_Player.r = 44;

	//Setup NPC Circle
	c2Circle circle_Npc;
	circle_Npc.p = c2V(npc.getAnimatedSprite().getPosition().x , npc.getAnimatedSprite().getPosition().y);
	circle_Npc.r = 44;

	//Setup Player Capsule
	c2Capsule capsule_Player;
	capsule_Player.r = 14;
	capsule_Player.a = { player.getAnimatedSprite().getPosition().x + capsule_Player.r, player.getAnimatedSprite().getPosition().y +33 };
	capsule_Player.b = { player.getAnimatedSprite().getPosition().x + player.getAnimatedSprite().getGlobalBounds().width - capsule_Player.r, player.getAnimatedSprite().getPosition().y +33 };

	//Setup NPC Capsule
	c2Capsule capsule_Npc;
	capsule_Npc.r = 14;
	capsule_Npc.a = { npc.getAnimatedSprite().getPosition().x + capsule_Npc.r, npc.getAnimatedSprite().getPosition().y +33 };
	capsule_Npc.b = { npc.getAnimatedSprite().getPosition().x + npc.getAnimatedSprite().getGlobalBounds().width - capsule_Npc.r, npc.getAnimatedSprite().getPosition().y +33 };

	//Setup player polygon
	c2Poly polygon_player;
	polygon_player.count = 3;
	polygon_player.verts[0] = c2V(player.getAnimatedSprite().getPosition().x, player.getAnimatedSprite().getPosition().y);
	polygon_player.verts[1] = c2V(player.getAnimatedSprite().getPosition().x, player.getAnimatedSprite().getPosition().y + player.getAnimatedSprite().getGlobalBounds().height);
	polygon_player.verts[2] = c2V(player.getAnimatedSprite().getPosition().x + player.getAnimatedSprite().getGlobalBounds().width, player.getAnimatedSprite().getPosition().y + player.getAnimatedSprite().getGlobalBounds().height);

	//setup npc polygon
	c2Poly polygon_Npc;
	polygon_Npc.count = 3;
	polygon_Npc.verts[0] = c2V(npc.getAnimatedSprite().getPosition().x, npc.getAnimatedSprite().getPosition().y);
	polygon_Npc.verts[1] = c2V(npc.getAnimatedSprite().getPosition().x, npc.getAnimatedSprite().getPosition().y + npc.getAnimatedSprite().getGlobalBounds().height);
	polygon_Npc.verts[2] = c2V(npc.getAnimatedSprite().getPosition().x + npc.getAnimatedSprite().getGlobalBounds().width, npc.getAnimatedSprite().getPosition().y + npc.getAnimatedSprite().getGlobalBounds().height);

	//setup player ray
	c2Ray ray_Player;
	ray_Player.p = c2V(player.getAnimatedSprite().getPosition().x, player.getAnimatedSprite().getPosition().y + 38);
	ray_Player.t = 82;

	c2v tempVector = c2V(ray_Player.p.x + 82, ray_Player.p.y);

	ray_Player.d = c2V((tempVector.x - ray_Player.p.x)/82, (tempVector.y - ray_Player.p.y)/82);

	//setup npc ray
	c2Ray ray_Npc;
	ray_Npc.p = c2V(npc.getAnimatedSprite().getPosition().x, npc.getAnimatedSprite().getPosition().y + 38);
	ray_Npc.t = 82;

	c2v tempVector = c2V(ray_Npc.p.x + 82, ray_Npc.p.y);

	ray_Npc.d = c2V((tempVector.x - ray_Npc.p.x) / 82, (tempVector.y - npc.p.y) / 82);


	// Initialize Input
	Input input;

	// Collision result
	int result = 0;

	// Start the game loop
	while (window.isOpen())
	{
		// Move Sprite Follow Mouse
		player.getAnimatedSprite().setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));

		// Update NPC AABB set x and y
		aabb_npc.min = c2V(
			npc.getAnimatedSprite().getPosition().x,
			npc.getAnimatedSprite().getPosition().y
		);

		aabb_npc.max = c2V(
			npc.getAnimatedSprite().getPosition().x +
			npc.getAnimatedSprite().getGlobalBounds().width,
			npc.getAnimatedSprite().getPosition().y +
			npc.getAnimatedSprite().getGlobalBounds().height
		);

		// Update Player AABB
		aabb_player.min = c2V(
			player.getAnimatedSprite().getPosition().x,
			player.getAnimatedSprite().getPosition().y
		);
		aabb_player.max = c2V(
			player.getAnimatedSprite().getPosition().x +
			player.getAnimatedSprite().getGlobalBounds().width,
			player.getAnimatedSprite().getPosition().y +
			player.getAnimatedSprite().getGlobalBounds().height
		);
		circle_Player.p = c2V(player.getAnimatedSprite().getPosition().x , player.getAnimatedSprite().getPosition().y );


		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					input.setCurrent(Input::Action::SQUARE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					input.setCurrent(Input::Action::POLY);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
				{
					input.setCurrent(Input::Action::CIRCLE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
				{
					input.setCurrent(Input::Action::CAPSULE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
				{
					input.setCurrent(Input::Action::RAY);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if (shapeSelect == 0)
					{
						shapeSelect = 1;
					}
					else if (shapeSelect == 1)
					{
						shapeSelect = 0;
					}
				}
				break;
			}
		}

		// Handle input to Player
		if (shapeSelect == 0)
		{
			player.handleInput(input);
		}
		else
		{
			npc.handleInput(input);
		}
		

		// Update the Player
		player.update();

		// Update the Player
		npc.update();

		// Check for collisions
		if (player.shape == 0 && npc.shape == 0)
		{
			result = c2AABBtoAABB(aabb_player, aabb_npc);
			cout << ((result != 0) ? ("box to box collision") : "") << endl;
		}
		else if (player.shape == 2 && npc.shape == 0)
		{
			result = c2CircletoAABB(circle_Player, aabb_npc);
			cout << ((result != 0) ? ("circle to box collision") : "") << endl;
		}

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Draw the NPC's Current Animated Sprite
		window.draw(npc.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};