#pragma once

#include <stdexcept>
#include <string>


namespace Butterfly
{
	namespace Asset
	{
		class AssetLoadException
			: public std::runtime_error
		{
		public:
			AssetLoadException(const std::string &message);
			virtual ~AssetLoadException();
		};
	}
}