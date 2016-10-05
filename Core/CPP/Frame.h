#pragma once

#include "HandData.h"
#include <map>
#include "Datum.h"
#include "DatumType.h"

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
		Efficio::HandData HandData;

		// TODO make this templated
		Efficio::Data::Datum* GetData(Efficio::Data::DatumType dataType);

		void AddData(Efficio::Data::Datum* datum);

	private:
		std::map<Efficio::Data::DatumType, Efficio::Data::Datum*> dataCollection;
	};
}