#pragma once

#include "Joint.h"
#include "BoneTypes.h"

#if _WINDLL
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT
#endif

namespace Efficio
{
	namespace Models
	{
		namespace Body
		{
			/// <summary>
			/// A segment between two joints
			/// </summary>
			extern class DLLEXPORT Bone
			{
			public:
				/// <summary>
				/// Initializes a new instance of the <see cref="Bone"/> class.
				/// </summary>
				/// <param name="proximalJoint">The proximal joint.</param>
				/// <param name="distalJoint">The distal joint.</param>
				Bone(Joint proximalJoint, Joint distalJoint);

				/// <summary>
				/// Finalizes an instance of the <see cref="Bone"/> class.
				/// </summary>
				~Bone();

				/// <summary>
				/// The proximal joint
				/// </summary>
				Joint ProximalJoint;

				/// <summary>
				/// The distal joint
				/// </summary>
				Joint DistalJoint;

				/// <summary>
				/// The bone type
				/// </summary>
				BoneType Type;

				/// <summary>
				/// Calculates length of the bone from joint to joint
				/// </summary>
				/// <returns>A float representing the length of the bone</returns>
				float Length();

				/// <summary>
				/// The width of the bone
				/// </summary>
				/// <returns></returns>
				float Width();

				// TODO change to quaternion
				int Rotation();

				// TODO figure out what this is. Leap uses it
				int Basis();

				/// <summary>
				/// Calculates the center of the bone
				/// </summary>
				/// <returns>A vector representing the center of the bone</returns>
				Vector3 Center();


				Vector3 Direction();

			};
		}
	}
}