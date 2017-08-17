#pragma once

#include <stdexcept>
#include <string>

namespace Butterfly
{
	namespace Asset
	{
		class AssetGetException
			: public std::runtime_error
		{
		public:
			AssetGetException(const std::string &message);
			virtual ~AssetGetException();
		};
	}
}