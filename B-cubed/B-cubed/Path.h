#pragma once

#include <list>
#include <cassert>

using namespace std;

/**
* @struct Vector3
* @brief A struct that holds 3 floats
* @param x - holds a x co-odinate as a float value
* @param y - holds a y co-odinate as a float value
* @param z - holds a z co-odinate as a float value
* @Author Ben Townroe
* @return Does not return a value
*/
struct Vector3
{
	float x;
	float y;
	float z;
};

class Path
{
public:

	/**
	* @function Path
	* @brief Acts as the default constructor for the Path
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	Path();

	/**
	* @function ~Path
	* @brief Acts as the default deconstructor for the Path
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	~Path() { } ;
	
	/**
	* @function Path(SetWatPoints)
	* @brief Acts as a constructor that automatically sets the path with a given list of Vector3's
	* @param SetWayPoints: A list of Vector3's that act as the waypoints an NPC traverses between
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	Path(std::list<Vector3> SetWayPoints);

	/**
	* @function GetWayPoint
	* @brief Returns the next Vector3 in the list 
	* @Author Ben Townroe
	* @return Returns the Vector3 stored within a list
	*/
	Vector3 GetWaypoint();

	/**
	* @function SetNextPoint
	* @brief Increments the iterator by 1, allowing for the list to be cycled through
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void SetNextPoint();

	//void SetPath(Vector3 P1/*std::list<Vector3> SetWayPoints*/);

	/**
	* @function SetPath
	* @brief Sets the Path of the NPC, allowing for custom paths to be made
	* @param SetWayPoints: A list of Vector3's that act as the waypoints an NPC traverses between
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void SetPath(std::list<Vector3> SetWayPoints);

private:
	/**
	* @var waypoints
	* @brief A list of vector3's that act as waypoints for an NPC to traverse
	*/
	std::list<Vector3> waypoints;

	/**
	* @var CurrentPoint
	* @brief A list iterator that points to an element in the list
	*/
	std::list<Vector3>::iterator CurrentPoint;
	//Vector3 /*NPC1P1,*/ NPC1P2, NPC1P3, NPC1P4;

	/**
	* @var iterator
	* @brief A custom iterator that behaves similar to a list iterator, but was developed to circumvent issues
	*/
	int iterator;

};

