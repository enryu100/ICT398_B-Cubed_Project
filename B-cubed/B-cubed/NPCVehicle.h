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
	NPCVehicle(float x, float y, float z, Path *thisPath);
	~NPCVehicle();

	void Update();

	Vector3 Position;
	Vector3 TargetPos;

	void Seek();
	Vector3 VNormalise(Vector3 vec);
	float Length(Vector3 vec);
	bool Arrive();

private:
	Vector3 DesiredVec;
	Path ThisPath;
};

