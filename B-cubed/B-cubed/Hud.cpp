#include "Hud.h"



void Hud::Update()
{
	updatePlayerHealth();
	updatePlayerAmmo();
	updateNPCData();
	updateDisplay();
}

void Hud::updatePlayerHealth()
{
	PlayerHealth = Player_ptr->getPlayerHealthStr();
}

void Hud::updatePlayerAmmo()
{
	PlayerAmmo = Player_ptr->getAmmoStr();
}

void Hud::updateNPCData()
{
	//Needed to be in this format to solve strange issues.
	//NPCData = "NPC DATA: \n NPC NAME: + \n NPC EMOTION STATE: Suprise-Anticipation";
}

void Hud::updateDisplay()
{
	guienv_ptr->clear();
	//guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", rect<s32>(10, 10, 260, 22), false);

	std::string HealthString = "Health: " + PlayerHealth; //Initialise string into a concatenated string 
	std::wstring wide_string1 = std::wstring(HealthString.begin(), HealthString.end()); //convert string into a wide string
	const wchar_t* HSFinal = wide_string1.c_str();	//convert the wide string to a const wchar_t*

	std::string AmmoString = "Ammo: " + PlayerAmmo;
	std::wstring wide_string2 = std::wstring(AmmoString.begin(), AmmoString.end());
	const wchar_t* ASFinal = wide_string2.c_str(); // <-- REMEMBER TO CHECK WHAT STRING YOUR CONVERTING


	//============= NOTE MORE NPC DATA WILL BE NEEDED AS TIME CONTINUES ====================================================
	std::string NPCData = "INTERACTION NPC DATA: ";
	std::wstring wide_string3 = std::wstring(NPCData.begin(), NPCData.end());
	const wchar_t* NPCFinal = wide_string3.c_str();

	guienv_ptr->addStaticText(HSFinal, rect<s32>(10, 20, 260, 50), false);
	guienv_ptr->addStaticText(ASFinal, rect<s32>(10, 40, 260, 70), false);
	guienv_ptr->addStaticText(NPCFinal, rect<s32>(10, 380, 260, 500), false);
	//rect<s32>()
	guienv_ptr->drawAll();
}


//void Hub::updatePlayerPosition()
//{

//}