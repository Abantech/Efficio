#pragma once

#include <map>
#include "Data.h"
#include "DataType.h"
#include "Event.h"

#include <memory>
#include <vector>

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
		Frame(int ID = 0);
		~Frame();

		std::map<Efficio::Data::DataType, std::vector<std::shared_ptr<Efficio::Data::Data>>> GetData();

		// TODO make this templated
		std::vector<std::shared_ptr<Efficio::Data::Data>> GetDataOfType(Efficio::Data::DataType dataType);

		void AddData(std::vector<std::shared_ptr<Efficio::Data::Data>> data);

		void AddFrame(Efficio::Frame frame);

		std::vector<std::shared_ptr<Efficio::Events::Event>> GetEvents();

		void AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr);

		const int ID;

	private:
		std::map<Efficio::Data::DataType, std::vector<std::shared_ptr<Efficio::Data::Data>>> dataCollection;
		std::vector<std::shared_ptr<Efficio::Events::Event>> events;
	};
}