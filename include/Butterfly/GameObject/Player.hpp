#pragma once
#include "GameObject.hpp"

namespace Butterfly
{
	namespace GameObject
	{
		class Player :
			public GameObject
		{
		public:
			Player();
			virtual ~Player();
			void Input();
		};
	}
}