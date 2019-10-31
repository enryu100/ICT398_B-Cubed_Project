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
	/**
	* @function NPCVehicle
	* @brief Acts as the default constructor for the NPCVehicle
	* @param float x - is the NPC's starting x co-ordinate
	* @param float y - is the NPC's starting y co-ordinate
	* @param float z - is the NPC's starting z co-ordinate
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	NPCVehicle(float x, float y, float z, Path *thisPath);

	/**
	* @function ~NPCVehicle
	* @brief Acts as the default deconstructor for the NPCVehicle
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	~NPCVehicle();

	/**
	* @function Update
	* @brief Function conducts all necessary function calls to successfully update all necessary NPCVehicle data
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void Update();

	/**
	* @function Seek
	* @brief Determines where teh NPC has to move next to arrive at its target co-ordinates
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void Seek();

	/**
	* @function VNormalise
	* @brief Normalises the passed in vector
	* @param vec is the passed in vector of co-ordinates to be normalised
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	Vector3 VNormalise(Vector3 vec);

	/**
	* @function Length
	* @brief Determines and calculates the length of a vector
	* @param vec is a Vector3df holding a passed in vector to be determine its length
	* @Author Ben Townroe
	* @return Returns a vector3df holding the Momentum on the x, y, z planes
	*/
	float Length(Vector3 vec);

	/**
	* @function Arrive
	* @brief Determines whether the NPC Vehicle has arrived at the desired co-ordinates
	* @Author Ben Townroe
	* @return Returns whether the NPC has arrived at the co-ordinates or not
	*/
	bool Arrive();

	/**
	* @var Position
	* @brief Holds the vector for the Npc's current position
	*/
	Vector3 Position;

	/**
	* @var TargetPos
	* @brief Holds the vector the next list co-ordinate
	*/
	Vector3 TargetPos;

private:
	/**
	* @var DesiredVec
	* @brief Holds the vector for the desired co-ordinates
	*/
	Vector3 DesiredVec;

	/**
	* @var ThisPath
	* @brief Holds the list of co-ordinates for the NPC to follow
	*/
	Path ThisPath;
};

