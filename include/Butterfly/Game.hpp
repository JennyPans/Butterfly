#pragma once

#include "GameState\GameStateManager.hpp"
#include "Butterfly\Asset\AssetManager.hpp"

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>
#include <SFML\System\Time.hpp>

namespace Butterfly
{
	class Game
	{
	public:
		Game();
		virtual ~Game();
		void Run();
		void Exit();
		GameState::GameStateManager& GetStateManager();
		Asset::AssetManager& GetAssetManager();
	private:
		void HandleEvents();
		void Update(float deltaTime);
		void Draw();
		GameState::GameStateManager stateManager;
		Asset::AssetManager assetManager;
		sf::RenderWindow window;
		sf::Event event;
		sf::Clock time;
		bool isRunning;
	};
}