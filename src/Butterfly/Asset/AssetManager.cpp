#include "Butterfly/Asset/AssetManager.hpp"

namespace Butterfly
{
	namespace Asset
	{
		AssetManager::AssetManager()
		{}

		AssetManager::~AssetManager()
		{}

		void AssetManager::Unload()
		{
			if(!textures.empty())
				textures.clear();

			if(!fonts.empty())
				fonts.clear();

			if(!sounds.empty())
				sounds.clear();

			if(!musics.empty())
				musics.clear();
		}
	}
}