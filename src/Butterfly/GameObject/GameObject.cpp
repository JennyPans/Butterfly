#include "Butterfly\GameObject\GameObject.hpp"
#include "SFML\Graphics\RenderTarget.hpp"

namespace Butterfly
{
	namespace GameObject
	{
		GameObject::GameObject()
			: sprite()
			, hitbox()
			, isHitboxVisible(false)
		{}

		GameObject::~GameObject()
		{}

		void GameObject::Update(float deltaTime)
		{
			if (speed.x != 0.0f || speed.y != 0.0f)
			{
				sprite.move(speed.x * deltaTime, 0.0f);
				hitbox.setPosition(sprite.getPosition());
				// Check collisions
				sprite.move(0.0f, speed.y * deltaTime);
				hitbox.setPosition(sprite.getPosition());
				// Check collisions
			}
		}

		void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
		{
			target.draw(sprite);
			if (isHitboxVisible)
				target.draw(hitbox);
		}
	}
}