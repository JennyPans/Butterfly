#include "Butterfly\Game.hpp"
#include "Butterfly\GameState\GameStateTest.hpp"

namespace Butterfly
{
	Game::Game()
		: stateManager()
		, assetManager()
		, window(sf::VideoMode(256, 240), "Butterfly")
		, event()
		, time()
		, isRunning(false)
	{
		window.setVerticalSyncEnabled(true);
		stateManager.PushState(std::make_unique<GameState::GameStateTest>(*this));
	}

	Game::~Game()
	{
		window.close();
	}

	void Game::Run()
	{
		isRunning = true;
		while (isRunning)
		{
			HandleEvents();
			Update(time.restart().asSeconds());
			Draw();
		}
	}

	void Game::Exit()
	{
		isRunning = false;
	}

	GameState::GameStateManager & Game::GetStateManager()
	{
		return stateManager;
	}

	Asset::AssetManager & Game::GetAssetManager()
	{
		return assetManager;
	}

	void Game::HandleEvents()
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Exit();
				break;

			default:
				break;
			}
		}
	}

	void Game::Update(float deltaTime)
	{
		stateManager.GetCurrentState().Update(deltaTime);
	}

	void Game::Draw()
	{
		window.draw(stateManager.GetCurrentState());
		window.display();
	}
}