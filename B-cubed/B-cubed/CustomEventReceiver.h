#pragma once
#include "irrlicht.h"
#include "driverChoice.h"

using namespace irr;

class CustomEventReceiver : public IEventReceiver
{
public:


	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	{
		// Remember the mouse state
		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		{
			switch (event.MouseInput.Event)
			{
			case EMIE_LMOUSE_PRESSED_DOWN:
				lClick = true;
				break;

			case EMIE_LMOUSE_LEFT_UP:
				lClick = false;
				break;
			default:
				// We won't use the wheel
				break;
			}
		}

		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		}

		return false;
	}


	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}

	bool getMouseClick() {
		return lClick;
	}

	CustomEventReceiver()
	{
		lClick = false;
		for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
	}

private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	bool lClick;
};