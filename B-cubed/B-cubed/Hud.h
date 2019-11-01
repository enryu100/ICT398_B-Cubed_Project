#pragma once
#include <string>
#include <irrlicht.h>
#include <iostream>

#include "Player.h"

//=== ONLY USED FOR THE IGUIENVIRONMENT ======
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

//============================================

class Hud
{
private:

	/**
	* @var PlayerHealth
	* @brief PlayerHealth is the amount of health the player has
	*/
	std::string PlayerHealth;

	/**
	* @var PlayerAmmo
	* @brief PlayerAmmo is the ammo the player holds
	*/
	std::string PlayerAmmo;

	/**
	* @var NPCData
	* @brief NPCData is the data displayed by the EmotionEngine
	*/
	std::string NPCData;

	/**
	* \fn updatePlayerHealth
	* @brief Updates the players health accordingly
	* @author Ben Townroe
	* @return There is no return for this function
	*/
	void updatePlayerHealth();

	/**
	* \fn updatePlayerAmmo
	* @brief Updates the players ammo accordingly
	* @author Ben Townroe
	* @return There is no return for this function
	*/
	void updatePlayerAmmo();

	/**
	* \fn updateDisplay
	* @brief Updates the information displayed on the hud
	* @author Ben Townroe
	* @return There is no return for this function
	*/
	void updateDisplay();
	//void updatePlayerPosition();

	//Pointers
	/**
	* @var *Player_ptr
	* @brief *Player_ptr holds the pointer to the player object
	*/
	Player *Player_ptr;

	/**
	* @var *guienv_ptr
	* @brief *guienv_ptr holds the pointer to access the gui interface
	*/
	IGUIEnvironment *guienv_ptr;

public:

	/**
	* \fn Hud
	* @brief Acts as the default constructor for the hud class
	* @param *Play_ptr is the pointer to the player object
	* @param *env_ptr is the pointer to the gui interface object
	* @author Ben Townroe
	* @return There is no return for this function
	*/
	Hud(Player *Play_ptr, IGUIEnvironment *env_ptr)
	{
		Player_ptr = Play_ptr;
		guienv_ptr = env_ptr;
	}

	/**
	* \fn ~Hud
	* @brief Acts as the deconstructor for the hud class
	* @author Ben Townroe
	* @return There is no return for this function
	*/
	~Hud() {};

	/**
	* \fn Update
	* @brief On Update, updates all information needed to change the hud to display accurate information
	* @author Ben Townroe
	* @return There is no return for this function
	*/
	void Update();

	/**
	* \fn updateNPCData
	* @brief Gets the NPC's data from the Emotion Engine
	* @author Ben Townroe
	* @return There is no return for this function
	*/
	void updateNPCData(std::string EmotionData);
};

