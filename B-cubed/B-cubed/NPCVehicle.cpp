#include "NPCVehicle.h"

#include <Math.h>

using namespace std;


NPCVehicle::NPCVehicle(float x, float y, float z, std::list<vector3df> PresetPath)
{
	Path ThisPath;
	ThisPath.SetPath(PresetPath);

	Position.X = x;
	Position.Y = y;
	Position.Z = z;

	TargetPos = ThisPath.GetWaypoint();
}


NPCVehicle::~NPCVehicle()
{
}

void NPCVehicle::Update()
{
	if (Arrive())
	{
		//ThisPath.SetNextPoint();

		//TargetPos = ThisPath.GetWaypoint();
	}
	Seek();
}

void NPCVehicle::Seek()
{
	DesiredVec.X = (TargetPos.X - Position.X);
	DesiredVec.Y = (TargetPos.Y - Position.Y);
	DesiredVec.Z = (TargetPos.Z - Position.Z);

	DesiredVec = VNormalise(DesiredVec);

	DesiredVec.X *= 0.1;
	DesiredVec.Y *= 0.1;
	DesiredVec.Z *= 0.1;

	Position.X = Position.X + DesiredVec.X;
	Position.Y = Position.Y + DesiredVec.Y;
	Position.Z = Position.Z + DesiredVec.Z;
}

vector3df NPCVehicle::VNormalise(vector3df vec)
{
	float len = Length(vec);
	vec.X /= len;
	vec.Y /= len;
	vec.Z /= len;

	return vec;
}

bool NPCVehicle::Arrive()
{
	vector3df ToTarget;

	ToTarget.X = (TargetPos.X - Position.X);
	ToTarget.Y = (TargetPos.Y - Position.Y);
	ToTarget.Z = (TargetPos.Z - Position.Z);

	double dist = Length(ToTarget);
	if (dist <= 0.3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float NPCVehicle::Length(vector3df vec)
{
	return sqrt(vec.X * vec.X +
		vec.Y * vec.Y +
		vec.Z * vec.Z);
}