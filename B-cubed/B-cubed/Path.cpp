#include "Path.h"

using namespace std;

Path::Path()
{
	waypoints = { vector3df(-100, 0, -100), vector3df(0, 0, 0) , vector3df(-50, 0, -50) };

}

void Path::SetPath(std::list<vector3df> SetWayPoints)
{
	waypoints = SetWayPoints;
	//waypoints = { vector3df(-100, 0, -100), vector3df(0, 0, 0) , vector3df(-50, 0, -50) , vector3df(-50, 0, 50) , vector3df(-100, 0, -100) };
	CurrentPoint = waypoints.begin();
}

vector3df Path::GetWaypoint()
{
	vector3df Returnedpoint = *CurrentPoint;

	return Returnedpoint;
}

void Path::SetNextPoint()
{
	assert(waypoints.size() > 0);

	//if (++CurrentPoint == waypoints.end())
	//{
	//	CurrentPoint = waypoints.begin();
	//}

}
