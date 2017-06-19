#include "HandData.h"

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			HandData::HandData() {}
			HandData::HandData(std::vector<Efficio::Models::Body::Hand> hands) : Hands(hands) {}
			HandData::~HandData() {}
		}
	}
}