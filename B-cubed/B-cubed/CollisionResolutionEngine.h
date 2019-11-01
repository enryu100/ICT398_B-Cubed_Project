#pragma once

#include "GameObject.h"

#include "irrlicht.h"
#include <iostream>
using namespace irr;
using namespace core;

class CollisionResolutionEngine
{
private:
	/**
	* @var Gravity
	* @brief Holds the vector for gravity for calculations
	*/
	irr::core::vector3df Gravity;
	
	/**
	* \fn CalculateLinearMomentum
	* @brief Determines and calculates the linear momentum of the object
	* @param *ThisObject is a pointer to a GameObject passed in from the program
	* @author Ben Townroe
	* @return Returns a vector3df holding the Momentum on the x, y, z planes
	*/
	vector3df CalculateLinearMomentum(GameObject *ThisObject);

	/**
	* \fn CalculateRotationalMomentum
	* @brief Determines and calculates the rotational momentum of the object - incomplete
	* @param *ThisObject is a pointer to a GameObject passed in from the program
	* @author Ben Townroe
	* @return Returns a vector3df holding the Momentum on the x, y, z planes
	*/
	vector3df CalculateRotationalMomentum(GameObject *ThisObject);

	/**
	* \fn VectorNormalize
	* @brief Normzalizes a given nector
	* @param Given_Vector is a Vector3df holding a passed in vector to be determine its length
	* @author Ben Townroe
	* @return Returns the Normalizes vector
	*/
	vector3df VectorNormalize(vector3df Given_Vector);

	/**
	* \fn Length
	* @brief Determines and calculates the length of a vector
	* @param vec is a Vector3df holding a passed in vector to be determine its length
	* @author Ben Townroe
	* @return Returns a vector3df holding the Momentum on the x, y, z planes
	*/
	float Length(vector3df vec);

	//vector3df ComputeImpulse(GameObject *ThisObject, vector3df Collision_Point, float CollisionForce);

	/**
	* @var Impulse
	* @brief Holds the vector the linear impulse
	*/
	vector3df Impulse;
public:

	/**
	* \fn CollisionResolutionEngine
	* @brief Acts as the default constructor for the CollisionResolutionEngine
	* @author Ben Townroe
	* @return Does not return a value
	*/
	CollisionResolutionEngine();

	/**
	* \fn Resolve Collisions
	* @brief Calculates the necessary values for collisions when one occurs
	* @param *ThisObject is a pointer to a GameObject passed in from the program
	* @param Collision_Point is the vector co-ordinate at which the collision takes place
	* @param CollisionForce is the float value, holding the amount of force applied
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void ResolveCollisions(GameObject *ThisObject, irr::core::vector3df Collision_Point, float CollisionForce);

	/**
	* \fn ResolveUpdate
	* @brief Calculates the necessary values for collisions when does not occurs
	* @param *ThisObject is a pointer to a GameObject passed in from the program
	* @param CollisionForce is the float value, holding the amount of force applied
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void ResolveUpdate(GameObject *ThisObject, float CollisionForce);

	/**
	* \fn ~CollisionResolutionEngine
	* @brief Acts as the default deconstructor for the CollisionResolutionEngine
	* @author Ben Townroe
	* @return Does not return a value
	*/
	~CollisionResolutionEngine();
};

