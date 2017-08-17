#include "Butterfly\GameState\GameState.hpp"
#include "Butterfly\Game.hpp"

namespace Butterfly
{
	namespace GameState
	{
		GameState::GameState(Game & game)
			: game(game)
		{}

		GameState::~GameState()
		{}
	}
}
