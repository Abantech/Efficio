//Room for expansion depending on utility, current below is generic

//ensure that only one humanosteology.cpp is included
#pragma once

//include statements
#include <string>
//#include <array>

//ensure proper devices are selected, with the correct wrapper included
//#include [wrapper selection] 
//#include <Vector3.h>
//#include <iostream> to print to console for testing, display
//for a massive multimaps approach, #include <multimap>


#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

using namespace std;

//namespace efficio
namespace Efficio {

	//namespace body
	namespace Body { //or EfficioBody
					 //joints as nodes

					 //must be generic

					 //will receive input data thru wrapper or directly from input system

					 //joint groups

		class joint
		{
		public:
		protected : string Side;
		protected : float x;
		protected : float y;
		protected :  float z;
		protected : float h;
		protected :  float d;
		protected : float s;

			//optional float/string h = optional float/string health;
			//optional float/string d = optional float/string density;
			//optional float/string s = optional float/string size;
		};

		class mandible : private joint
		{
		public:
			mandible(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~mandible();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}

		};

		class spine : private joint
		{
		public:
			spine(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~spine();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class pivot : private joint //neck pivot joint
		{
		public:
			pivot(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~pivot();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class vertebra : private joint
		{
		public:
			vertebra(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~vertebra();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class eachvertebra : private joint //each vertebra
		{
		public:
			eachvertebra(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~eachvertebra();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class ballsocket : private joint //ball and socket, the shoulder joint
		{
		public:
			ballsocket(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~ballsocket();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class hinge : private joint //hinge joint, the elbow
		{
		public:
			hinge(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~hinge();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class saddle : private joint //saddle joint, the wrists
		{
		public:
			saddle(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~saddle();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class knuckle : private joint
		{
		public:
			knuckle(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~knuckle();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class eachknuckle : private joint
		{
		public:
			eachknuckle(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~eachknuckle();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class hip : private joint
		{
		public:
			hip(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~hip();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class knee : private joint
		{
		public:
			knee(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~knee();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class ankle : private joint
		{
		public:
			ankle(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~ankle();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class toeknuckles : private joint
		{
		public:
			toeknuckles(string bodyside, float xcoordinate, float ycoordinate, float zcoordinate)
			{
				Side = bodyside;
				x = xcoordinate;
				y = ycoordinate;
				z = zcoordinate;
			}
			~toeknuckles();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		//each might have attributes: biophysics: (health, resistance, hardness / density)  coordinates, size
		
		class bone
		{
		public:
			string Side;
			float x;
			float y;
			float z;
			float h;
			float d;
			float s;
		};

		class skull : private bone
		{
		public:
			skull(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~skull();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}

		};

		class mandibleb : private bone
		{
		public:
			mandibleb(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~mandibleb();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class sternum : private bone
		{
		public:
			sternum(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~sternum();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class humerus : private bone
		{
		public:
			humerus(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~humerus();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class forearm : private bone
		{
		public:
			forearm(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~forearm();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class vertebrab : private bone
		{
		public:
			vertebrab(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~vertebrab();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class rib : private bone
		{
		public:
			rib(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~rib();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class metacarpal : private bone
		{
		public:
			metacarpal(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~metacarpal();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class phalange : private bone
		{
		public:
			phalange(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~phalange();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class pelvicgirdle : private bone
		{
		public:
			pelvicgirdle(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~pelvicgirdle();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class femur : private bone
		{
		public:
			femur(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~femur();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class lowerleg : private bone
		{
		public:
			lowerleg(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~lowerleg();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class tarsal : private bone
		{
		public:
			tarsal(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~tarsal();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class metatarsal : private bone
		{
		public:
			metatarsal(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~metatarsal();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};

		class phalangeb : private bone
		{
		public:
			phalangeb(string bodyside, float centerxcoordinate, float centerycoordinate, float centerzcoordinate)
			{
				Side = bodyside;
				x = centerxcoordinate;
				y = centerycoordinate;
				z = centerzcoordinate;
			}
			~phalangeb();
			void SetHealth(float health)
			{
				h = health;
			}
			void SetDensity(float density)
			{
				d = density;
			}
			void SetSize(float size)
			{
				s = size;
			}
		};
		
		//Engine may populate with Vector3s similarly to abstracting-joint-data approach

	}
}