#pragma once

#include "Frame.h"
#include "Event.h"
#include "EfficioHand.h"
#include "EfficioFinger.h"
#include <vector>
#include <memory>

using namespace std;
using namespace Efficio;

/*
Note I created EfficioBody.h as numerous declared fingers are required to be members of EfficioBody.

Put classes into Body
*/

//I belive Greg prefers frame-by-frame

//So we want to create all these objects in the Engine from the device. It sounds like Greg wants them in a vector first. Then, he wants them to be manipulated through shared pointers.
//

namespace Efficio
{
	class DLLEXPORT Body //namespace Efficio needs Body tag member.
	{
	public:
		
		EfficioFinger Finger(Efficio::Body::FingerType);

		vector<shared_ptr<Efficio::EfficioFinger>> Finger;
				
		vector<shared_ptr<Efficio::EfficioHand>> Hands;
		vector<shared_ptr<Efficio::Events::Event>> events;
		int ID;
		
		Body(int ID)
		{
			
		}
		//what is the purpose of ID? Can the EfficioFrame constructor instead receive Hands?
		~Body();
		//	 { delete vector<shared_ptr<Efficio::EfficioHand>> Hands; }
		vector<shared_ptr<Efficio::Events::Event>> GetEvents();
		void AddEvent(shared_ptr<Efficio::Events::Event> eventPtr);

		virtual ~Body()
		{
		}
	};
};