#pragma once

#include <SFML\Graphics\Drawable.hpp>

namespace Butterfly
{
	class Game;

	namespace GameState
	{
		class GameState
			: public sf::Drawable
		{
		public:
			GameState(Game& game);
			virtual ~GameState();
			virtual void Update(float deltaTime) = 0;
		protected:
			virtual void LoadAssets() = 0;
			virtual void UnloadAssets() = 0;
			virtual void Initialize() = 0;
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
			Game &game;
		};
	}
}