#pragma once


#include <string>
#include <irrlicht.h>
#include "EmotionEngine.h"

using namespace irr;
using namespace core;

/********************************************//**
* \class GameObject
* \brief GameObject class for loading in objects
* \details class container for properties of objects in the game
* \author Brandon Jin Yang Lim
* \version 1.0
* \date 2019
************************************************/
class GameObject {
	private:
		/**
		* \addtogroup filePaths
		* \brief paths to relevant files
		* \details the filepaths of the mesh and texture for the object
		* @{
		*/
		/**
		* \var meshPath
		* \brief mesh filepath
		* \details relative path to the object model file
		*/
		std::string meshPath;
		/**
		* \var texPath
		* \brief texture filepath
		* \details relative path to the object's texture file
		*/
		std::string texPath;
		/**
		* @}
		*/
		
		/**
		* \addtogroup positionOrientation
		* \brief position, rotation and scale
		* \details the position, rotation and scale of the object
		* @{
		*/
		/**
		* \var posX
		* \brief X-axis position
		*/
		float posX;
		/**
		* \var posY
		* \brief Y-axis position
		*/
		float posY;
		/**
		* \var posZ
		* \brief Z-axis position
		*/
		float posZ;
		/**
		* \var scaleX
		* \brief X-axis scale multiplier
		*/
		float scaleX;
		/**
		* \var scaleY
		* \brief Y-axis scale multiplier
		*/
		float scaleY;
		/**
		* \var scaleZ
		* \brief Z-axis scale multiplier
		*/
		float scaleZ;
		/**
		* \var rotX
		* \brief rotation about the X-axis
		*/
		float rotX;
		/**
		* \var rotY
		* \brief rotation about the Y-axis
		*/
		float rotY;
		/**
		* \var rotZ
		* \brief rotation about the Z-axis
		*/
		float rotZ;
		/**
		* @}
		*/
		
		/**
		* \addtogroup motionData
		* \brief linear and rotational velocity
		* \details the linear and rotational velocity of the object. rotational is around the corresponding axis
		* @{
		*/
		/**
		* \var velX
		* \brief X-axis linear velocity
		*/
		float velX;
		/**
		* \var velY
		* \brief Y-axis linear velocity
		*/
		float velY;
		/**
		* \var velZ
		* \brief Z-axis linear velocity
		*/
		float velZ;
		/**
		* \var rotvX
		* \brief rotational velocity about the X-axis
		*/
		float rotvX;
		/**
		* \var rotvY
		* \brief rotational velocity about the Y-axis
		*/
		float rotvY;
		/**
		* \var rotvZ
		* \brief rotational velocity about the Z-axis
		*/
		float rotvZ;
		/**
		* @}
		*/
		
		/**
		* \var ptm
		* \brief planar texture mapping
		* \details variable containing the planar texture mapping information
		*/
		float ptm;
		
		/**
		* \var hasAnim
		* \brief flag for animations
		* \details variable denoting whether the model has animations
		*/
		int hasAnim;

		/**
		* \var mass
		* \brief mass of object
		* \details variable containing mass of object for use with physics
		*/
		float mass;

		/**
		* \var isPickable
		* \brief for colliders
		* \details variable denoting whether the object is "pickable" by colliders, and is thus able to be collided against.
		*/
		int isPickable;

		/**
		* \var hasPhysics
		* \brief physics flag
		*/
		bool hasPhysics;

		/**
		* \var interactible
		* \brief interaction flag for NPCs
		*/
		bool interactible;

		/**
		* \var emotions
		* \brief emotion management system for NPCs
		*/
		EmotionEngine emotions;
		
		/**
		* \var hunger
		* \brief hunger var for affordances
		*/
		float hunger;
		
		/**
		* \var hungerRate
		* \brief rate of hunger gain
		*/
		float hungerRate;
		
	public:
		/********************************************//**
		 * \fn GameObject
		 * \brief overloaded constructor
		 * \details overloaded constructor which sets all variables. For models with animations
		 * \author Brandon Jin Yang Lim
		 ***********************************************/
		GameObject(std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float p, int h, float m, int pick, bool phys, bool interact);
		
		/********************************************//**
		 * \fn GameObject
		 * \brief overloaded constructor
		 * \details overloaded constructor which sets variables. for models with no animations
		 * \author Brandon Jin Yang Lim
		 ***********************************************/
		GameObject(std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float p, float m, int pick, bool phys, bool interact);

		/**
		* \addtogroup getFunc
		* \brief get functions
		* \details getter functions which return the variable
		* @{
		*/
		std::string getMesh() { return meshPath; }
		std::string getTex() { return texPath; }
		float getPosX() { return posX; }
		float getPosY() { return posY; }
		float getPosZ() { return posZ; }
		float getRotX() { return rotX; }
		float getRotY() { return rotY; }
		float getRotZ() { return rotZ; }
		float getScaleX() { return scaleX; }
		float getScaleY() { return scaleY; }
		float getScaleZ() { return scaleZ; }
		float getPTM() { return ptm; }
		int getAnim() { return hasAnim; }
		float getMass() { return mass; }
		int getPickable() { return isPickable; }
		bool getPhysics() { return hasPhysics; }
		bool getInteractible() { return interactible; }
		vector3df getScaleVector();
		vector3df getPosVector();
		vector3df getRotVector();
		float getVelX() { return velX; }
		float getVelY() { return velY; }
		float getVelZ() { return velZ; }
		vector3df getLineVel();
		float getRotVX() { return rotvX; }
		float getRotVY() { return rotvY; }
		float getRotVZ() { return rotvZ; }
		vector3df getRotVel();
		std::string getEmotions();
		bool isHungry();
		/**
		* @}
		*/

		/**
		* \addtogroup setFunc
		* \brief set functions
		* \details setter functions for setting variables
		* @{
		*/
		void setMesh(std::string mPath);
		void setTex(std::string tPath);
		void setPosX(float x);
		void setPosY(float y);
		void setPosZ(float z);
		void setRotX(float x);
		void setRotY(float y);
		void setRotZ(float z);
		void setScaleX(float x);
		void setScaleY(float y);
		void setScaleZ(float z);
		void setPTM(float p);
		void setAnim(int h);
		void setMass(float m);
		void setPickable(int flag);
		void setPhysics(bool phys);
		void setInteractible(bool interact);
		void setVelX(float vx);
		void setVelY(float vy);
		void setVelZ(float vz);
		void setRotVX(float rx);
		void setRotVY(float ry);
		void setRotVZ(float rz);
		/**
		* @}
		*/
		
		/********************************************//**
		 * \fn incHunger
		 * \brief increases hunger
		 * \author Brandon Jin Yang Lim
		 ***********************************************/
		void incHunger(float val);
		
		/********************************************//**
		 * \fn decHunger
		 * \brief decreases hunger
		 * \author Brandon Jin Yang Lim
		 ***********************************************/
		void decHunger(float val);
		
		/********************************************//**
		 * \fn initEmotions
		 * \brief initialiser for emotion var
		 * \details Initialises emotion management system for NPCs to base values
		 * \author Brandon Jin Yang Lim
		 ***********************************************/
		void initEmotions();


		/********************************************//**
		 * \fn initEmotionVals
		 * \brief second initialiser for emotion var
		 * \details Initialises emotion management system for NPCs to specified values
		 * \author Brandon Jin Yang Lim
		 ***********************************************/
		void initEmotionVals();
};