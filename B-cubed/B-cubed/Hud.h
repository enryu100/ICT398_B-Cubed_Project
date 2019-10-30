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
	* @function updatePlayerHealth
	* @brief Updates the players health accordingly
	* @Author Ben Townroe
	* @return There is no return for this function
	*/
	void updatePlayerHealth();

	/**
	* @function updatePlayerAmmo
	* @brief Updates the players ammo accordingly
	* @Author Ben Townroe
	* @return There is no return for this function
	*/
	void updatePlayerAmmo();

	/**
	* @function updateDisplay
	* @brief Updates the information displayed on the hud
	* @Author Ben Townroe
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
	* @function Hud
	* @brief Acts as the default constructor for the hud class
	* @param *Play_ptr is the pointer to the player object
	* @param *env_ptr is the pointer to the gui interface object
	* @Author Ben Townroe
	* @return There is no return for this function
	*/
	Hud(Player *Play_ptr, IGUIEnvironment *env_ptr)
	{
		Player_ptr = Play_ptr;
		guienv_ptr = env_ptr;
	}

	/**
	* @function ~Hud
	* @brief Acts as the deconstructor for the hud class
	* @Author Ben Townroe
	* @return There is no return for this function
	*/
	~Hud() {};

	/**
	* @function Update
	* @brief On Update, updates all information needed to change the hud to display accurate information
	* @Author Ben Townroe
	* @return There is no return for this function
	*/
	void Update();

	/**
	* @function updateNPCData
	* @brief Gets the NPC's data from the Emotion Engine
	* @Author Ben Townroe
	* @return There is no return for this function
	*/
	void updateNPCData(std::string EmotionData);
};

