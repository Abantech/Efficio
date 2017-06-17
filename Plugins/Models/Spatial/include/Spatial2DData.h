#include "Data.h"

namespace Efficio
{
	namespace Models
	{
		namespace Spatial
		{
			class Spatial2DData : public Efficio::Data
			{
			public:
				Spatial2DData();
				~Spatial2DData();

				virtual std::string GetDataType() override;
			private:

			};
		}
	}
}