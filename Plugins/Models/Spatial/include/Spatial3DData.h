#include "Data.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			class Spatial3DData : public Efficio::Data
			{
			public:
				Spatial3DData();
				~Spatial3DData();

				virtual std::string GetDataType() override;
			private:

			};
		}
	}
}