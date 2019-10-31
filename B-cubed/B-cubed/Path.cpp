#include "Path.h"

using namespace std;

Path::Path()
{

}

Path::Path(std::list<Vector3> SetWayPoints)
{
	waypoints = SetWayPoints;
	CurrentPoint = waypoints.begin();
}

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


	/*
	if (++CurrentPoint == waypoints.end())
	{
		CurrentPoint = waypoints.begin();
	}
	*/

}
