#include "Butterfly\Asset\AssetGetException.hpp"

namespace Butterfly
{
	namespace Asset
	{
		AssetGetException::AssetGetException(const std::string & message)
			: std::runtime_error(message)
		{}

		AssetGetException::~AssetGetException()
		{}
	}
}