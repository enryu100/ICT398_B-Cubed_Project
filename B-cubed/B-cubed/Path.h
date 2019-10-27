#pragma once

#include <list>
#include <cassert>

using namespace std;

struct Vector3
{
	float x;
	float y;
	float z;
};

class Path
{
public:
	Path();
	//Path(std::list<Vector3> SetWayPoints);
	~Path() { } ;
 
	Vector3 GetWaypoint();
	void SetNextPoint();

	void SetPath(Vector3 P1/*std::list<Vector3> SetWayPoints*/);
	void SetPath(std::list<Vector3> SetWayPoints);

private:
	std::list<Vector3> waypoints;
	std::list<Vector3>::iterator CurrentPoint;
	Vector3 /*NPC1P1,*/ NPC1P2, NPC1P3, NPC1P4;

};

