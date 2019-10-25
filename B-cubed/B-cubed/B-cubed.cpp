// B-cubed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <irrlicht.h>
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

#include "Player.h"
#include "Hud.h"
#include "GameObject.h"
#include <string>
#include <vector>

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
	
	video::E_DRIVER_TYPE driverType;
	driverType = video::EDT_OPENGL;
	IrrlichtDevice *device = createDevice(driverType, dimension2d<u32>(1000, 780));


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

	//NPC
	gameObjects.push_back(new GameObject("media/Sydney.md2", "media/sydney.bmp", -100, 0, -100, 0, 0, 0, 3.0, 3.0, 3.0, 0, 1, 1, false, true));

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
	gameObjects.push_back(new GameObject("media/projector.obj", "media/door.bmp", 0, 160, 0, -180, 90, 0, 1.5, 1.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/projectorScreen.obj", "media/door.bmp", -330, 110, 0, 0, -90, 0, 0.3, 0.3, 0.3, 0, 1, 0, false, false));

	//cupboards
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 140, 100, -576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 0, 100, -576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", -140, 100, -576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 140, 100, 576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", 0, 100, 576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/cupboard.obj", "", -140, 100, 576, 0, 0, 0, 4.0, 4.0, 2.0, 0, 1, 1, false, false));

	//tables, lecterns and lectern-top objects
	gameObjects.push_back(new GameObject("media/desalto_bend_in_obj.obj", "media/WhiteTabletop.bmp", -80, -80, 200, 0, 90, 0, 1, 1, 1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/desalto_bend_in_obj.obj", "media/WhiteTabletop.bmp", -0, -80, -200, 0, 90, 0, 1, 1, 1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/lecturn.obj", "media/WhiteTabletop.bmp", 180, -86, 200, 0, 0, 0, 3, 4, 6, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/marker.obj", "", 180, -31, 160, 0, 0, 0, 1, 1, 1, 0, 1, 1, false, false));

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
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -450, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -520, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, -270, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, -300, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, -340, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -340, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -400, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, -150, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, -180, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, -220, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -220, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -280, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, -30, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, -60, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, -100, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, -100, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, 240, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 490, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 470, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 430, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 440, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, 120, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 370, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 350, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 310, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 320, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, 0, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 250, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 230, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 190, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 200, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	gameObjects.push_back(new GameObject("media/monitor.obj", "", -330, 75, -120, 0, 90, 0, 0.1, 0.1, 0.1, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/tower.obj", "", -320, -13, 130, 0, 90, 0, 1.5, 2, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/mouse.obj", "", -290, -13, 110, 0, 90, 0, 3, 3, 3, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/keyboard.obj", "", -300, -13, 70, 0, 90, 0, 1.5, 0.5, 1.5, 0, 1, 0, false, false));
	gameObjects.push_back(new GameObject("media/Office_chair_obj/Office_chair.obj", "", -260, -85, 80, 0, 90, 0, 0.1, 0.1, 0.1, 0.003, 1, 1, false, false));
	
	int i = 0;
	for (i = 0; i < gameObjects.size(); i++){
		IAnimatedMesh* temp = smgr->getMesh(gameObjects[i]->getMesh().c_str());
		
		float ptm = gameObjects[i]->getPTM();
		if(ptm != 0){
			smgr->getMeshManipulator()->makePlanarTextureMapping(temp->getMesh(0), ptm);
		}
		if (!temp)
		{
			device->drop();
			return 1;
		}
		
		IAnimatedMeshSceneNode* tempContainer = smgr->addAnimatedMeshSceneNode(temp, 0, gameObjects[i]->getPickable());
		if (tempContainer)
		{
			tempContainer->setMaterialFlag(EMF_LIGHTING, false);
			if(gameObjects[i]->getPTM() == 1){
				tempContainer->setMD2Animation(scene::EMAT_STAND);
			}
			if(gameObjects[i]->getTex() != ""){
				tempContainer->setMaterialTexture(0, driver->getTexture(gameObjects[i]->getTex().c_str()));
			}
			tempContainer->setScale(gameObjects[i]->getScaleVector());
			tempContainer->setPosition(gameObjects[i]->getPosVector());

			if (gameObjects[i]->getInteractible()) {
				//object in NPC
				gameObjects[i]->initEmotions();
			}

			if(gameObjects[i]->getPickable() != 0){
				scene::ITriangleSelector* selector = smgr->createTriangleSelector(temp, tempContainer);
				tempContainer->setTriangleSelector(selector);
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

	device->getCursorControl()->setVisible(false);

	int lastFPS = -1;

	while (device->run())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, SColor(255, 100, 101, 140));



			smgr->drawAll();
			//guienv->drawAll();
			ThisHud.Update();

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
