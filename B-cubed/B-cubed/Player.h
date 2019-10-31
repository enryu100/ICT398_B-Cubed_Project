#pragma once

#include <string>

class Player
{

private:
	/**
	* @brief integer variable that stores the players Health
	* @Author Ben Townroe
	*/
	int playerHealth; //Holds the players health

	/**
	* @brief integer variable that stores the players Ammo
	* @Author Ben Townroe
	*/
	int playerAmmo; //ammount of ammo the player holds

	//Vec3 PlayerPosition; //Developer Only

public:
	/**
	* @function Player
	* @brief Acts as the default constructor for player
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	Player()
	{
		playerHealth = 100;
		playerAmmo = 100;
		//PlayerPosition;
	}

	/**
	* @function ~player
	* @brief Acts as the default deconstructor for player
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	~Player();

	/**
	* @function setPlayerHealth
	* @brief sets a value on the players health
	* @param value: an integer value given to set the players Health
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void setPlayerHealth(int value);
	
	/**
	* @function setPlayerAmmo
	* @brief sets a value one the players Ammo
	* @param value: an integer value given to set the players Ammo level
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void setPlayerAmmo(int value);

	//void setPlayerPosition(float x, float y, float z); //Developer only

	/**
	* @function increasePlayersHealth
	* @brief increases Players Health incrementally by some value
	* @param value: the passed in integer value to increment Health by
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void increasePlayerHealth(int value);

	/**
	* @function increasePlayersAmmp
	* @brief increases Players Ammo incrementally by some value
	* @param value: the passed in integer value to increment Ammo by
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void increaseAmmo(int value);

	/**
	* @function decreasePlayersHealth
	* @brief decreases Players Health incrementally by some value
	* @param value: the passed in integer value to decrement health by
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void decreasePlayerHealth(int value);

	/**
	* @function decreasePlayersAmmp
	* @brief decreases Players Ammo incrementally by some value
	* @param value: the passed in integer value to decrement Ammo by
	* @Author Ben Townroe
	* @return Does not return a value
	*/
	void decreaseAmmo(int value);

	/**
	* @function getPlayerHealth
	* @brief returns the players current health
	* @Author Ben Townroe
	* @return Returns the players current health as an integer
	*/
	int getPlayerHealth();

	/**
	* @function getAmmo
 	* @brief returns the players Ammo Ammount
	* @Author Ben Townroe
	* @return Returns the players current ammo as an integer
	*/
	int getAmmo();
	
	//Vector3 getPlayerPosition(); //Developer Only

	/**
	* @brief a string variable used to store the necessay health data as a string
	* @Author Ben Townroe
	*/
	std::string getPlayerHealthStr();

	/**
	* @brief a string variable used to store the necessay ammo data as a string
	* @Author Ben Townroe
	*/
	std::string getAmmoStr();
};

