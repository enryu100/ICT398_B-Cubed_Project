#pragma once

#include "GameObject.h"

#include "irrlicht.h"
#include <iostream>
using namespace irr;
using namespace core;

class CollisionResolutionEngine
{
private:
	irr::core::vector3df Gravity;
	
	vector3df CalculateLinearMomentum(GameObject *ThisObject);
	vector3df CalculateRotationalMomentum(GameObject *ThisObject);
	vector3df VectorNormalize(vector3df Given_Vector);

	float Length(vector3df vec);

	//vector3df ComputeImpulse(GameObject *ThisObject, vector3df Collision_Point, float CollisionForce);

	vector3df Impulse;
public:
	CollisionResolutionEngine();
	void ResolveCollisions(GameObject *ThisObject, irr::core::vector3df Collision_Point, float CollisionForce);

	~CollisionResolutionEngine();
};

