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

	int i = 0;
	for (i = 0; i < gameObjects.size(); i++){
		IAnimatedMesh* temp = smgr->getMesh(gameObjects[i]->getMesh().c_str());
		
		ptm = gameObjects[i]->getPTM();
		if(ptm != 0){
			smgr->getMeshManipulator()->makePlanarTextureMapping(temp->getMesh(0), ptm);
		}
		if (!temp)
		{
			device->drop();
			return 1;
		}
		
		IAnimatedMeshSceneNode* tempContainer = 0;
		
		switch (gameObjects[i]->getPickable()) {
			case 0:
				tempContainer = smgr->addAnimatedMeshSceneNode(temp, 0, ID_IsNotPickable);
				break;
			case 1:
				tempContainer = smgr->addAnimatedMeshSceneNode(temp, 0, IDFlag_IsPickable);
				break;
			case 2:
				tempContainer = smgr->addAnimatedMeshSceneNode(temp, 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
				break;
			default:
				tempContainer = smgr->addAnimatedMeshSceneNode(temp);
				break;
		}

		if (tempContainer != 0)
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
			tempContainer->setRotation(gameObjects[i]->getRotVector());

			if (gameObjects[i]->getAnim() == 1) {
				tempContainer->setMD2Animation(scene::EMAT_STAND);
			}

			if (gameObjects[i]->getInteractible()) {
				//object in NPC
				gameObjects[i]->initEmotions();
				scene::ITriangleSelector* tempselector = smgr->createTriangleSelector(tempContainer);
				tempContainer->setTriangleSelector(tempselector);
				tempselector->drop();
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

	core::map<ISceneNode*, GameObject*> objectByNode;
	objectByNode.clear();

	//NPCs done separately for interaction purposes
	GameObject* NPC1 = new GameObject("media/Sydney.md2", "media/sydney.bmp", -100, 0, -100, 0, 0, 0, 3.0, 3.0, 3.0, 0, 1, 1, 2, false, true);
	IAnimatedMesh* NPC1m = smgr->getMesh(NPC1->getMesh().c_str());

	ptm = NPC1->getPTM();
	if (ptm != 0) {
		smgr->getMeshManipulator()->makePlanarTextureMapping(NPC1m->getMesh(0), ptm);
	}
	if (!NPC1m)
	{
		device->drop();
		return 1;
	}

	IAnimatedMeshSceneNode* NPC1n = 0;

	switch (NPC1->getPickable()) {
	case 0:
		NPC1n = smgr->addAnimatedMeshSceneNode(NPC1m, 0, ID_IsNotPickable);
		break;
	case 1:
		NPC1n = smgr->addAnimatedMeshSceneNode(NPC1m, 0, IDFlag_IsPickable);
		break;
	case 2:
		NPC1n = smgr->addAnimatedMeshSceneNode(NPC1m, 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
		break;
	default:
		NPC1n = smgr->addAnimatedMeshSceneNode(NPC1m);
		break;
	}

	if (NPC1n != 0)
	{
		objectByNode.insert(NPC1n, NPC1);
		NPC1n->setMaterialFlag(EMF_LIGHTING, false);
		if (NPC1->getPTM() == 1) {
			NPC1n->setMD2Animation(scene::EMAT_STAND);
		}
		if (NPC1->getTex() != "") {
			NPC1n->setMaterialTexture(0, driver->getTexture(NPC1->getTex().c_str()));
		}
		NPC1n->setScale(NPC1->getScaleVector());
		NPC1n->setPosition(NPC1->getPosVector());
		NPC1n->setRotation(NPC1->getRotVector());

		if (NPC1->getAnim() == 1) {
			NPC1n->setMD2Animation(scene::EMAT_STAND);
		}

		if (NPC1->getInteractible()) {
			//object in NPC
			NPC1->initEmotions();
			scene::ITriangleSelector* tempselector = smgr->createTriangleSelector(NPC1n);
			NPC1n->setTriangleSelector(tempselector);
			tempselector->drop();
		}

		if (NPC1->getPickable() != 0) {
			scene::ITriangleSelector* selector = smgr->createTriangleSelector(NPC1m, NPC1n);
			NPC1n->setTriangleSelector(selector);
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
	GameObject* NPC2 = new GameObject("media/Sydney.md2", "media/sydney.bmp", 100, 0, 100, 0, 0, 0, 3.0, 3.0, 3.0, 0, 1, 1, 2, false, true);
	IAnimatedMesh* NPC2m = smgr->getMesh(NPC2->getMesh().c_str());

	ptm = NPC2->getPTM();
	if (ptm != 0) {
		smgr->getMeshManipulator()->makePlanarTextureMapping(NPC2m->getMesh(0), ptm);
	}
	if (!NPC2m)
	{
		device->drop();
		return 1;
	}

	IAnimatedMeshSceneNode* NPC2n = 0;

	switch (NPC2->getPickable()) {
	case 0:
		NPC2n = smgr->addAnimatedMeshSceneNode(NPC2m, 0, ID_IsNotPickable);
		break;
	case 1:
		NPC2n = smgr->addAnimatedMeshSceneNode(NPC2m, 0, IDFlag_IsPickable);
		break;
	case 2:
		NPC2n = smgr->addAnimatedMeshSceneNode(NPC2m, 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
		break;
	default:
		NPC2n = smgr->addAnimatedMeshSceneNode(NPC2m);
		break;
	}

	if (NPC2n != 0)
	{
		objectByNode.insert(NPC2n, NPC2);
		NPC2n->setMaterialFlag(EMF_LIGHTING, false);
		if (NPC2->getPTM() == 1) {
			NPC2n->setMD2Animation(scene::EMAT_STAND);
		}
		if (NPC2->getTex() != "") {
			NPC2n->setMaterialTexture(0, driver->getTexture(NPC2->getTex().c_str()));
		}
		NPC2n->setScale(NPC2->getScaleVector());
		NPC2n->setPosition(NPC2->getPosVector());
		NPC2n->setRotation(NPC2->getRotVector());

		if (NPC2->getAnim() == 1) {
			NPC2n->setMD2Animation(scene::EMAT_STAND);
		}

		if (NPC2->getInteractible()) {
			//object in NPC
			NPC2->initEmotions();
			scene::ITriangleSelector* tempselector = smgr->createTriangleSelector(NPC2n);
			NPC2n->setTriangleSelector(tempselector);
			tempselector->drop();
		}

		if (NPC2->getPickable() != 0) {
			scene::ITriangleSelector* selector = smgr->createTriangleSelector(NPC2m, NPC2n);
			NPC2n->setTriangleSelector(selector);
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
	GameObject* NPC3 = new GameObject("media/Sydney.md2", "media/sydney.bmp", -100, 0, 100, 0, 0, 0, 3.0, 3.0, 3.0, 0, 1, 1, 2, false, true);
	IAnimatedMesh* NPC3m = smgr->getMesh(NPC3->getMesh().c_str());

	ptm = NPC3->getPTM();
	if (ptm != 0) {
		smgr->getMeshManipulator()->makePlanarTextureMapping(NPC3m->getMesh(0), ptm);
	}
	if (!NPC3m)
	{
		device->drop();
		return 1;
	}

	IAnimatedMeshSceneNode* NPC3n = 0;

	switch (NPC3->getPickable()) {
	case 0:
		NPC3n = smgr->addAnimatedMeshSceneNode(NPC3m, 0, ID_IsNotPickable);
		break;
	case 1:
		NPC3n = smgr->addAnimatedMeshSceneNode(NPC3m, 0, IDFlag_IsPickable);
		break;
	case 2:
		NPC3n = smgr->addAnimatedMeshSceneNode(NPC3m, 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
		break;
	default:
		NPC3n = smgr->addAnimatedMeshSceneNode(NPC3m);
		break;
	}

	if (NPC3n != 0)
	{
		objectByNode.insert(NPC3n, NPC3);
		NPC3n->setMaterialFlag(EMF_LIGHTING, false);
		if (NPC3->getPTM() == 1) {
			NPC3n->setMD2Animation(scene::EMAT_STAND);
		}
		if (NPC3->getTex() != "") {
			NPC3n->setMaterialTexture(0, driver->getTexture(NPC3->getTex().c_str()));
		}
		NPC3n->setScale(NPC3->getScaleVector());
		NPC3n->setPosition(NPC3->getPosVector());
		NPC3n->setRotation(NPC3->getRotVector());

		if (NPC3->getAnim() == 1) {
			NPC3n->setMD2Animation(scene::EMAT_STAND);
		}

		if (NPC3->getInteractible()) {
			//object in NPC
			NPC3->initEmotions();
			scene::ITriangleSelector* tempselector = smgr->createTriangleSelector(NPC3n);
			NPC3n->setTriangleSelector(tempselector);
			tempselector->drop();
		}

		if (NPC3->getPickable() != 0) {
			scene::ITriangleSelector* selector = smgr->createTriangleSelector(NPC3m, NPC3n);
			NPC3n->setTriangleSelector(selector);
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
	int tempflag = 0;


	while (device->run())
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, SColor(255, 100, 101, 140));

			smgr->drawAll();
			//guienv->drawAll();
			ThisHud.Update();

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

					targetObject = (GameObject*)objectByNode.find(highlightedSceneNode);

					//if object exists and is interactible, do stuff
					if (targetObject) {
						if (tempflag == 0) {
							std::cout << "target exists as game object" << std::endl;
							tempflag = 1;
						}
						
						bill->setPosition(intersection);

						//if 'J' key pressed, change joy
						if (receiver.IsKeyDown(KEY_KEY_J)) {
							std::cout << "J-key pressed!" << std::endl;
							//increase joy by 5
							targetObject->changeEmotion(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

							if (targetObject->getEmotionResponse() == 1) {
								std::cout << "Emotion Response received!" << std::endl;
							}
						}
					}
					else {
						std::cout << "no target found" << std::endl;
					}
				}
				else {
					tempflag = 0;
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
