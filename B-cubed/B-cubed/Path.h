#pragma once

#include <list>
#include <cassert>

#include "irrlicht.h"
//#include <iostream>
using namespace irr;
using namespace core;

using namespace std;

class Path
{
public:
	Path();
	//Path(std::list<vector3df> SetWayPoints);
	~Path() { } ;
 
	vector3df GetWaypoint();
	void SetNextPoint();
	void SetPath(std::list<vector3df> SetWayPoints);

private:
	std::list<vector3df> waypoints;
	std::list<vector3df>::iterator CurrentPoint;

};

