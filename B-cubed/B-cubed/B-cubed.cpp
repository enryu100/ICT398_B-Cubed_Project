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

	vector<GameObject> gameObjects;

	gameObjects.push_back(GameObject("media/Sydney.md2", "media/sydney.bmp", -100, 0, -100, 0, 0, 0, 3.0, 3.0, 3.0, 1, 0, false, true));

	
	IAnimatedMesh* sydney = smgr->getMesh(gameObjects[0].getMesh().c_str());
	if (!sydney)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* whiteboard = smgr->getMesh("media/whiteBoard.obj");
	if (!whiteboard)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* ceiling = smgr->getMesh("media/roof.obj");
	if (!ceiling)
	{
		device->drop();
		return 1;
	}

	IAnimatedMesh* windowLeft = smgr->getMesh("media/windowLeft.obj");
	if (!windowLeft)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* windowRight = smgr->getMesh("media/windowRight.obj");
	if (!windowRight)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* windowCenter = smgr->getMesh("media/windowCenter.obj");
	if (!windowCenter)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* backWall = smgr->getMesh("media/backWall.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(backWall->getMesh(0), 0.002f);
	if (!backWall)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* farWall = smgr->getMesh("media/farWall.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(farWall->getMesh(0), 0.003f);
	if (!farWall)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* leftWall = smgr->getMesh("media/leftWall.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(leftWall->getMesh(0), 0.003f);
	if (!leftWall)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* rightWall = smgr->getMesh("media/rightWall.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(rightWall->getMesh(0), 0.003f);
	if (!rightWall)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* floor = smgr->getMesh("media/floor.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(floor->getMesh(0), 0.003f);
	if (!floor)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* benchRight = smgr->getMesh("media/benchRight.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(benchRight->getMesh(0), 0.003f);
	if (!benchRight)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* benchLeft = smgr->getMesh("media/benchLeft.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(benchLeft->getMesh(0), 0.003f);
	if (!benchLeft)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* benchCenter = smgr->getMesh("media/benchCenter.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(benchCenter->getMesh(0), 0.003f);
	if (!benchCenter)
	{
		device->drop();
		return 1;
	}

	IAnimatedMesh* door = smgr->getMesh("media/door.obj");
	if (!door)
	{
		device->drop();
		return 1;
	}

	IAnimatedMesh* pcChair1 = smgr->getMesh("media/Office_chair_obj/Office_chair.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(pcChair1->getMesh(0), 0.003f);
	if (!pcChair1)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* table = smgr->getMesh("media/desalto_bend_in_obj.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(table->getMesh(0), 0.003f);
	if (!table)
	{
		device->drop();
		return 1;
	}

	IAnimatedMesh* projector = smgr->getMesh("media/projector.obj");
	if (!projector)
	{
		device->drop();
		return 1;
	}


	IAnimatedMesh* monitor = smgr->getMesh("media/monitor.obj");
	if (!monitor)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* keyboard = smgr->getMesh("media/keyboard.obj");
	if (!keyboard)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* marker = smgr->getMesh("media/marker.obj");
	if (!marker)
	{
		device->drop();
		return 1;
	}

	IAnimatedMesh* pscreen = smgr->getMesh("media/projectorScreen.obj");
	if (!pscreen)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* tower = smgr->getMesh("media/tower.obj");
	if (!tower)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* mouse = smgr->getMesh("media/mouse.obj");
	if (!mouse)
	{
		device->drop();
		return 1;
	}
	IAnimatedMesh* cupboard = smgr->getMesh("media/cupboard.obj");
	if (!cupboard)
	{
		device->drop();
		return 1;
	}

	IAnimatedMesh* lecturn = smgr->getMesh("media/lecturn.obj");
	smgr->getMeshManipulator()->makePlanarTextureMapping(lecturn->getMesh(0), 0.003f);
	if (!lecturn)
	{
		device->drop();
		return 1;
	}
	IMeshSceneNode * ceilingContainer = smgr->addMeshSceneNode(ceiling);
	IMeshSceneNode * whiteboardContainer = smgr->addMeshSceneNode(whiteboard, 0, IDFlag_IsPickable);
	 IMeshSceneNode * windowLeftContainer = smgr->addMeshSceneNode(windowLeft, 0, IDFlag_IsPickable);
	 IMeshSceneNode * windowRightContainer = smgr->addMeshSceneNode(windowRight, 0, IDFlag_IsPickable);
	 IMeshSceneNode * windowCenterContainer = smgr->addMeshSceneNode(windowCenter, 0, IDFlag_IsPickable);
	 IMeshSceneNode * backWallContainer = smgr->addMeshSceneNode(backWall, 0, IDFlag_IsPickable);
	 IMeshSceneNode * farWallContainer = smgr->addMeshSceneNode(farWall, 0, IDFlag_IsPickable);
	 IMeshSceneNode * leftWallContainer = smgr->addMeshSceneNode(leftWall, 0, IDFlag_IsPickable);
	 IMeshSceneNode * rightWallContainer = smgr->addMeshSceneNode(rightWall, 0, IDFlag_IsPickable);
	 IMeshSceneNode * FloorContainer = smgr->addMeshSceneNode(floor, 0, IDFlag_IsPickable);
	 IMeshSceneNode * benchLeftContainer = smgr->addMeshSceneNode(benchLeft);
	 IMeshSceneNode * benchRightContainer = smgr->addMeshSceneNode(benchRight, 0, IDFlag_IsPickable);
	 IMeshSceneNode * benchCenterContainer = smgr->addMeshSceneNode(benchCenter, 0, IDFlag_IsPickable);
	 IMeshSceneNode * doorContainer = smgr->addMeshSceneNode(door, 0, IDFlag_IsPickable);
	 IMeshSceneNode * tableContainer = smgr->addMeshSceneNode(table, 0, IDFlag_IsPickable);
	 IMeshSceneNode * tableContainer2 = smgr->addMeshSceneNode(table, 0, IDFlag_IsPickable);
	 IAnimatedMeshSceneNode* sydneyContainer = smgr->addAnimatedMeshSceneNode(sydney, 0, gameObjects[0].getPickable());
	 
	 IMeshSceneNode * projectorContainer = smgr->addMeshSceneNode(projector);
	 IMeshSceneNode * pscreenContainer = smgr->addMeshSceneNode(pscreen, 0, IDFlag_IsPickable);
	 IMeshSceneNode * markerContainer1 = smgr->addMeshSceneNode(marker);

	 IMeshSceneNode * chairContainer1 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer1 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer2 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer2 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer2 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer2 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer2 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer3 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer3 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer3 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer3 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer3 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer4 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer4 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer4 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer4 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer4 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer5 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer5 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer5 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer5 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer5 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer6 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer6 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer6 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer6 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer6 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer7 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer7 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer7 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer7 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer7 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer8 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer8 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer8 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer8 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer8 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer9 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer9 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer9 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer9 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer9 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer10 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer10 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer10 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer10 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer10 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer11 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer11 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer11 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer11 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer11 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer12 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer12 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer12 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer12 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer12 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer13 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer13 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer13 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer13 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer13 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer14 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer14 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer14 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer14 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer14 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer15 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer15 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer15 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer15 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer15 = smgr->addMeshSceneNode(mouse);

	 IMeshSceneNode * chairContainer16 = smgr->addMeshSceneNode(pcChair1, 0, IDFlag_IsPickable);
	 IMeshSceneNode * monitorContainer16 = smgr->addMeshSceneNode(monitor);
	 IMeshSceneNode * keyboardContainer16 = smgr->addMeshSceneNode(keyboard);
	 IMeshSceneNode * towerContainer16 = smgr->addMeshSceneNode(tower);
	 IMeshSceneNode * mouseContainer16 = smgr->addMeshSceneNode(mouse);


	 IMeshSceneNode * cupboardContainer = smgr->addMeshSceneNode(cupboard, 0, IDFlag_IsPickable);
	 IMeshSceneNode * cupboardContainer2 = smgr->addMeshSceneNode(cupboard, 0, IDFlag_IsPickable);
	 IMeshSceneNode * cupboardContainer3 = smgr->addMeshSceneNode(cupboard, 0, IDFlag_IsPickable);
	 IMeshSceneNode * cupboardContainer4 = smgr->addMeshSceneNode(cupboard, 0, IDFlag_IsPickable);
	 IMeshSceneNode * cupboardContainer5 = smgr->addMeshSceneNode(cupboard, 0, IDFlag_IsPickable);
	 IMeshSceneNode * cupboardContainer6 = smgr->addMeshSceneNode(cupboard, 0, IDFlag_IsPickable);
	 IMeshSceneNode * lecturnContainer = smgr->addMeshSceneNode(lecturn, 0, IDFlag_IsPickable);

	 if (ceilingContainer)
	 {
		 ceilingContainer->setMaterialFlag(EMF_LIGHTING, false);
		 
		 ceilingContainer->setPosition(vector3df(0, 0, 0));
		 
	 }
	 if (windowLeftContainer)
	 {
		 windowLeftContainer->setMaterialFlag(EMF_LIGHTING, false);
		 //windowLeftContainer->setMaterialTexture(0, driver->getTexture("media/window.bmp"));
		 windowLeftContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorWL = smgr->createTriangleSelector(windowLeft, windowLeftContainer);
		 windowLeftContainer->setTriangleSelector(selectorWL);
		 if (selectorWL)
		 {
			 scene::ISceneNodeAnimator* animWl = smgr->createCollisionResponseAnimator(
				 selectorWL, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorWL->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animWl);
			 animWl->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (windowRightContainer)
	 {
		 windowRightContainer->setMaterialFlag(EMF_LIGHTING, false);
		 //windowRightContainer->setMaterialTexture(0, driver->getTexture("media/window.bmp"));
		 windowLeftContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorWR = smgr->createTriangleSelector(windowRight, windowRightContainer);
		 windowRightContainer->setTriangleSelector(selectorWR);
		 if (selectorWR)
		 {
			 scene::ISceneNodeAnimator* animWr = smgr->createCollisionResponseAnimator(
				 selectorWR, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorWR->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animWr);
			 animWr->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (windowCenterContainer)
	 {
		 windowCenterContainer->setMaterialFlag(EMF_LIGHTING, false);
		 //windowCenterContainer->setMaterialTexture(0, driver->getTexture("media/window.bmp"));
		 windowCenterContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorWC = smgr->createTriangleSelector(windowCenter, windowCenterContainer);
		 windowCenterContainer->setTriangleSelector(selectorWC);
		 if (selectorWC)
		 {
			 scene::ISceneNodeAnimator* animWc = smgr->createCollisionResponseAnimator(
				 selectorWC, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorWC->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animWc);
			 animWc->drop();  // And likewise, drop the animator when we're done referring to it.
		 }

	 }
	 if (backWallContainer)
	 {
		 backWallContainer->setMaterialFlag(EMF_LIGHTING, false);
		 backWallContainer->setMaterialTexture(0, driver->getTexture("media/redBackWall.bmp"));
		 backWallContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorBW = smgr->createTriangleSelector(backWall, backWallContainer);
		 backWallContainer->setTriangleSelector(selectorBW);
		 if (selectorBW)
		 {
			 scene::ISceneNodeAnimator* animBw = smgr->createCollisionResponseAnimator(
				 selectorBW, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorBW->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animBw);
			 animBw->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (farWallContainer)
	 {
		 farWallContainer->setMaterialFlag(EMF_LIGHTING, false);
		 
		 farWallContainer->setMaterialTexture(0, driver->getTexture("media/farWall.bmp"));
		 farWallContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorFW = smgr->createTriangleSelector(farWall, farWallContainer);
		 farWallContainer->setTriangleSelector(selectorFW);
		 if (selectorFW)
		 {
			 scene::ISceneNodeAnimator* animFw = smgr->createCollisionResponseAnimator(
				 selectorFW, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorFW->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animFw);
			 animFw->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (leftWallContainer)
	 {
		 leftWallContainer->setMaterialFlag(EMF_LIGHTING, false);
		 leftWallContainer->setMaterialTexture(0, driver->getTexture("media/redWall.bmp"));
		 leftWallContainer->setPosition(vector3df(0, 0, 0)); 

		 scene::ITriangleSelector* selectorLW = smgr->createTriangleSelector(leftWall, leftWallContainer);
		 leftWallContainer->setTriangleSelector(selectorLW);
		 if (selectorLW)
		 {
			 scene::ISceneNodeAnimator* animLw = smgr->createCollisionResponseAnimator(
				 selectorLW, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorLW->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animLw);
			 animLw->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (rightWallContainer)
	 {
		 rightWallContainer->setMaterialFlag(EMF_LIGHTING, false);
		 rightWallContainer->setMaterialTexture(0, driver->getTexture("media/redWall.bmp"));
		 rightWallContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorRW = smgr->createTriangleSelector(rightWall, rightWallContainer);
		 rightWallContainer->setTriangleSelector(selectorRW);
		 if (selectorRW)
		 {
			 scene::ISceneNodeAnimator* animRw = smgr->createCollisionResponseAnimator(
				 selectorRW, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorRW->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animRw);
			 animRw->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (FloorContainer)
	 {
		 FloorContainer->setMaterialFlag(EMF_LIGHTING, false);
		 FloorContainer->setMaterialTexture(0, driver->getTexture("media/Navy-Blue-Carpet.bmp"));
		 FloorContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorF = smgr->createTriangleSelector(smgr->getMesh("media/floor.obj"), FloorContainer);
		 FloorContainer->setTriangleSelector(selectorF);
		 if (selectorF)
		 {
			 scene::ISceneNodeAnimator* animF = smgr->createCollisionResponseAnimator(
				 selectorF, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 80, 0));
			 selectorF->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animF);
			 animF->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (benchLeftContainer)
	 {
		 benchLeftContainer->setMaterialFlag(EMF_LIGHTING, false);
		 benchLeftContainer->setMaterialTexture(0, driver->getTexture("media/WhiteTabletop.bmp"));
		 benchLeftContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorBL = smgr->createTriangleSelector(benchLeft, benchLeftContainer);
		 benchLeftContainer->setTriangleSelector(selectorBL);
		 if (selectorBL)
		 {
			 scene::ISceneNodeAnimator* animBl = smgr->createCollisionResponseAnimator(
				 selectorBL, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorBL->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animBl);
			 animBl->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (benchRightContainer)
	 {
		 benchRightContainer->setMaterialFlag(EMF_LIGHTING, false);

		 benchRightContainer->setMaterialTexture(0, driver->getTexture("media/WhiteTabletop.bmp"));
		 benchRightContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorBR = smgr->createTriangleSelector(benchRight, benchRightContainer);
		 benchRightContainer->setTriangleSelector(selectorBR);
		 if (selectorBR)
		 {
			 scene::ISceneNodeAnimator* animBr = smgr->createCollisionResponseAnimator(
				 selectorBR, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorBR->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animBr);
			 animBr->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (benchCenterContainer)
	 {
		 benchCenterContainer->setMaterialFlag(EMF_LIGHTING, false);
		 benchCenterContainer->setMaterialTexture(0, driver->getTexture("media/WhiteTabletop.bmp"));
		 benchCenterContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorBC = smgr->createTriangleSelector(benchCenter, benchCenterContainer);
		 windowLeftContainer->setTriangleSelector(selectorBC);
		 if (selectorBC)
		 {
			 scene::ISceneNodeAnimator* animBc = smgr->createCollisionResponseAnimator(
				 selectorBC, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorBC->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animBc);
			 animBc->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }

	 if (doorContainer)
	 {
		 doorContainer->setMaterialFlag(EMF_LIGHTING, false);
		 doorContainer->setMaterialTexture(0, driver->getTexture("media/door.bmp"));
		 doorContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorD = smgr->createTriangleSelector(door, doorContainer);
		 doorContainer->setTriangleSelector(selectorD);
		 if (selectorD)
		 {
			 scene::ISceneNodeAnimator* animD = smgr->createCollisionResponseAnimator(
				 selectorD, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorD->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animD);
			 animD->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	 if (whiteboardContainer)
	 {
		 whiteboardContainer->setMaterialFlag(EMF_LIGHTING, false);
		 whiteboardContainer->setPosition(vector3df(0, 0, 0));

		 scene::ITriangleSelector* selectorWB = smgr->createTriangleSelector(whiteboard, whiteboardContainer);
		 whiteboardContainer->setTriangleSelector(selectorWB);
		 if (selectorWB)
		 {
			 scene::ISceneNodeAnimator* animWb = smgr->createCollisionResponseAnimator(
				 selectorWB, camera, core::vector3df(30, 1000, 30),
				 core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			 selectorWB->drop(); // As soon as we're done with the selector, drop it.
			 camera->addAnimator(animWb);
			 animWb->drop();  // And likewise, drop the animator when we're done referring to it.
		 }
	 }
	if (sydneyContainer)
	{
		sydneyContainer->setMaterialFlag(EMF_LIGHTING, false);
		sydneyContainer->setMD2Animation(scene::EMAT_STAND);
		sydneyContainer->setMaterialTexture(0, driver->getTexture(gameObjects[0].getTex().c_str()));
		sydneyContainer->setScale(gameObjects[0].getScaleVector());
		sydneyContainer->setPosition(gameObjects[0].getPosVector());

		scene::ITriangleSelector* selector = smgr->createTriangleSelector(sydney, sydneyContainer);
		sydneyContainer->setTriangleSelector(selector);
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

	
	
	if (tableContainer)
	{
		tableContainer->setMaterialFlag(EMF_LIGHTING, false);
		tableContainer->setMaterialTexture(0, driver->getTexture("media/WhiteTabletop.bmp"));
		//tableContainer->setScale(vector3df(2.0, 2.0, 2.0));
		tableContainer->setPosition(vector3df(-80, -80, 200));
		vector3df roty = tableContainer->getRotation();
		roty.Y += 90;
		tableContainer->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorT = smgr->createTriangleSelector(table, tableContainer);
		tableContainer->setTriangleSelector(selectorT);
		if (selectorT)
		{
			scene::ISceneNodeAnimator* animT = smgr->createCollisionResponseAnimator(
				selectorT, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorT->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animT);
			animT->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (tableContainer2)
	{
		tableContainer2->setMaterialFlag(EMF_LIGHTING, false);
		tableContainer2->setMaterialTexture(0, driver->getTexture("media/WhiteTabletop.bmp"));
		//tableContainer->setScale(vector3df(2.0, 2.0, 2.0));
		tableContainer2->setPosition(vector3df(0, -80, -200));
		
		scene::ITriangleSelector* selectorT2 = smgr->createTriangleSelector(table, tableContainer2);
		tableContainer2->setTriangleSelector(selectorT2);
		if (selectorT2)
		{
			scene::ISceneNodeAnimator* animT2 = smgr->createCollisionResponseAnimator(
				selectorT2, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorT2->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animT2);
			animT2->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	
	if (projectorContainer)
	{
		projectorContainer->setMaterialFlag(EMF_LIGHTING, false);
		projectorContainer->setScale(vector3df(1.5, 1.5, 1.5));
		projectorContainer->setPosition(vector3df(0, 160, 0));
		
		vector3df rotx = projectorContainer->getRotation();
		
		rotx.X -= 180;
		//
		projectorContainer->setRotation(vector3df(rotx));
		vector3df roty = projectorContainer->getRotation();
		roty.Y += 90;
		projectorContainer->setRotation(vector3df(roty));
	}

	

	
	

	if (pscreenContainer)
	{
		pscreenContainer->setMaterialFlag(EMF_LIGHTING, false);

		pscreenContainer->setScale(vector3df(0.3, 0.3, 0.3));
		pscreenContainer->setPosition(vector3df(-330, 110, 0));
		vector3df roty = pscreenContainer->getRotation();
		roty.Y -= 90;
		pscreenContainer->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorPS = smgr->createTriangleSelector(pscreen, pscreenContainer);
		pscreenContainer->setTriangleSelector(selectorPS);
		if (selectorPS)
		{
			scene::ISceneNodeAnimator* animPs = smgr->createCollisionResponseAnimator(
				selectorPS, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorPS->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animPs);
			animPs->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}


	if (monitorContainer)
	{
		monitorContainer->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer->setPosition(vector3df(440, 75, -578));
	}
	if (towerContainer)
	{
		towerContainer->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer->setScale(vector3df(1.5, 2, 1.5));
		towerContainer->setPosition(vector3df(190, -13, -560));
		
	}
	if (mouseContainer)
	{
		mouseContainer->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer->setScale(vector3df(3, 3, 3));
		mouseContainer->setPosition(vector3df(220, -13, -540));

	}
	if (keyboardContainer1)
	{
		keyboardContainer1->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer1->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer1->setPosition(vector3df(270, -13, -550));
	}
	if (chairContainer1)
	{
		chairContainer1->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer1->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer1->setPosition(vector3df(250, -85, -500));

		vector3df roty = chairContainer1->getRotation();
		roty.Y -= 180;
		chairContainer1->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC1 = smgr->createTriangleSelector(pcChair1, chairContainer1);
		chairContainer1->setTriangleSelector(selectorC1);
		if (selectorC1)
		{
			scene::ISceneNodeAnimator* animC1 = smgr->createCollisionResponseAnimator(
				selectorC1, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC1->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC1);
			animC1->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (monitorContainer2)
	{
		monitorContainer2->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer2->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer2->setPosition(vector3df(290, 75, -578));
	}
	if (towerContainer2)
	{
		towerContainer2->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer2->setScale(vector3df(1.5, 2, 1.5));
		towerContainer2->setPosition(vector3df(40, -13, -560));

	}
	if (mouseContainer2)
	{
		mouseContainer2->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer2->setScale(vector3df(3, 3, 3));
		mouseContainer2->setPosition(vector3df(70, -13, -540));

	}
	if (keyboardContainer2)
	{
		keyboardContainer2->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer2->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer2->setPosition(vector3df(120, -13, -550));
	}
	if (chairContainer2)
	{
		chairContainer2->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer2->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer2->setPosition(vector3df(100, -85, -500));

		vector3df roty = chairContainer2->getRotation();
		roty.Y -= 180;
		chairContainer2->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC2 = smgr->createTriangleSelector(pcChair1, chairContainer2);
		chairContainer2->setTriangleSelector(selectorC2);
		if (selectorC2)
		{
			scene::ISceneNodeAnimator* animC2 = smgr->createCollisionResponseAnimator(
				selectorC2, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC2->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC2);
			animC2->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}



	if (monitorContainer3)
	{
		monitorContainer3->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer3->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer3->setPosition(vector3df(0, 75, -578));
	}
	if (towerContainer3)
	{
		towerContainer3->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer3->setScale(vector3df(1.5, 2, 1.5));
		towerContainer3->setPosition(vector3df(-250, -13, -560));

	}
	if (mouseContainer3)
	{
		mouseContainer3->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer3->setScale(vector3df(3, 3, 3));
		mouseContainer3->setPosition(vector3df(-220, -13, -540));

	}
	if (keyboardContainer3)
	{
		keyboardContainer3->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer3->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer3->setPosition(vector3df(-170, -13, -550));
	}
	if (chairContainer3)
	{
		chairContainer3->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer3->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer3->setPosition(vector3df(-180, -85, -500));

		vector3df roty = chairContainer3->getRotation();
		roty.Y -= 180;
		chairContainer3->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC3 = smgr->createTriangleSelector(pcChair1, chairContainer3);
		chairContainer3->setTriangleSelector(selectorC3);
		if (selectorC3)
		{
			scene::ISceneNodeAnimator* animC3 = smgr->createCollisionResponseAnimator(
				selectorC3, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC3->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC3);
			animC3->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (monitorContainer4)
	{
		monitorContainer4->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer4->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer4->setPosition(vector3df(150, 75, -578));
	}
	if (towerContainer4)
	{
		towerContainer4->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer4->setScale(vector3df(1.5, 2, 1.5));
		towerContainer4->setPosition(vector3df(-120, -13, -560));

	}
	if (mouseContainer4)
	{
		mouseContainer4->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer4->setScale(vector3df(3, 3, 3));
		mouseContainer4->setPosition(vector3df(-90, -13, -540));

	}
	if (keyboardContainer4)
	{
		keyboardContainer4->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer4->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer4->setPosition(vector3df(-40, -13, -550));
	}
	if (chairContainer4)
	{
		chairContainer4->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer4->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer4->setPosition(vector3df(-50, -85, -500));

		vector3df roty = chairContainer4->getRotation();
		roty.Y -= 180;
		chairContainer4->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC4 = smgr->createTriangleSelector(pcChair1, chairContainer4);
		chairContainer4->setTriangleSelector(selectorC4);
		if (selectorC4)
		{
			scene::ISceneNodeAnimator* animC4 = smgr->createCollisionResponseAnimator(
				selectorC4, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC4->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC4);
			animC4->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (monitorContainer5)
	{
		monitorContainer5->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer5->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer5->setPosition(vector3df(70, 75, 578));
		vector3df roty = monitorContainer5->getRotation();
		roty.Y -= 180;
		monitorContainer5->setRotation(vector3df(roty));
	}
	if (towerContainer5)
	{
		towerContainer5->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer5->setScale(vector3df(1.5, 2, 1.5));
		towerContainer5->setPosition(vector3df(190, -13, 560));
		vector3df roty = towerContainer5->getRotation();
		roty.Y -= 180;
		towerContainer5->setRotation(vector3df(roty));
	}
	if (mouseContainer5)
	{
		mouseContainer5->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer5->setScale(vector3df(3, 3, 3));
		mouseContainer5->setPosition(vector3df(290, -13, 540));
		vector3df roty = mouseContainer5->getRotation();
		roty.Y -= 180;
		mouseContainer5->setRotation(vector3df(roty));

	}
	if (keyboardContainer5)
	{
		keyboardContainer5->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer5->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer5->setPosition(vector3df(240, -13, 550));
		vector3df roty = keyboardContainer5->getRotation();
		roty.Y -= 180;
		keyboardContainer5->setRotation(vector3df(roty));
	}
	if (chairContainer5)
	{
		chairContainer5->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer5->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer5->setPosition(vector3df(250, -85, 500));

		scene::ITriangleSelector* selectorC5 = smgr->createTriangleSelector(pcChair1, chairContainer5);
		chairContainer5->setTriangleSelector(selectorC5);
		if (selectorC5)
		{
			scene::ISceneNodeAnimator* animC5 = smgr->createCollisionResponseAnimator(
				selectorC5, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC5->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC5);
			animC5->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (monitorContainer6)
	{
		monitorContainer6->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer6->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer6->setPosition(vector3df(-70, 75, 578));
		vector3df roty = monitorContainer6->getRotation();
		roty.Y -= 180;
		monitorContainer6->setRotation(vector3df(roty));
	}
	if (towerContainer6)
	{
		towerContainer6->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer6->setScale(vector3df(1.5, 2, 1.5));
		towerContainer6->setPosition(vector3df(40, -13, 560));
		vector3df roty = towerContainer6->getRotation();
		roty.Y -= 180;
		towerContainer6->setRotation(vector3df(roty));
	}
	if (mouseContainer6)
	{
		mouseContainer6->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer6->setScale(vector3df(3, 3, 3));
		mouseContainer6->setPosition(vector3df(150, -13, 540));
		vector3df roty = mouseContainer6->getRotation();
		roty.Y -= 180;
		mouseContainer6->setRotation(vector3df(roty));
	}
	if (keyboardContainer6)
	{
		keyboardContainer6->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer6->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer6->setPosition(vector3df(110, -13, 550));
		vector3df roty = keyboardContainer6->getRotation();
		roty.Y -= 180;
		keyboardContainer6->setRotation(vector3df(roty));
	}
	if (chairContainer6)
	{
		chairContainer6->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer6->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer6->setPosition(vector3df(100, -85, 500));

		scene::ITriangleSelector* selectorC6 = smgr->createTriangleSelector(pcChair1, chairContainer6);
		chairContainer6->setTriangleSelector(selectorC6);
		if (selectorC6)
		{
			scene::ISceneNodeAnimator* animC6 = smgr->createCollisionResponseAnimator(
				selectorC6, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC6->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC6);
			animC6->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}



	if (monitorContainer7)
	{
		monitorContainer7->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer7->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer7->setPosition(vector3df(-380, 75, 578));
		vector3df roty = monitorContainer7->getRotation();
		roty.Y -= 180;
		monitorContainer7->setRotation(vector3df(roty));
	}
	if (towerContainer7)
	{
		towerContainer7->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer7->setScale(vector3df(1.5, 2, 1.5));
		towerContainer7->setPosition(vector3df(-250, -13, 560));
		vector3df roty = towerContainer7->getRotation();
		roty.Y -= 180;
		towerContainer7->setRotation(vector3df(roty));

	}
	if (mouseContainer7)
	{
		mouseContainer7->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer7->setScale(vector3df(3, 3, 3));
		mouseContainer7->setPosition(vector3df(-150, -13, 540));
		vector3df roty = mouseContainer7->getRotation();
		roty.Y -= 180;
		mouseContainer7->setRotation(vector3df(roty));

	}
	if (keyboardContainer7)
	{
		keyboardContainer7->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer7->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer7->setPosition(vector3df(-200, -13, 550));
		vector3df roty = keyboardContainer7->getRotation();
		roty.Y -= 180;
		keyboardContainer7->setRotation(vector3df(roty));
	}
	if (chairContainer7)
	{
		chairContainer7->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer7->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer7->setPosition(vector3df(-180, -85, 500));

		scene::ITriangleSelector* selectorC7 = smgr->createTriangleSelector(pcChair1, chairContainer7);
		chairContainer7->setTriangleSelector(selectorC7);
		if (selectorC7)
		{
			scene::ISceneNodeAnimator* animC7 = smgr->createCollisionResponseAnimator(
				selectorC7, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC7->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC7);
			animC7->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (monitorContainer8)
	{
		monitorContainer8->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer8->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer8->setPosition(vector3df(-250, 75, 578));
		vector3df roty = monitorContainer8->getRotation();
		roty.Y -= 180;
		monitorContainer8->setRotation(vector3df(roty));
	}
	if (towerContainer8)
	{
		towerContainer8->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer8->setScale(vector3df(1.5, 2, 1.5));
		towerContainer8->setPosition(vector3df(-120, -13, 560));
		vector3df roty = towerContainer8->getRotation();
		roty.Y -= 180;
		towerContainer8->setRotation(vector3df(roty));
	}
	if (mouseContainer8)
	{
		mouseContainer8->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer8->setScale(vector3df(3, 3, 3));
		mouseContainer8->setPosition(vector3df(-10, -13, 540));
		vector3df roty = mouseContainer8->getRotation();
		roty.Y -= 180;
		mouseContainer8->setRotation(vector3df(roty));
	}
	if (keyboardContainer8)
	{
		keyboardContainer8->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer8->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer8->setPosition(vector3df(-60, -13, 550));
		vector3df roty = keyboardContainer8->getRotation();
		roty.Y -= 180;
		keyboardContainer8->setRotation(vector3df(roty));
	}
	if (chairContainer8)
	{
		chairContainer8->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer8->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer8->setPosition(vector3df(-50, -85, 500));

		//vector3df roty = chairContainer8->getRotation();
		//roty.Y -= 180;
		//chairContainer8->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC8 = smgr->createTriangleSelector(pcChair1, chairContainer8);
		chairContainer7->setTriangleSelector(selectorC8);
		if (selectorC8)
		{
			scene::ISceneNodeAnimator* animC8 = smgr->createCollisionResponseAnimator(
				selectorC8, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC8->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC8);
			animC8->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (monitorContainer9)
	{
		monitorContainer9->setMaterialFlag(EMF_LIGHTING, false);
	
		monitorContainer9->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer9->setPosition(vector3df(-330, 75, -650));
		vector3df roty = monitorContainer9->getRotation();
		roty.Y += 90;
		monitorContainer9->setRotation(vector3df(roty));
	}
	if (towerContainer9)
	{
		towerContainer9->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer9->setScale(vector3df(1.5, 2, 1.5));
		towerContainer9->setPosition(vector3df(-320, -13, -390));
		vector3df roty = towerContainer9->getRotation();
		roty.Y += 90;
		towerContainer9->setRotation(vector3df(roty));
	}
	if (mouseContainer9)
	{
		mouseContainer9->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer9->setScale(vector3df(3, 3, 3));
		mouseContainer9->setPosition(vector3df(-290, -13, -410));
		vector3df roty = mouseContainer9->getRotation();
		roty.Y += 90;
		mouseContainer9->setRotation(vector3df(roty));
	}
	if (keyboardContainer9)
	{
		keyboardContainer9->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer9->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer9->setPosition(vector3df(-300, -13, -450));
		vector3df roty = keyboardContainer9->getRotation();
		roty.Y += 90;
		keyboardContainer9->setRotation(vector3df(roty));
	}
	if (chairContainer9)
	{
		chairContainer9->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer9->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer9->setPosition(vector3df(-260, -85, -450));

		vector3df roty = chairContainer9->getRotation();
		roty.Y -= 90;
		chairContainer9->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC9 = smgr->createTriangleSelector(pcChair1, chairContainer9);
		chairContainer9->setTriangleSelector(selectorC9);
		if (selectorC9)
		{
			scene::ISceneNodeAnimator* animC9 = smgr->createCollisionResponseAnimator(
				selectorC9, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC9->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC9);
			animC9->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (monitorContainer10)
	{
		monitorContainer10->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer10->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer10->setPosition(vector3df(-330, 75, -520));
		vector3df roty = monitorContainer10->getRotation();
		roty.Y += 90;
		monitorContainer10->setRotation(vector3df(roty));
	}
	if (towerContainer10)
	{
		towerContainer10->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer10->setScale(vector3df(1.5, 2, 1.5));
		towerContainer10->setPosition(vector3df(-320, -13, -270));
		vector3df roty = towerContainer10->getRotation();
		roty.Y += 90;
		towerContainer10->setRotation(vector3df(roty));
	}
	if (mouseContainer10)
	{
		mouseContainer10->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer10->setScale(vector3df(3, 3, 3));
		mouseContainer10->setPosition(vector3df(-290, -13, -300));
		vector3df roty = mouseContainer10->getRotation();
		roty.Y += 90;
		mouseContainer10->setRotation(vector3df(roty));
	}
	if (keyboardContainer10)
	{
		keyboardContainer10->setMaterialFlag(EMF_LIGHTING, false);
	
		keyboardContainer10->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer10->setPosition(vector3df(-300, -13, -340));
		vector3df roty = keyboardContainer10->getRotation();
		roty.Y += 90;
		keyboardContainer10->setRotation(vector3df(roty));
	}
	if (chairContainer10)
	{
		chairContainer10->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer10->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer10->setPosition(vector3df(-260, -85, -340));

		vector3df roty = chairContainer10->getRotation();
		roty.Y -= 90;
		chairContainer10->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC10 = smgr->createTriangleSelector(pcChair1, chairContainer10);
		chairContainer10->setTriangleSelector(selectorC10);
		if (selectorC10)
		{
			scene::ISceneNodeAnimator* animC10 = smgr->createCollisionResponseAnimator(
				selectorC10, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC10->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC10);
			animC10->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (monitorContainer11)
	{
		monitorContainer11->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer11->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer11->setPosition(vector3df(-330, 75, -400));
		vector3df roty = monitorContainer11->getRotation();
		roty.Y += 90;
		monitorContainer11->setRotation(vector3df(roty));
	}
	if (towerContainer11)
	{
		towerContainer11->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer11->setScale(vector3df(1.5, 2, 1.5));
		towerContainer11->setPosition(vector3df(-320, -13, -150));
		vector3df roty = towerContainer11->getRotation();
		roty.Y += 90;
		towerContainer11->setRotation(vector3df(roty));
	}
	if (mouseContainer11)
	{
		mouseContainer11->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer11->setScale(vector3df(3, 3, 3));
		mouseContainer11->setPosition(vector3df(-290, -13, -180));
		vector3df roty = mouseContainer11->getRotation();
		roty.Y += 90;
		mouseContainer11->setRotation(vector3df(roty));
	}
	if (keyboardContainer11)
	{
		keyboardContainer11->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer11->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer11->setPosition(vector3df(-300, -13, -220));
		vector3df roty = keyboardContainer11->getRotation();
		roty.Y += 90;
		keyboardContainer11->setRotation(vector3df(roty));
	}
	if (chairContainer11)
	{
		chairContainer11->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer11->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer11->setPosition(vector3df(-260, -85, -220));

		vector3df roty = chairContainer11->getRotation();
		roty.Y -= 90;
		chairContainer11->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC11 = smgr->createTriangleSelector(pcChair1, chairContainer11);
		chairContainer11->setTriangleSelector(selectorC11);
		if (selectorC11)
		{
			scene::ISceneNodeAnimator* animC11 = smgr->createCollisionResponseAnimator(
				selectorC11, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC11->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC11);
			animC11->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (monitorContainer12)
	{
		monitorContainer12->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer12->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer12->setPosition(vector3df(-330, 75, -280));
		vector3df roty = monitorContainer12->getRotation();
		roty.Y += 90;
		monitorContainer12->setRotation(vector3df(roty));
	}
	if (towerContainer12)
	{
		towerContainer12->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer12->setScale(vector3df(1.5, 2, 1.5));
		towerContainer12->setPosition(vector3df(-320, -13, -30));
		vector3df roty = towerContainer12->getRotation();
		roty.Y += 90;
		towerContainer12->setRotation(vector3df(roty));
	}
	if (mouseContainer12)
	{
		mouseContainer12->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer12->setScale(vector3df(3, 3, 3));
		mouseContainer12->setPosition(vector3df(-290, -13, -60));
		vector3df roty = mouseContainer12->getRotation();
		roty.Y += 90;
		mouseContainer12->setRotation(vector3df(roty));
	}
	if (keyboardContainer12)
	{
		keyboardContainer12->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer12->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer12->setPosition(vector3df(-300, -13, -100));
		vector3df roty = keyboardContainer12->getRotation();
		roty.Y += 90;
		keyboardContainer12->setRotation(vector3df(roty));
	}
	if (chairContainer12)
	{
		chairContainer12->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer12->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer12->setPosition(vector3df(-260, -85, -100));

		vector3df roty = chairContainer12->getRotation();
		roty.Y -= 90;
		chairContainer12->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC12 = smgr->createTriangleSelector(pcChair1, chairContainer12);
		chairContainer12->setTriangleSelector(selectorC12);
		if (selectorC12)
		{
			scene::ISceneNodeAnimator* animC12 = smgr->createCollisionResponseAnimator(
				selectorC12, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC12->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC12);
			animC12->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	/////////////////////////////////////
	if (monitorContainer13)
	{
		monitorContainer13->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer13->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer13->setPosition(vector3df(-330, 75, 240));
		vector3df roty = monitorContainer13->getRotation();
		roty.Y += 90;
		monitorContainer13->setRotation(vector3df(roty));
	}
	if (towerContainer13)
	{
		towerContainer13->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer13->setScale(vector3df(1.5, 2, 1.5));
		towerContainer13->setPosition(vector3df(-320, -13, 490));
		vector3df roty = towerContainer13->getRotation();
		roty.Y += 90;
		towerContainer13->setRotation(vector3df(roty));
	}

	if (mouseContainer13)
	{
		mouseContainer13->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer13->setScale(vector3df(3, 3, 3));
		mouseContainer13->setPosition(vector3df(-290, -13, 470));
		vector3df roty = mouseContainer13->getRotation();
		roty.Y += 90;
		mouseContainer13->setRotation(vector3df(roty));
	}

	if (keyboardContainer13)
	{
		keyboardContainer13->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer13->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer13->setPosition(vector3df(-300, -13, 430));
		vector3df roty = keyboardContainer13->getRotation();
		roty.Y += 90;
		keyboardContainer13->setRotation(vector3df(roty));
	}

	if (chairContainer13)
	{
		chairContainer13->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer13->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer13->setPosition(vector3df(-260, -85, 440));

		vector3df roty = chairContainer13->getRotation();
		roty.Y -= 90;
		chairContainer13->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC13 = smgr->createTriangleSelector(pcChair1, chairContainer13);
		chairContainer13->setTriangleSelector(selectorC13);
		if (selectorC13)
		{
			scene::ISceneNodeAnimator* animC13 = smgr->createCollisionResponseAnimator(
				selectorC13, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC13->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC13);
			animC13->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	
	if (monitorContainer14)
	{
		monitorContainer14->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer14->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer14->setPosition(vector3df(-330, 75, 120));
		vector3df roty = monitorContainer14->getRotation();
		roty.Y += 90;
		monitorContainer14->setRotation(vector3df(roty));
	}
	if (towerContainer14)
	{
		towerContainer14->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer14->setScale(vector3df(1.5, 2, 1.5));
		towerContainer14->setPosition(vector3df(-320, -13, 370));
		vector3df roty = towerContainer14->getRotation();
		roty.Y += 90;
		towerContainer14->setRotation(vector3df(roty));
	}

	if (mouseContainer14)
	{
		mouseContainer14->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer14->setScale(vector3df(3, 3, 3));
		mouseContainer14->setPosition(vector3df(-290, -13, 350));
		vector3df roty = mouseContainer14->getRotation();
		roty.Y += 90;
		mouseContainer14->setRotation(vector3df(roty));
	}

	if (keyboardContainer14)
	{
		keyboardContainer14->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer14->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer14->setPosition(vector3df(-300, -13, 310));
		vector3df roty = keyboardContainer14->getRotation();
		roty.Y += 90;
		keyboardContainer14->setRotation(vector3df(roty));
	}

	if (chairContainer14)
	{
		chairContainer14->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer14->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer14->setPosition(vector3df(-260, -85, 320));

		vector3df roty = chairContainer14->getRotation();
		roty.Y -= 90;
		chairContainer14->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC14 = smgr->createTriangleSelector(pcChair1, chairContainer14);
		chairContainer14->setTriangleSelector(selectorC14);
		if (selectorC14)
		{
			scene::ISceneNodeAnimator* animC14 = smgr->createCollisionResponseAnimator(
				selectorC14, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC14->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC14);
			animC14->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (monitorContainer15)
	{
		monitorContainer15->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer15->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer15->setPosition(vector3df(-330, 75, 0));
		vector3df roty = monitorContainer15->getRotation();
		roty.Y += 90;
		monitorContainer15->setRotation(vector3df(roty));
	}
	if (towerContainer15)
	{
		towerContainer15->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer15->setScale(vector3df(1.5, 2, 1.5));
		towerContainer15->setPosition(vector3df(-320, -13, 250));
		vector3df roty = towerContainer15->getRotation();
		roty.Y += 90;
		towerContainer15->setRotation(vector3df(roty));
	}

	if (mouseContainer15)
	{
		mouseContainer15->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer15->setScale(vector3df(3, 3, 3));
		mouseContainer15->setPosition(vector3df(-290, -13, 230));
		vector3df roty = mouseContainer15->getRotation();
		roty.Y += 90;
		mouseContainer15->setRotation(vector3df(roty));
	}

	if (keyboardContainer15)
	{
		keyboardContainer15->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer15->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer15->setPosition(vector3df(-300, -13, 190));
		vector3df roty = keyboardContainer15->getRotation();
		roty.Y += 90;
		keyboardContainer15->setRotation(vector3df(roty));
	}

	if (chairContainer15)
	{
		chairContainer15->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer15->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer15->setPosition(vector3df(-260, -85, 200));

		vector3df roty = chairContainer15->getRotation();
		roty.Y -= 90;
		chairContainer15->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC15 = smgr->createTriangleSelector(pcChair1, chairContainer15);
		chairContainer15->setTriangleSelector(selectorC15);
		if (selectorC15)
		{
			scene::ISceneNodeAnimator* animC15 = smgr->createCollisionResponseAnimator(
				selectorC15, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC15->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC15);
			animC15->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (monitorContainer16)
	{
		monitorContainer16->setMaterialFlag(EMF_LIGHTING, false);

		monitorContainer16->setScale(vector3df(0.1, 0.1, 0.1));
		monitorContainer16->setPosition(vector3df(-330, 75, -120));
		vector3df roty = monitorContainer16->getRotation();
		roty.Y += 90;
		monitorContainer16->setRotation(vector3df(roty));
	}
	if (towerContainer16)
	{
		towerContainer16->setMaterialFlag(EMF_LIGHTING, false);

		towerContainer16->setScale(vector3df(1.5, 2, 1.5));
		towerContainer16->setPosition(vector3df(-320, -13, 130));
		vector3df roty = towerContainer16->getRotation();
		roty.Y += 90;
		towerContainer16->setRotation(vector3df(roty));
	}

	if (mouseContainer16)
	{
		mouseContainer16->setMaterialFlag(EMF_LIGHTING, false);

		mouseContainer16->setScale(vector3df(3, 3, 3));
		mouseContainer16->setPosition(vector3df(-290, -13, 110));
		vector3df roty = mouseContainer16->getRotation();
		roty.Y += 90;
		mouseContainer16->setRotation(vector3df(roty));
	}

	if (keyboardContainer16)
	{
		keyboardContainer16->setMaterialFlag(EMF_LIGHTING, false);

		keyboardContainer16->setScale(vector3df(1.5, 0.5, 1.5));
		keyboardContainer16->setPosition(vector3df(-300, -13, 70));
		vector3df roty = keyboardContainer16->getRotation();
		roty.Y += 90;
		keyboardContainer16->setRotation(vector3df(roty));
	}

	if (chairContainer16)
	{
		chairContainer16->setMaterialFlag(EMF_LIGHTING, false);
		chairContainer16->setScale(vector3df(0.1, 0.1, 0.1));
		chairContainer16->setPosition(vector3df(-260, -85, 80));

		vector3df roty = chairContainer16->getRotation();
		roty.Y -= 90;
		chairContainer16->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorC16 = smgr->createTriangleSelector(pcChair1, chairContainer16);
		chairContainer16->setTriangleSelector(selectorC16);
		if (selectorC16)
		{
			scene::ISceneNodeAnimator* animC16 = smgr->createCollisionResponseAnimator(
				selectorC16, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorC16->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animC16);
			animC16->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}

	if (cupboardContainer)
	{
		cupboardContainer->setMaterialFlag(EMF_LIGHTING, false);
		cupboardContainer->setScale(vector3df(4.0, 4.0, 2.0));
		cupboardContainer->setPosition(vector3df(140, 100, -576));

		scene::ITriangleSelector* selectorCb1 = smgr->createTriangleSelector(cupboard, cupboardContainer);
		cupboardContainer->setTriangleSelector(selectorCb1);
		if (selectorCb1)
		{
			scene::ISceneNodeAnimator* animCb1 = smgr->createCollisionResponseAnimator(
				selectorCb1, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorCb1->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animCb1);
			animCb1->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (cupboardContainer2)
	{
		cupboardContainer2->setMaterialFlag(EMF_LIGHTING, false);
		cupboardContainer2->setScale(vector3df(4.0, 4.0, 2.0));
		cupboardContainer2->setPosition(vector3df(0, 100, -576));

		scene::ITriangleSelector* selectorCb2 = smgr->createTriangleSelector(cupboard, cupboardContainer2);
		cupboardContainer2->setTriangleSelector(selectorCb2);
		if (selectorCb2)
		{
			scene::ISceneNodeAnimator* animCb2 = smgr->createCollisionResponseAnimator(
				selectorCb2, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorCb2->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animCb2);
			animCb2->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (cupboardContainer3)
	{
		cupboardContainer3->setMaterialFlag(EMF_LIGHTING, false);
		cupboardContainer3->setScale(vector3df(4.0, 4.0, 2.0));
		cupboardContainer3->setPosition(vector3df(-140, 100, -576));

		scene::ITriangleSelector* selectorCb3 = smgr->createTriangleSelector(cupboard, cupboardContainer3);
		cupboardContainer3->setTriangleSelector(selectorCb3);
		if (selectorCb3)
		{
			scene::ISceneNodeAnimator* animCb3 = smgr->createCollisionResponseAnimator(
				selectorCb3, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorCb3->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animCb3);
			animCb3->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (cupboardContainer4)
	{
		cupboardContainer4->setMaterialFlag(EMF_LIGHTING, false);
		cupboardContainer4->setScale(vector3df(4.0, 4.0, 2.0));
		cupboardContainer4->setPosition(vector3df(140, 100, 576));
		vector3df roty = cupboardContainer4->getRotation();
		roty.Y -= 180;
		cupboardContainer4->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorCb4 = smgr->createTriangleSelector(cupboard, cupboardContainer4);
		cupboardContainer4->setTriangleSelector(selectorCb4);
		if (selectorCb4)
		{
			scene::ISceneNodeAnimator* animCb4 = smgr->createCollisionResponseAnimator(
				selectorCb4, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorCb4->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animCb4);
			animCb4->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (cupboardContainer5)
	{
		cupboardContainer5->setMaterialFlag(EMF_LIGHTING, false);
		cupboardContainer5->setScale(vector3df(4.0, 4.0, 2.0));
		cupboardContainer5->setPosition(vector3df(0, 100, 576));
		vector3df roty = cupboardContainer5->getRotation();
		roty.Y -= 180;
		cupboardContainer5->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorCb5 = smgr->createTriangleSelector(cupboard, cupboardContainer5);
		cupboardContainer5->setTriangleSelector(selectorCb5);
		if (selectorCb5)
		{
			scene::ISceneNodeAnimator* animCb5 = smgr->createCollisionResponseAnimator(
				selectorCb5, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorCb5->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animCb5);
			animCb5->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (cupboardContainer6)
	{
		cupboardContainer6->setMaterialFlag(EMF_LIGHTING, false);
		cupboardContainer6->setScale(vector3df(4.0, 4.0, 2.0));
		cupboardContainer6->setPosition(vector3df(-140, 100, 576));
		vector3df roty = cupboardContainer6->getRotation();
		roty.Y -= 180;
		cupboardContainer6->setRotation(vector3df(roty));

		scene::ITriangleSelector* selectorCb6 = smgr->createTriangleSelector(cupboard, cupboardContainer6);
		cupboardContainer6->setTriangleSelector(selectorCb6);
		if (selectorCb6)
		{
			scene::ISceneNodeAnimator* animCb6 = smgr->createCollisionResponseAnimator(
				selectorCb6, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorCb6->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animCb6);
			animCb6->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (lecturnContainer)
	{
		lecturnContainer->setMaterialFlag(EMF_LIGHTING, false);
		lecturnContainer->setMaterialTexture(0, driver->getTexture("media/WhiteTabletop.bmp"));
		lecturnContainer->setScale(vector3df(3.0, 4.0, 6.0));
		lecturnContainer->setPosition(vector3df(180.0, -86.0, 200.0));

		scene::ITriangleSelector* selectorLec = smgr->createTriangleSelector(lecturn, lecturnContainer);
		lecturnContainer->setTriangleSelector(selectorLec);
		if (selectorLec)
		{
			scene::ISceneNodeAnimator* animL = smgr->createCollisionResponseAnimator(
				selectorLec, camera, core::vector3df(30, 1000, 30),
				core::vector3df(0, 0, 0), core::vector3df(0, 50, 0));
			selectorLec->drop(); // As soon as we're done with the selector, drop it.
			camera->addAnimator(animL);
			animL->drop();  // And likewise, drop the animator when we're done referring to it.
		}
	}
	if (markerContainer1)
	{
		markerContainer1->setMaterialFlag(EMF_LIGHTING, false);
		//markerContainer1->setScale(vector3df(0.5, 1.0, 1.0));
		markerContainer1->setPosition(vector3df(180, -31, 160));
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
