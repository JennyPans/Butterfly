#include "Butterfly\GameObject\Player.hpp"
#include "SFML\Window\Keyboard.hpp"

namespace Butterfly
{
	namespace GameObject
	{
		Player::Player()
			: GameObject()
		{
			maxSpeed = 150.f;
			hitbox.setSize(sf::Vector2f(64.f, 64.f));
			hitbox.setFillColor(sf::Color(230, 65, 10));
			isHitboxVisible = true;
		}

		Player::~Player()
		{}

		void Player::Input()
		{
			speed.x = 0.0f;
			speed.y = 0.0f;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				speed.x = -maxSpeed;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				speed.x = maxSpeed;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				speed.y = -maxSpeed;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				speed.y = maxSpeed;
			}
		}
	}
}