#include "EmotionEngine.h"
#include <cmath>

int EmotionEngine::testEmotionForResponse(float emotion) {
	if (emotion >= emotionThreshold) {
		return 1;
	}
	else {
		if (emotion <= (emotionThreshold * -1.0f)) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

void EmotionEngine::normalizeEmotions() {
	// check if total means there could be more than 1 value over threshold
	float total;
	total = abs(joySad) + abs(trustDisgust) + abs(fearRage) + abs(surpriseAnticipation);
	if (total > (float)19.7) {
		//normalization needed
		float ratio = 19.7f / total;
		joySad = joySad * ratio;
		trustDisgust = trustDisgust * ratio;
		fearRage = fearRage * ratio;
		surpriseAnticipation = surpriseAnticipation * ratio;
	}

	return;
}

int EmotionEngine::addJoy(float joyVal) {
	joySad += (joyVal * joyMod);
	normalizeEmotions();
	return testEmotionForResponse(joySad);
}

int EmotionEngine::addSad(float sadVal) {
	joySad -= (sadVal * sadMod);
	normalizeEmotions();
	return testEmotionForResponse(joySad);
}

int EmotionEngine::addTrust(float trustVal) {
	trustDisgust += (trustVal * trustMod);
	normalizeEmotions();
	return testEmotionForResponse(trustDisgust);
}

int EmotionEngine::addDisgust(float disgVal) {
	trustDisgust -= (disgVal * disgustMod);
	normalizeEmotions();
	return testEmotionForResponse(trustDisgust);
}

int EmotionEngine::addFear(float fearVal) {
	fearRage += (fearVal * fearMod);
	normalizeEmotions();
	return testEmotionForResponse(fearRage);
}

int EmotionEngine::addAnger(float angVal) {
	fearRage -= (angVal * rageMod);
	normalizeEmotions();
	return testEmotionForResponse(fearRage);
}

int EmotionEngine::addSurprise(float surpVal) {
	surpriseAnticipation += (surpVal * surpriseMod);
	normalizeEmotions();
	return testEmotionForResponse(surpriseAnticipation);
}

int EmotionEngine::addAnticipation(float anticVal) {
	surpriseAnticipation -= (anticVal * anticipationMod);
	normalizeEmotions();
	return testEmotionForResponse(surpriseAnticipation);
}

void EmotionEngine::calcViewData() {
	int state = 0;

	//calculate emotional state based on emotion values
	if (joySad > 0) {
		state++;
	}
	else {
		if (joySad < 0) {
			state--;
		}
	}
	if (trustDisgust > 0) {
		state++;
	}
	else {
		if (trustDisgust < 0) {
			state--;
		}
	}
	if (surpriseAnticipation > 0) {
		state++;
	}
	else {
		if (surpriseAnticipation < 0) {
			state--;
		}
	}

	//translate state to view angle and depth
	if (state > 0) {
		angleOfView = 120.0;
		depthOfView = 50.0;
	}
	else if (state < 0) {
		angleOfView = 90.0;
		depthOfView = 100.0;
	}
}

void EmotionEngine::setEmotionThreshold(float e_threshhold) {
	emotionThreshold = e_threshhold;
}

void EmotionEngine::decayEmotions() {
	//this should be called on a specific interval, to gradually return emotions to a near-midpoint level
	if(joySad > 0) {
		joySad = (joySad * decayRate * joyMod) + initialJS;
	}
	else {
		joySad = (joySad * decayRate * sadMod) + initialJS;
	}
	if (trustDisgust > 0) {
		trustDisgust = (trustDisgust * decayRate * trustMod) + initialTD;
	}
	else {
		trustDisgust = (trustDisgust * decayRate * disgustMod) + initialTD;
	}
	if (fearRage > 0) {
		fearRage = (fearRage * decayRate * fearMod) + initialFR;
	}
	else {
		fearRage = (fearRage * decayRate * rageMod) + initialFR;
	}
	if (surpriseAnticipation > 0) {
		surpriseAnticipation = (surpriseAnticipation * decayRate * surpriseMod) + initialSA;
	} else {
		surpriseAnticipation = (surpriseAnticipation * decayRate * anticipationMod) + initialSA;
	}
}

void EmotionEngine::setEmotionLevels(float joy, float trust, float fear, float surprise) {
	joySad = joy;
	trustDisgust = trust;
	fearRage = fear;
	surpriseAnticipation = surprise;
}

void EmotionEngine::setJoyModifier(float joy_m) {
	joyMod = joy_m;
}
void EmotionEngine::setTrustModifier(float trust_m) {
	trustMod = trust_m;
}
void EmotionEngine::setFearModifier(float fear_m) {
	fearMod = fear_m;
}
void EmotionEngine::setSurpriseModifier(float surprise_m) {
	surpriseMod = surprise_m;
}
void EmotionEngine::setSadnessModifier(float sadness_m) {
	sadMod = sadness_m;
}
void EmotionEngine::setDisgustModifier(float disgust_m) {
	disgustMod = disgust_m;
}
void EmotionEngine::setAngerModifier(float anger_m) {
	rageMod = anger_m;
}
void EmotionEngine::setAnticipationModifier(float anticipation_m) {
	anticipationMod = anticipation_m;
}

EmotionEngine::EmotionEngine(float js, float td, float fr, float sa, float jm, float sadm, float tm, float dm, float fm, float rm, float surpm, float am, float aov, float dov, float dr, float et) {
	joySad = js;
	initialJS = joySad;
	trustDisgust = td;
	initialTD = trustDisgust;
	fearRage = fr;
	initialFR = fearRage;
	surpriseAnticipation = sa;
	initialSA = surpriseAnticipation;
	joyMod = jm;
	sadMod = sadm;
	trustMod = tm;
	disgustMod = dm;
	fearMod = fm;
	rageMod = rm;
	surpriseMod = surpm;
	anticipationMod = am;
	emotionThreshold = et;
	decayRate = dr;
	depthOfView = dov;
	angleOfView = aov;
	normalizeEmotions();
}

EmotionEngine::EmotionEngine() {
	joySad = 0.0f;
	initialJS = joySad;
	trustDisgust = 0.0f;
	initialTD = trustDisgust;
	fearRage = 0.0f;
	initialFR = fearRage;
	surpriseAnticipation = 0.0f;
	initialSA = surpriseAnticipation;
	joyMod = 1.0f;
	sadMod = 1.0f;
	trustMod = 1.0f;
	disgustMod = 1.0f;
	fearMod = 1.0f;
	rageMod = 1.0f;
	surpriseMod = 1.0f;
	anticipationMod = 1.0f;
	emotionThreshold = 10.0f;
	decayRate = 1.0f;
	depthOfView = 10.0f;
	angleOfView = 120.0f;
	normalizeEmotions();
}

