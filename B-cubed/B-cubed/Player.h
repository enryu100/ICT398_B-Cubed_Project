#pragma once

#include <string>

class Player
{

private:
	int playerHealth; //Holds the players health
	int playerAmmo; //ammount of ammo the player holds
	//Vec3 PlayerPosition; //Developer Only

public:
	Player()
	{
		playerHealth = 100;
		playerAmmo = 100;
		//PlayerPosition;
	}
	~Player();

	void setPlayerHealth(int value);
	
	void setPlayerAmmo(int value);

	//void setPlayerPosition(float x, float y, float z); //Developer only

	void increasePlayerHealth(int value);

	void increaseAmmo(int value);

	void decreasePlayerHealth(int value);

	void decreaseAmmo(int value);

	int getPlayerHealth();

	int getAmmo();
	
	//Vector3 getPlayerPosition(); //Developer Only

	std::string getPlayerHealthStr();

	std::string getAmmoStr();
};

