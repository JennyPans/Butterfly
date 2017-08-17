#include "Butterfly\GameState\GameStateTest.hpp"
#include "Butterfly\Game.hpp"

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

#include <iostream>

namespace Butterfly
{
	namespace GameState
	{
		GameStateTest::GameStateTest(Game & game)
			: GameState(game)
		{
			LoadAssets();
			Initialize();
		}

		GameStateTest::~GameStateTest()
		{
			UnloadAssets();
		}

		void GameStateTest::LoadAssets()
		{
			game.GetAssetManager().Load<sf::Texture>("Background", "background.png");
		}

		void GameStateTest::UnloadAssets()
		{
			game.GetAssetManager().Unload();
		}

		void GameStateTest::Initialize()
		{
			std::cout << "GameState : GameStateTest" << std::endl;
			background.setTexture(game.GetAssetManager().Get<sf::Texture>("Background"));
		}

		void GameStateTest::Update(float deltaTime)
		{
			player.Input();
			player.Update(deltaTime);
		}

		void GameStateTest::draw(sf::RenderTarget & target, sf::RenderStates states) const
		{
			target.clear(sf::Color::Black);
			target.draw(background);
			target.draw(player);
		}
	}
}