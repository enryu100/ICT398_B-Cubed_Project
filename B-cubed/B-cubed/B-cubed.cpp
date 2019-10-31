// B-cubed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "irrlicht.h"
#include <iostream>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <string>
#include <vector>
#include "Player.h"
#include "Hud.h"
#include "GameObject.h"
#include "lua_Script.h"
#include "CustomEventReceiver.h"

#include "Path.h"
#include "NPCVehicle.h"
#include "CollisionResolutionEngine.h"

using namespace std;

enum
{
	// I use this ISceneNode ID to indicate a scene node that is
	// not pickable by getSceneNodeAndCollisionPointFromRay()
	ID_IsNotPickable = 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be picked by ray selection.
	IDFlag_IsPickable = 1 << 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be highlighted.  In this example, the
	// homonids can be highlighted, but the level mesh can't.
	IDFlag_IsHighlightable = 1 << 1
};


int main()
{
	CustomEventReceiver receiver;
	
	video::E_DRIVER_TYPE driverType;
	driverType = video::EDT_OPENGL;
	IrrlichtDevice *device = createDevice(driverType, dimension2d<u32>(1000, 780), 16, false, false, false, &receiver);


	if (!device)
		return 1;

	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	scene::ICameraSceneNode*        camera;
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	IGUIFont* font = guienv->getFont("media/myfont.png");
	//device->getGUIEnvironment()->getSkin()->setFont("media/myfont");
	if (font) 
	{
		device->getGUIEnvironment()->getSkin()->setFont(font);
	}
	device->getGUIEnvironment()->getSkin()->setColor(gui::EGDC_BUTTON_TEXT,video::SColor(255, 0, 100, 0));
	//device->getGUIEnvironment()->getSkin()->getFont()->getDimension()=
	//guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",rect<s32>(10, 10, 260, 22), false);
	//guienv->addStaticText(L"Health: ", rect<s32>(10, 10, 260, 22), false);
	

	Player player; //Initilises the player class
	Player *ptr_player = &player; //Pointer to the player Object

	Hud ThisHud(ptr_player, guienv);


	//guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",rect<s32>(10, 10, 260, 22), true);
	//device->maximizeWindow();


	camera = smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, ID_IsNotPickable, 0, 0, true, 0.f);
	camera->setFarValue(5000.0f);
	camera->setNearValue(1.0f);
	//camera->set
	camera->setFOV(45.0f);
	camera->setAutomaticCulling(false);

	camera->setPosition(vector3df(30, 80, 30));

	vector<GameObject*> gameObjects;
	
	//NPCs
	gameObjects.push_back(new GameObject("NPC1", "media/Sydney.md2", "media/sydney.bmp", -100, 0, -60, 0, 0, 0, 3.0, 3.0, 3.0, 0, 1, 1, 2, false, true));

	gameObjects.push_back(new GameObject("NPC2", "media/Sydney.md2", "media/sydney.bmp", 250, 0, 180, 0, 180, 0, 3.0, 3.0, 3.0, 0, 1, 1, 2, false, true));
																						
	gameObjects.push_back(new GameObject("NPC3", "media/Sydney.md2", "media/sydney.bmp", -170, 0, 80, 0, 0, 0, 3.0, 3.0, 3.0, 0, 1, 1, 2, false, true));

	//food object for affordance stuff.

	//gameObjects.push_back(new GameObject("food", "media/Bread.obj", "", 0, 0, 200, 40, 0, 0, 30, 30, 30, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("food", "media/Bread.obj", "", 0, 0, -60, 40, 0, 0, 30, 30, 30, 0, 1, 0, false, false));
	gameObjects[3]->makeEdible();

	//cube for physics

	//Room walls, floors and wall-mounted objects
	gameObjects.push_back(new GameObject("media/whiteBoard.obj", "", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/roof.obj", "", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/windowLeft.obj", "", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/windowRight.obj", "", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/windowCenter.obj", "", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/backWall.obj", "media/redBackWall.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.002, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/farWall.obj", "media/farWall.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/leftWall.obj", "media/redWall.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/rightWall.obj", "media/redWall.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/floor.obj", "media/Navy-Blue-Carpet.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/benchRight.obj", "media/WhiteTabletop.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/benchCenter.obj", "media/WhiteTabletop.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/benchLeft.obj", "media/WhiteTabletop.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/door.obj", "media/door.bmp", 0, 0, 0, 0, 0, 0, 1.0, 1.0, 1.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/projector.obj", "", 0, 160, 0, 180, 90, 0, 1.5, 1.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/projectorScreen.obj", "", -330, 110, 0, 0, 90, 0, 0.3, 0.3, 0.3, 0, 1, 0, false, false));

	//cupboards
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 140, 100, -576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 0, 100, -576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", -140, 100, -576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 140, 100, 576, 0, 180, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 0, 100, 576, 0, 180, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", -140, 100, 576, 0, 180, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));

	//tables, lecterns and lectern-top objects
	gameObjects.push_back(new GameObject("media/desalto_bend_in_obj.obj", "media/WhiteTabletop.bmp", -80, -80, 200, 0, 90, 0, 1, 1, 1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/desalto_bend_in_obj.obj", "media/WhiteTabletop.bmp", -0, -80, -200, 0, 90, 0, 1, 1, 1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/lecturn.obj", "media/WhiteTabletop.bmp", 180, -86, 200, 0, 0, 0, 3, 4, 6, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("marker", "media/marker.obj", "", 180, -31, 160, 0, 0, 0, 1, 1, 1, 0, 1, 1, false, false));

	//PC-workstation sets
	gameObjects.push_back(new GameObject("media/monitor.obj", "", 440, 75, -578, 0, 0, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", 190, -13, -560, 0, 0, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", 220, -13, -540, 0, 0, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", 270, -13, -550, 0, 0, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", 250, -85, -500, 0, -180, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", 290, 75, -578, 0, 0, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", 40, -13, -560, 0, 0, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", 70, -13, -540, 0, 0, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", 120, -13, -550, 0, 0, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", 100, -85, -500, 0, -180, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", 0, 75, -578, 0, 0, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -250, -13, -560, 0, 0, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -220, -13, -540, 0, 0, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -170, -13, -550, 0, 0, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -180, -85, -500, 0, -180, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", 150, 75, -578, 0, 0, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -120, -13, -560, 0, 0, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -90, -13, -540, 0, 0, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -40, -13, -550, 0, 0, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -50, -85, -500, 0, -180, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", 70, 75, 578, 0, -180, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", 190, -13, 560, 0, -180, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", 290, -13, 540, 0, -180, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", 240, -13, 550, 0, -180, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", 250, -85, 500, 0, 0, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -70, 75, 578, 0, -180, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", 40, -13, 560, 0, -180, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", 150, -13, 540, 0, -180, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", 110, -13, 550, 0, -180, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", 100, -85, 500, 0, 0, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -380, 75, 578, 0, -180, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -250, -13, 560, 0, -180, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -150, -13, 540, 0, -180, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -200, -13, 550, 0, -180, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -180, -85, 500, 0, 0, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -250, 75, 578, 0, -180, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -120, -13, 560, 0, -180, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -10, -13, 540, 0, -180, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -60, -13, 550, 0, -180, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -50, -85, 500, 0, 0, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -650, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, -390, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, -410, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, -450, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -450, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -520, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, -270, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, -300, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, -340, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -340, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -400, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, -150, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, -180, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, -220, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -220, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -280, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, -30, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, -60, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, -100, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -100, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, 240, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 490, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 470, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 430, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 440, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, 120, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 370, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 350, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 310, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 320, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, 0, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 250, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 230, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 190, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 200, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -120, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 130, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 110, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 70, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 80, 0, 270, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));

	float ptm;
	core::map<ISceneNode*, GameObject*> objectByNode;
	core::map<std::string, GameObject*> objectsByName;
	objectByNode.clear();
	std::vector<IAnimatedMeshSceneNode*> nodes;

	int i = 0;
	for (i = 0; i < gameObjects.size(); i++){
		gameObjects[i]->setObjMesh(smgr->getMesh(gameObjects[i]->getMesh().c_str()));
		
		
		ptm = gameObjects[i]->getPTM();
		if(ptm != 0){
			smgr->getMeshManipulator()->makePlanarTextureMapping(gameObjects[i]->getObjMesh()->getMesh(0), ptm);
		}
		if (!gameObjects[i]->getObjMesh())
		{
			device->drop();
			return 1;
		}
		
		
		
		switch (gameObjects[i]->getPickable()) {
			case 0:
				nodes.push_back(smgr->addAnimatedMeshSceneNode(gameObjects[i]->getObjMesh(), 0, ID_IsNotPickable));
				break;
			case 1:
				nodes.push_back(smgr->addAnimatedMeshSceneNode(gameObjects[i]->getObjMesh(), 0, IDFlag_IsPickable));
				break;
			case 2:
				nodes.push_back(smgr->addAnimatedMeshSceneNode(gameObjects[i]->getObjMesh(), 0, IDFlag_IsPickable | IDFlag_IsHighlightable));
				break;
			default:
				nodes.push_back(smgr->addAnimatedMeshSceneNode(gameObjects[i]->getObjMesh()));
				break;
		}

		gameObjects[i]->setID(i);
		gameObjects[i]->setNode(nodes[i]);

		if (gameObjects[i]->getNode())
		{
			objectByNode.insert(gameObjects[i]->getNode(), gameObjects[i]);
			if (gameObjects[i]->getName() != "") {
				objectsByName.insert(gameObjects[i]->getName(), gameObjects[i]);
			}

			gameObjects[i]->getNode()->setMaterialFlag(EMF_LIGHTING, false);
			if(gameObjects[i]->getTex() != ""){
				gameObjects[i]->getNode()->setMaterialTexture(0, driver->getTexture(gameObjects[i]->getTex().c_str()));
			}
			gameObjects[i]->getNode()->setScale(gameObjects[i]->getScaleVector());
			gameObjects[i]->getNode()->setPosition(gameObjects[i]->getPosVector());
			gameObjects[i]->getNode()->setRotation(gameObjects[i]->getRotVector());

			if (gameObjects[i]->getAnim() == 1) {
				gameObjects[i]->getAnimNode()->setMD2Animation(scene::EMAT_STAND);
			}

			if (gameObjects[i]->getInteractible()) {
				//object in NPC
				gameObjects[i]->initEmotions();
				scene::ITriangleSelector* tempselector = smgr->createTriangleSelector(gameObjects[i]->getAnimNode());
				gameObjects[i]->getNode()->setTriangleSelector(tempselector);
				tempselector->drop();
			}

			if(gameObjects[i]->getPickable() != 0){
				scene::ITriangleSelector* selector = smgr->createTriangleSelector(gameObjects[i]->getObjMesh(), gameObjects[i]->getAnimNode());
				gameObjects[i]->getNode()->setTriangleSelector(selector);
				if (selector)
				{
					scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
						selector, camera, core::vector3df(30, 1000, 30),
						core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
					selector->drop(); // As soon as we're done with the selector, drop it.
					camera->addAnimator(anim);
					anim->drop();  // And likewise, drop the animator when we're done referring to it.
				}
			}
		}
	}

	//unique personalities for NPCs. overrides present defaults
	gameObjects[0]->initEmotionVals(1, -1, 0, -1, 3, 0.5, 1, 2, 0.8, 2, 2, 2, 120, 50, 3, 10);
	gameObjects[1]->initEmotionVals(-3, 2, 4, 2, -2, 1, 1, 2, 1, 1, 1, 1, 120, 50, 3, 7);
	gameObjects[2]->initEmotionVals(1, -1, 0, -1, 1, 2, 0.5, 2, 1, 2, 2, 2, 120, 50, 3, 10);

	//cube object for physics
	GameObject* physCube = new GameObject("cube", "", "", 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 10, 2, true, false);
	ISceneNode* cubeNode = smgr->addCubeSceneNode(50.0f, 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
	physCube->setNode(cubeNode);
	cubeNode->setPosition(physCube->getPosVector());
	cubeNode->setRotation(physCube->getRotVector());
	cubeNode->setScale(physCube->getScaleVector());
	objectByNode.insert(cubeNode, physCube);
	objectsByName.insert(physCube->getName(), physCube);
	cubeNode->setMaterialFlag(video::EMF_LIGHTING, false);
	ITriangleSelector* cubeSel = smgr->createTriangleSelectorFromBoundingBox(cubeNode);
	cubeNode->setTriangleSelector(cubeSel);
	cubeSel->drop();

	
	device->getCursorControl()->setVisible(false);

	// Add the billboard. temporarily used to signal interactible
	scene::IBillboardSceneNode * bill = smgr->addBillboardSceneNode();
	bill->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
	bill->setMaterialTexture(0, driver->getTexture("media/particle.bmp"));
	bill->setMaterialFlag(video::EMF_LIGHTING, false);
	bill->setMaterialFlag(video::EMF_ZBUFFER, false);
	bill->setSize(core::dimension2d<f32>(20.0f, 20.0f));
	bill->setID(ID_IsNotPickable); // This ensures that we don't accidentally ray-pick it

	// Remember which scene node is selected
	scene::ISceneNode* highlightedSceneNode = 0;
	scene::ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();
	GameObject* targetObject = 0;
	int lastFPS = -1;
	int tempflag = 0, tempflag2 = 0, hasbeenmoved = 0, clicked = 0;


	//std::list<vector3df> NPC1Path = { vector3df(-100, 0, -100), vector3df(0, 0, 0) , vector3df(-50, 0, -50) , vector3df(-50, 0, 50) , vector3df(-100, 0, -100) };


	Vector3 NPC1P1, NPC1P2, NPC1P3, NPC1P4;
	Vector3 NPC2P1, NPC2P2, NPC2P3, NPC2P4;
	Vector3 NPC3P1, NPC3P2, NPC3P3, NPC3P4;

	NPC1P1.x = -100;
	NPC1P1.y = 0;
	NPC1P1.z = -60;
	//===============
	NPC1P2.x = -100;
	NPC1P2.y = 0;
	NPC1P2.z = -350;
	//===============
	NPC1P3.x = 150;
	NPC1P3.y = 0;
	NPC1P3.z = -350;
	//===============
	NPC1P4.x = 150;
	NPC1P4.y = 0;
	NPC1P4.z = -60;

	std::list<Vector3> NPC1Path = { NPC1P1, NPC1P2 , NPC1P3 , NPC1P4 };
	Path npc1Path = Path();
	Path npcTestPath = Path(NPC1Path);
	npc1Path.SetPath(NPC1Path);

	//=============================================================================

	NPC3P1.x = -170;
	NPC3P1.y = 0;
	NPC3P1.z = 80;
	//===============
	NPC3P2.x = -170;
	NPC3P2.y = 0;
	NPC3P2.z = 340;
	//===============
	NPC3P3.x = 20;
	NPC3P3.y = 0;
	NPC3P3.z = 340;
	//===============
	NPC3P4.x = 20;
	NPC3P4.y = 0;
	NPC3P4.z = 80;

	std::list<Vector3> NPC3Path = { NPC3P1, NPC3P2 , NPC3P3 , NPC3P4 };
	Path npc3Path = Path();
	Path npcTestPath3 = Path(NPC3Path);
	npc3Path.SetPath(NPC3Path);


	//Path for NPC1
	NPCVehicle VNPC1(gameObjects[0]->getPosX(), gameObjects[0]->getPosY(), gameObjects[0]->getPosZ(), &npcTestPath);

	//Path for NPC3
	NPCVehicle VNPC3(gameObjects[2]->getPosX(), gameObjects[2]->getPosY(), gameObjects[2]->getPosZ(), &npcTestPath3);

	CollisionResolutionEngine ThisResolutionEngine;


	while (device->run())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, SColor(255, 100, 101, 140));

			smgr->drawAll();

			VNPC1.Update();
			gameObjects[0]->incHunger(0.001);
			VNPC3.Update();

			vector3df tempvec1;
			tempvec1.X = VNPC1.Position.x;
			tempvec1.Y = VNPC1.Position.y;
			tempvec1.Z = VNPC1.Position.z;
			gameObjects[0]->setPosVec(tempvec1);
			nodes[0]->setPosition(tempvec1);

			vector3df tempvec3;
			tempvec3.X = VNPC3.Position.x;
			tempvec3.Y = VNPC3.Position.y;
			tempvec3.Z = VNPC3.Position.z;
			gameObjects[2]->setPosVec(tempvec3);
			nodes[2]->setPosition(tempvec3);

			//NPC1->setPosX(VNPC1.Position.X);
			//NPC1->setPosZ(VNPC1.Position.Z);

			//nodes[3]->setPosition(vector3df(0, 100, -100));

			////ThisResolutionEngine.ResolveCollisions(gameObjects[3], core::vector3df(0, -20, -60), 0.001f);
			////nodes[3]->setPosition(gameObjects[3]->getPosVector());

			//deselect currently selected
			if (highlightedSceneNode) {
				highlightedSceneNode = 0;
			}

			// All intersections in this example are done with a ray cast out from the camera to
			// a distance of 1000.  You can easily modify this to check (e.g.) a bullet
			// trajectory or a sword's position, or create a ray from a mouse click position using
			// ISceneCollisionManager::getRayFromScreenCoordinates()
			core::line3d<f32> ray;
			ray.start = camera->getPosition();
			ray.end = ray.start + (camera->getTarget() - ray.start).normalize() * 1000.0f;

			// Tracks the current intersection point with the level or a mesh
			core::vector3df intersection;
			// Used to show with triangle has been hit
			core::triangle3df hitTriangle;

			scene::ISceneNode * selectedSceneNode = 
				collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, hitTriangle, IDFlag_IsPickable, 0);

			// If the ray hit anything, do stuff
			if (selectedSceneNode)
			{
				if ((selectedSceneNode->getID() & IDFlag_IsHighlightable) == IDFlag_IsHighlightable)
				{
					if (tempflag == 0) {
						std::cout << "pickable object targeted" << std::endl;
					}
					

					highlightedSceneNode = selectedSceneNode;

					// Highlighting in this case means turning lighting OFF for this node,
					// which means that it will be drawn with full brightness.
					highlightedSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

					if (!objectByNode.empty()) {
						targetObject = (GameObject*)objectByNode.find(highlightedSceneNode);

						//if object exists and is interactible, do stuff
						if (targetObject) {

							if (tempflag == 0) {
								std::cout << "target exists as game object" << std::endl;
								tempflag = 1;
							}

							if (targetObject->getInteractible()) {
								ThisHud.updateNPCData(targetObject->getEmotions());
							}
							

							bill->setPosition(intersection);

							//other inputs commented out for stability while testing
							//if 'W' key pressed, change joy
							if (receiver.IsKeyDown(KEY_KEY_W)) {
								std::cout << "W-key pressed!" << std::endl;
								//increase joy by 5
								targetObject->changeEmotion(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
								tempflag2 = 0;
							}
							////if 'A' key pressed, change Trust
							//if (receiver.IsKeyDown(KEY_KEY_A)) {
							//	std::cout << "A-key pressed!" << std::endl;
							//	//increase joy by 5
							//	targetObject->changeEmotion(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
							//	tempflag2 = 0;
							//}
							////if 'S' key pressed, change Fear
							//if (receiver.IsKeyDown(KEY_KEY_S)) {
							//	std::cout << "S-key pressed!" << std::endl;
							//	//increase joy by 5
							//	targetObject->changeEmotion(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
							//	tempflag2 = 0;
							//}
							////if 'D' key pressed, change surprise
							//if (receiver.IsKeyDown(KEY_KEY_D)) {
							//	std::cout << "D-key pressed!" << std::endl;
							//	//increase joy by 5
							//	targetObject->changeEmotion(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
							//	tempflag2 = 0;
							//}

							//check for emotional response
							if (targetObject->getEmotionResponse() == 1 && tempflag2 == 0) {
								std::cout << "Emotion Response received!" << std::endl;
								tempflag2 = 1;
							}

							//if object has physics, pass object to physics stuff on mouse leftclick
							if (targetObject->getPhysics()); {
								if (receiver.getMouseClick() && clicked == 0) {
									//left click flag, to prevent repeat inputs
									//must mouse away from object before second input can be read
									clicked = 1;
									vector3df objIntersection;
									//calculate intersection coords relative to the object
									std::cout << "clicked on physics cube!" << std::endl;
									objIntersection.X = intersection.X - targetObject->getPosX();
									objIntersection.Y = intersection.Y - targetObject->getPosY();
									objIntersection.Z = intersection.Z - targetObject->getPosZ();
									std::cout << "collision points are: \nX: " << objIntersection.X << "\nY: " << objIntersection.Y << "\nZ: " << objIntersection.Z << std::endl;
									
									ThisResolutionEngine.ResolveCollisions(gameObjects[3], core::vector3df(objIntersection.X, objIntersection.Y, objIntersection.Z), 0.001f);
									nodes[3]->setPosition(gameObjects[3]->getPosVector());
									////physFunc(targetObject, objIntersection, force);
								}
							}
						}
					}
					else {
						std::cout << "no target found" << std::endl;
					}
				}
				else {
					ThisHud.updateNPCData("");
					tempflag = 0;
					clicked = 0;
				}
			}

			ThisHud.Update();

			//positioning test
			if (receiver.IsKeyDown(KEY_KEY_Z)) {
				GameObject *target = (GameObject*)objectsByName.find("marker");

				ISceneNode *tNode = nodes[29];
				if ((!tNode) || tNode == nullptr) {
					std::cout << "error: no node" << std::endl;
				}
				vector3df tmp = target->getPosVector();
				tmp.Z = 100.0f;
				target->setPosVec(tmp);
				tNode->setPosition(tmp);
			}

			//on esc press, exit
			if (receiver.IsKeyDown(KEY_ESCAPE)) {
				device->closeDevice();
			}
			
			if (gameObjects[0]->isHungry()) {
				vector3df NPCPos = gameObjects[0]->getPosVector();
				vector3df FoodPos = gameObjects[3]->getPosVector();

				//if NPC is within 10 units of food horizontally, and food is edible
				if ((NPCPos.X - FoodPos.X <= 10) && (NPCPos.X - FoodPos.X >= -10) &&
					(NPCPos.Z - FoodPos.Z <= 10) && (NPCPos.Z - FoodPos.Z >= -10) &&
					gameObjects[3]->isEdible()){
					//food in range
					gameObjects[0]->decHunger(50);
					
				}
			}

			driver->endScene();

			int fps = driver->getFPS();

			if (lastFPS != fps)
			{
				core::stringw str = L"ICT398 B-Cubed Project - Irrlicht Engine [";
				str += driver->getName();
				str += "] FPS:";
				str += fps;

				device->setWindowCaption(str.c_str());
				lastFPS = fps;
			}
		}
	}
	device->drop();

	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
