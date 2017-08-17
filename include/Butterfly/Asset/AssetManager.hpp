#pragma once

#include "Butterfly\Asset\AssetGetException.hpp"
#include "Butterfly\Asset\AssetLoadException.hpp"

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Audio\SoundBuffer.hpp>
#include <SFML\Audio\Music.hpp>

#include <map>
#include <string>
#include <memory>
#include <iostream>

namespace Butterfly
{
	namespace Asset
	{
		class AssetManager
		{
		public:
			AssetManager();
			virtual ~AssetManager();
			template<typename T>
			const T& Get(const std::string &name) const;
			template<typename T>
			void Load(const std::string &name, const std::string &fileName);
			void Unload();
		private:
			std::map<std::string, std::unique_ptr<sf::Texture>> textures;
			std::map<std::string, std::unique_ptr<sf::Font>> fonts;
			std::map<std::string, std::unique_ptr<sf::SoundBuffer>> sounds;
			std::map<std::string, std::unique_ptr<sf::Music>> musics;
		};

		template<>
		inline const sf::Texture & AssetManager::Get<sf::Texture>(const std::string & name) const
		{
			if (textures.find(name) == textures.end())
				throw AssetGetException("The texture " + name + " was not found");

			return *textures.find(name)->second;
		}

		template<>
		inline const sf::Font & AssetManager::Get<sf::Font>(const std::string & name) const
		{
			if (fonts.find(name) == fonts.end())
				throw AssetGetException("The font " + name + " was not found");

			return *fonts.find(name)->second;
		}

		template<>
		inline const sf::SoundBuffer & AssetManager::Get<sf::SoundBuffer>(const std::string & name) const
		{
			if (sounds.find(name) == sounds.end())
				throw AssetGetException("The sound " + name + " was not found");

			return *sounds.find(name)->second;
		}

		template<>
		inline const sf::Music & AssetManager::Get<sf::Music>(const std::string & name) const
		{
			if (musics.find(name) == musics.end())
				throw AssetGetException("The music " + name + " was not found");

			return *musics.find(name)->second;
		}

		template<>
		inline void AssetManager::Load<sf::Texture>(const std::string & name, const std::string & fileName)
		{
			textures.insert(std::make_pair(name, std::make_unique<sf::Texture>()));
			if (!textures.find(name)->second->loadFromFile("Assets\\Textures\\" + fileName))
			{
				textures.erase(name);
				throw AssetLoadException("The file \"" + fileName + "\" was not found.");
			}
		}

		template<>
		inline void AssetManager::Load<sf::Font>(const std::string & name, const std::string & fileName)
		{
			fonts.insert(std::make_pair(name, std::make_unique<sf::Font>()));
			if (!fonts.find(name)->second->loadFromFile("Assets\\Fonts\\" + fileName))
			{
				fonts.erase(name);
				throw AssetLoadException("The file \"" + fileName + "\" was not found.");
			}
		}

		template<>
		inline void AssetManager::Load<sf::SoundBuffer>(const std::string & name, const std::string & fileName)
		{
			sounds.insert(std::make_pair(name, std::make_unique<sf::SoundBuffer>()));
			if (!fonts.find(name)->second->loadFromFile("Assets\\Sound\\" + fileName))
			{
				sounds.erase(name);
				throw AssetLoadException("The file \"" + fileName + "\" was not found.");
			}
		}

		template<>
		inline void AssetManager::Load<sf::Music>(const std::string & name, const std::string & fileName)
		{
			musics.insert(std::make_pair(name, std::make_unique<sf::Music>()));
			if (!musics.find(name)->second->openFromFile("Assets\\Fonts\\" + fileName))
			{
				musics.erase(name);
				throw AssetLoadException("The file \"" + fileName + "\" was not found.");
			}
		}
	}
}