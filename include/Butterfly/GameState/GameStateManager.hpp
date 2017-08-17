#pragma once

#include <stack>
#include <memory>

namespace Butterfly
{
	namespace GameState
	{
		class GameState;

		class GameStateManager
		{
		public:
			GameStateManager();
			virtual ~GameStateManager();
			void PushState(std::unique_ptr<GameState> state);
			void PopState();
			void PopStates();
			GameState& GetCurrentState();
		private:
			std::stack<std::unique_ptr<GameState>> states;
		};
	}
}
