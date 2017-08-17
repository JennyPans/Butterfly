#pragma once

#include "Butterfly\GameState\GameState.hpp"
#include "Butterfly\GameObject\Player.hpp"

#include <SFML\Graphics\Sprite.hpp>

namespace Butterfly
{
	class Game;

	namespace GameState
	{
		class GameStateTest:
			public GameState
		{
		public:
			GameStateTest(Game &game);
			virtual ~GameStateTest();
			virtual void Update(float deltaTime);
		private:
			virtual void LoadAssets();
			virtual void UnloadAssets();
			virtual void Initialize();
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
			GameObject::Player player;
			sf::Sprite background;
		};
	}
}