#include "HandData.h"

namespace Efficio
{
	namespace Data
	{
		namespace Body
		{
			HandData::HandData() {}
			HandData::HandData(std::vector<Efficio::Models::Body::Hand> hands) : Hands(hands) {}
			HandData::~HandData() {}
		}
	}
}