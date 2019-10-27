#include "NPCVehicle.h"

#include <Math.h>

using namespace std;



NPCVehicle::NPCVehicle(float x, float y, float z, std::list<Vector3> PresetPath)
{

	Path ThisPath;
	//ThisPath.SetPath(NPC1Path);

	Position.x = x;
	Position.y = y;
	Position.z = z;

	TargetPos = ThisPath.GetWaypoint();
}


NPCVehicle::~NPCVehicle()
{
}

void NPCVehicle::Update()
{
	if (Arrive())
	{
		ThisPath.SetNextPoint();

		TargetPos = ThisPath.GetWaypoint();
	}
	Seek();

	cout << "X: " << Position.x << "      Z: " << Position.z << endl;
}

void NPCVehicle::Seek()
{
	DesiredVec.x = (TargetPos.x - Position.x);
	DesiredVec.y = (TargetPos.y - Position.y);
	DesiredVec.z = (TargetPos.z - Position.z);

	DesiredVec = VNormalise(DesiredVec);

	DesiredVec.x *= 0.1;
	DesiredVec.y *= 0.1;
	DesiredVec.z *= 0.1;

	Position.x = Position.x + DesiredVec.x;
	Position.y = Position.y + DesiredVec.y;
	Position.z = Position.z + DesiredVec.z;
}

Vector3 NPCVehicle::VNormalise(Vector3 vec)
{
	float len = Length(vec);
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;

	return vec;
}

bool NPCVehicle::Arrive()
{
	Vector3 ToTarget;

	ToTarget.x = (TargetPos.x - Position.x);
	ToTarget.y = (TargetPos.y - Position.y);
	ToTarget.z = (TargetPos.z - Position.z);

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

float NPCVehicle::Length(Vector3 vec)
{
	return sqrt(vec.x * vec.x +
		vec.y * vec.y +
		vec.z * vec.z);
}