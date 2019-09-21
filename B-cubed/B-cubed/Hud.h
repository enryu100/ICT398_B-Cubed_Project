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
	std::string PlayerHealth;
	std::string PlayerAmmo;
	std::string NPCData;
	//string PlayerPosition;

	void updatePlayerHealth();
	void updatePlayerAmmo();
	void updateNPCData();
	void updateDisplay();
	//void updatePlayerPosition();

	//Pointers
	Player *Player_ptr;
	IGUIEnvironment *guienv_ptr;

public:
	Hud(Player *Play_ptr, IGUIEnvironment *env_ptr)
	{
		Player_ptr = Play_ptr;
		guienv_ptr = env_ptr;

		
	}
	~Hud() {};

	void Update();
};

