#include "Butterfly\Asset\AssetLoadException.hpp"

namespace Butterfly
{
	namespace Asset
	{
		AssetLoadException::AssetLoadException(const std::string &message)
			: std::runtime_error(message)
		{}

		AssetLoadException::~AssetLoadException()
		{}
	}
}