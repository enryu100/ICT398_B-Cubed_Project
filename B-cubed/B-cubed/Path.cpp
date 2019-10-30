#include "Path.h"

using namespace std;

Path::Path()
{

	//Vector3 NPC1P1;
	//NPC1P1.x = -100;
	//NPC1P1.y = 0;
	//NPC1P1.z = -60;

	//SetPath(NPC1P1);

	//waypoints = { NPC1P1 };
	//CurrentPoint = waypoints.begin();
}

Path::Path(std::list<Vector3> SetWayPoints)
{
	waypoints = SetWayPoints;
	CurrentPoint = waypoints.begin();
}

/*void Path::SetPath(Vector3 P1)
{

	NPC1P2.x = -100;
	NPC1P2.y = 0;
	NPC1P2.z = -350;

	NPC1P3.x = 150;
	NPC1P3.y = 0;
	NPC1P3.z = -350;

	NPC1P4.x = 150;
	NPC1P4.y = 0;
	NPC1P4.z = -60;

	waypoints = { P1, NPC1P2, NPC1P3, NPC1P4 };
	CurrentPoint = waypoints.begin();

}*/

void Path::SetPath(std::list<Vector3> SetWayPoints)
{
	waypoints = SetWayPoints;
	CurrentPoint = waypoints.begin();
	iterator = 0;
}

Vector3 Path::GetWaypoint()
{
	CurrentPoint = waypoints.begin();

	std::advance(CurrentPoint, iterator);


	return *CurrentPoint;
}

void Path::SetNextPoint()
{
	assert(waypoints.size() > 0);

	if (++iterator > (waypoints.size() - 1))
	{
		iterator = 0;
	}else{
		iterator+1;
	}


	/*if (++CurrentPoint == waypoints.end())
	{
		CurrentPoint = waypoints.begin();
	}*/

}
