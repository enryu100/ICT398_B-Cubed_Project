#pragma once

#include <string>

class Player
{

private:
	/**
	* @brief integer variable that stores the players Health
	* @author Ben Townroe
	*/
	int playerHealth; //Holds the players health

	/**
	* @brief integer variable that stores the players Ammo
	* @author Ben Townroe
	*/
	int playerAmmo; //ammount of ammo the player holds

	//Vec3 PlayerPosition; //Developer Only

public:
	/**
	* \fn Player
	* @brief Acts as the default constructor for player
	* @author Ben Townroe
	* @return Does not return a value
	*/
	Player()
	{
		playerHealth = 100;
		playerAmmo = 100;
		//PlayerPosition;
	}

	/**
	* \fn ~player
	* @brief Acts as the default deconstructor for player
	* @author Ben Townroe
	* @return Does not return a value
	*/
	~Player();

	/**
	* \fn setPlayerHealth
	* @brief sets a value on the players health
	* @param value: an integer value given to set the players Health
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void setPlayerHealth(int value);
	
	/**
	* \fn setPlayerAmmo
	* @brief sets a value one the players Ammo
	* @param value: an integer value given to set the players Ammo level
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void setPlayerAmmo(int value);

	//void setPlayerPosition(float x, float y, float z); //Developer only

	/**
	* \fn increasePlayersHealth
	* @brief increases Players Health incrementally by some value
	* @param value: the passed in integer value to increment Health by
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void increasePlayerHealth(int value);

	/**
	* \fn increasePlayersAmmp
	* @brief increases Players Ammo incrementally by some value
	* @param value: the passed in integer value to increment Ammo by
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void increaseAmmo(int value);

	/**
	* \fn decreasePlayersHealth
	* @brief decreases Players Health incrementally by some value
	* @param value: the passed in integer value to decrement health by
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void decreasePlayerHealth(int value);

	/**
	* \fn decreasePlayersAmmp
	* @brief decreases Players Ammo incrementally by some value
	* @param value: the passed in integer value to decrement Ammo by
	* @author Ben Townroe
	* @return Does not return a value
	*/
	void decreaseAmmo(int value);

	/**
	* \fn getPlayerHealth
	* @brief returns the players current health
	* @author Ben Townroe
	* @return Returns the players current health as an integer
	*/
	int getPlayerHealth();

	/**
	* \fn getAmmo
 	* @brief returns the players Ammo Ammount
	* @author Ben Townroe
	* @return Returns the players current ammo as an integer
	*/
	int getAmmo();
	
	//Vector3 getPlayerPosition(); //Developer Only

	/**
	* @brief a string variable used to store the necessay health data as a string
	* @author Ben Townroe
	*/
	std::string getPlayerHealthStr();

	/**
	* @brief a string variable used to store the necessay ammo data as a string
	* @author Ben Townroe
	*/
	std::string getAmmoStr();
};

