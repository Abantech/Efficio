#pragma once

#include "Frame.h"
#include "Event.h"
#include "Hand.h"
#include "Finger.h"
#include <vector>
#include <memory>

using namespace std;
using namespace Efficio;

/*
Note I created EfficioBody.h as numerous declared fingers are required to be members of EfficioBody.
*/

namespace Efficio
{
	class DLLEXPORT Body //namespace Efficio needs Body tag member.
	{
	public:
		
		vector<shared_ptr<Efficio::Body::Finger>> Finger;
		vector<shared_ptr<Efficio::Body::Hand>> Hands;
		vector<shared_ptr<Efficio::Events::Event>> events;
		int ID;
		Body(int ID)
		{
			
		}
		//what is the purpose of ID? Can the EfficioFrame constructor instead receive Hands?
		~Body();

		vector<std::shared_ptr<Efficio::Events::Event>> GetEvents();
		void AddEvent(std::shared_ptr<Efficio::Events::Event> eventPtr);

		virtual ~Body()
		{
		}
	};
};

