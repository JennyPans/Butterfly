#include "Butterfly\GameState\GameStateManager.hpp"
#include "Butterfly\GameState\GameState.hpp"

namespace Butterfly
{
	namespace GameState
	{
		GameStateManager::GameStateManager()
		{
		}

		GameStateManager::~GameStateManager()
		{
			PopStates();
		}

		void GameStateManager::PushState(std::unique_ptr<GameState> state)
		{
			states.push(std::move(state));
		}

		void GameStateManager::PopState()
		{
			if (!states.empty())
				states.pop();
		}

		void GameStateManager::PopStates()
		{
			while (!states.empty())
			{
				states.pop();
			}
		}
		GameState & GameStateManager::GetCurrentState()
		{
			return *states.top();
		}
	}
}