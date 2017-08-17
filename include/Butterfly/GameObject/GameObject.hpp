#pragma once

#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\System\Vector2.hpp>

namespace Butterfly
{
	namespace GameObject
	{
		class GameObject
			: public sf::Drawable
		{
		public:
			GameObject();
			virtual ~GameObject();
			virtual void Update(float deltaTime);
		protected:
			sf::Sprite sprite;
			sf::RectangleShape hitbox;
			bool isHitboxVisible;
			sf::Vector2f speed;
			float maxSpeed;
		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		};
	}
}