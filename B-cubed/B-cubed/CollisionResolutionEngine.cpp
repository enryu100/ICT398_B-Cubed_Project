#include "CollisionResolutionEngine.h"

#include "GameObject.h"
#include "iostream"

CollisionResolutionEngine::CollisionResolutionEngine()
{
	Gravity = irr::core::vector3df(0, 0.981, 0);
}

CollisionResolutionEngine::~CollisionResolutionEngine()
{
}


vector3df CollisionResolutionEngine::CalculateLinearMomentum(GameObject *ThisObject)
{
	vector3df Momentum = ThisObject->getMass()*ThisObject->getLineVel();
	return Momentum;
}

vector3df CollisionResolutionEngine::CalculateRotationalMomentum(GameObject *ThisObject)
{
	vector3df Momentum = ThisObject->getMass()*ThisObject->getRotVel();
	return Momentum;
}

float CollisionResolutionEngine::Length(vector3df vec)
{
	return sqrt(vec.X * vec.X +
		vec.Y * vec.Y +
		vec.Z * vec.Z);
}

vector3df CollisionResolutionEngine::VectorNormalize(vector3df Given_Vector)
{

	float len = Length(Given_Vector);
	Given_Vector.X /= len;
	Given_Vector.Y /= len;
	Given_Vector.Z /= len;

	return Given_Vector;

}

/*vector3df CollisionResolutionEngine::ComputeImpulse(GameObject *ThisObject, vector3df Collision_Point, float CollisionForce)
{
	vector3df TempImpulse = Normalize(ThisObject, Collision_Point);

	return TempImpulse;
}*/

void CollisionResolutionEngine::ResolveCollisions(GameObject *ThisObject, irr::core::vector3df Collision_Point, float CollisionForce)
{
	//vector3df LinearMomentum = CalculateLinearMomentum(ThisObject);
	//vector3df RotationalMomentum = CalculateRotationalMomentum(ThisObject);

	ThisObject->setForce(Collision_Point);

	//-- IMPULSE IS CALUCLATED FROM THE OBJECT COLLISION DETECTION
	//Impulse = ComputeImpulse(ThisObject, Collision_Point, CollisionForce);

	vector3df ObjPosition = ThisObject->getPosVector();
	vector3df AppliedVector;

	AppliedVector.X = ObjPosition.X - Collision_Point.X;
	AppliedVector.Y = ObjPosition.Y - Collision_Point.Y;
	AppliedVector.Z = ObjPosition.Z - Collision_Point.Z;

	VectorNormalize(AppliedVector); //The force of the impact

	//Must calculate new vector, based off, Initial Vector, * Applied Vector

	AppliedVector.X = AppliedVector.X * CollisionForce;
	AppliedVector.Y = AppliedVector.Y * CollisionForce;
	AppliedVector.Z = AppliedVector.Z * CollisionForce;

	//=======================================
	//Calculate new velocity based off applied and current velocity
	vector3df NewVelocity; //Vector holding the new velocity of the object
	vector3df InitVelocity; //Initial velocity before collision
	InitVelocity.X = ThisObject->getVelX();
	InitVelocity.Y = ThisObject->getVelY();
	InitVelocity.Z = ThisObject->getVelZ();

	NewVelocity.X = AppliedVector.X + InitVelocity.X;
	NewVelocity.Y = AppliedVector.Y + InitVelocity.Y;
	NewVelocity.Z = AppliedVector.Z + InitVelocity.Z;

	//=======================================
	//Use the New Velocity to determine the position of the object
	vector3df NewPosition;

	NewPosition.X = ObjPosition.X + NewVelocity.X;
	NewPosition.Y = ObjPosition.Y + NewVelocity.Y;
	NewPosition.Z = ObjPosition.Z + NewVelocity.Z;


	//Impulse is the change in velocity * mass
				//Delta V
	Impulse = (InitVelocity+NewVelocity) * ThisObject->getMass();

	//std::cout << NewPosition.Y << std::endl;

	ThisObject->setPosVec(NewPosition);
}

void CollisionResolutionEngine::ResolveUpdate(GameObject *ThisObject, float CollisionForce)
{
	vector3df LinearMomentum = CalculateLinearMomentum(ThisObject);
	//vector3df RotationalMomentum = CalculateRotationalMomentum(ThisObject);

	//-- IMPULSE IS CALUCLATED FROM THE OBJECT COLLISION DETECTION
	//Impulse = ComputeImpulse(ThisObject, Collision_Point, CollisionForce);

	vector3df ObjPosition = ThisObject->getPosVector();
	vector3df AppliedVector;

	vector3df Collision_Point = ThisObject->getForce();

	AppliedVector.X = ObjPosition.X - Collision_Point.X;
	AppliedVector.Y = ObjPosition.Y - Collision_Point.Y;
	AppliedVector.Z = ObjPosition.Z - Collision_Point.Z;

	VectorNormalize(AppliedVector); //The force of the impact

	//Must calculate new vector, based off, Initial Vector, * Applied Vector

	AppliedVector.X = AppliedVector.X * CollisionForce;
	AppliedVector.Y = AppliedVector.Y * CollisionForce;
	AppliedVector.Z = AppliedVector.Z * CollisionForce;

	//=======================================
	//Calculate new velocity based off applied and current velocity
	vector3df NewVelocity; //Vector holding the new velocity of the object
	vector3df InitVelocity; //Initial velocity before collision
	InitVelocity.X = ThisObject->getVelX();
	InitVelocity.Y = ThisObject->getVelY();
	InitVelocity.Z = ThisObject->getVelZ();

	NewVelocity.X = AppliedVector.X + InitVelocity.X;
	NewVelocity.Y = AppliedVector.Y + InitVelocity.Y;
	NewVelocity.Z = AppliedVector.Z + InitVelocity.Z;

	//=======================================
	//Use the New Velocity to determine the position of the object
	vector3df NewPosition;

	NewPosition.X = ObjPosition.X + NewVelocity.X;
	NewPosition.Y = ObjPosition.Y + NewVelocity.Y;
	NewPosition.Z = ObjPosition.Z + NewVelocity.Z;


	//Impulse is the change in velocity * mass
				//Delta V
	Impulse = (InitVelocity + NewVelocity) * ThisObject->getMass();

	//std::cout << NewPosition.Y << std::endl;

	ThisObject->setPosVec(NewPosition);
}


