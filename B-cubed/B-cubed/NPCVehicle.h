#pragma once

#include "Path.h"

#include "irrlicht.h"
#include <iostream>
using namespace irr;
using namespace core;

using namespace std;

class NPCVehicle
{
public:
	NPCVehicle(float x, float y, float z, std::list<vector3df> PresetPath);
	~NPCVehicle();

	void Update();

	vector3df Position;
	vector3df TargetPos;

	void Seek();
	vector3df VNormalise(vector3df vec);
	float Length(vector3df vec);
	bool Arrive();

private:
	vector3df DesiredVec;
	Path ThisPath;
};

