#pragma once

<<<<<<< HEAD
#include "HandData.h"
#include <map>
#include "Data.h"
#include "DataType.h"

=======
>>>>>>> origin/master
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Efficio
{
	extern class DLLEXPORT Frame
	{
	public:
		Frame();
		~Frame();
<<<<<<< HEAD
		Efficio::HandData HandData;

		// TODO make this templated
		Efficio::Data::Data* GetData(Efficio::Data::DataType dataType);

		void AddData(Efficio::Data::Data* data);

	private:
		std::map<Efficio::Data::DataType, Efficio::Data::Data*> dataCollection;
=======
>>>>>>> origin/master
	};
}