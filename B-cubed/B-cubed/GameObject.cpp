#include "GameObject.h"
#include "irrlicht.h"

void GameObject::setID(int i) {
	id = i;
}

void GameObject::setName(std::string name) {
	objName = name;
}

void GameObject::setMesh(std::string mPath) {
	meshPath = mPath;
}

void GameObject::setTex(std::string tPath) {
	texPath = tPath;
}

void GameObject::setPosX(float x) {
	posX = x;
}

void GameObject::setPosY(float y) {
	posY = y;
}

void GameObject::setPosZ(float z) {
	posZ = z;
}

void GameObject::setRotX(float x) {
	rotX = x;
}

void GameObject::setRotY(float y) {
	rotY = y;
}

void GameObject::setRotZ(float z) {
	rotZ = z;
}

void GameObject::setScaleX(float x) {
	scaleX = x;
}

void GameObject::setScaleY(float y) {
	scaleY = y;
}

void GameObject::setScaleZ(float z) {
	scaleZ = z;
}

void GameObject::setPTM(float p) {
	ptm = p;
}

void GameObject::setAnim(int h){
	hasAnim = h;
}

void GameObject::setMass(float m) {
	mass = m;
}

void GameObject::setPickable(int flag) {
	isPickable = flag;
}

void GameObject::setPhysics(bool phys) {
	hasPhysics = phys;
}

void GameObject::setInteractible(bool interact) {
	interactible = interact;
}

void GameObject::setVelX(float vx){
	velX = vx;
}

void GameObject::setVelY(float vy){
	velY = vy;
}

void GameObject::setVelZ(float vz){
	velZ = vz;
}

void GameObject::setRotVX(float rx){
	rotvX = rx;
}

void GameObject::setRotVY(float ry){
	rotvY = ry;
}

void GameObject::setRotVZ(float rz){
	rotvZ = rz;
}

void GameObject::setEmotionResponse(int er) {
	emotionResponse = er;
}

GameObject::GameObject(std::string name, std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float p, int h, float m, int pick, bool phys, bool interact) {
	setName(name);
	setMesh(mPath);
	setTex(tPath);
	setPosX(x);
	setPosY(y);
	setPosZ(z);
	setRotX(rx);
	setRotY(ry);
	setRotZ(rz);
	setScaleX(sx);
	setScaleY(sy);
	setScaleZ(sz);
	setPTM(p);
	setAnim(h);
	setMass(m);
	setPickable(pick);
	setPhysics(phys);
	setInteractible(interact);
	setEmotionResponse(0);
	edible = 0;
}

GameObject::GameObject(std::string name, std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float p, float m, int pick, bool phys, bool interact) {
	setName(name);
	setMesh(mPath);
	setTex(tPath);
	setPosX(x);
	setPosY(y);
	setPosZ(z);
	setRotX(rx);
	setRotY(ry);
	setRotZ(rz);
	setScaleX(sx);
	setScaleY(sy);
	setScaleZ(sz);
	setPTM(p);
	setAnim(0);
	setMass(m);
	setPickable(pick);
	setPhysics(phys);
	setInteractible(interact);
	setEmotionResponse(0);
	edible = 0;
}

GameObject::GameObject(std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float p, float m, int pick, bool phys, bool interact) {
	setName("");
	setMesh(mPath);
	setTex(tPath);
	setPosX(x);
	setPosY(y);
	setPosZ(z);
	setRotX(rx);
	setRotY(ry);
	setRotZ(rz);
	setScaleX(sx);
	setScaleY(sy);
	setScaleZ(sz);
	setPTM(p);
	setAnim(0);
	setMass(m);
	setPickable(pick);
	setPhysics(phys);
	setInteractible(interact);
	setEmotionResponse(0);
	edible = 0;
}

vector3df GameObject::getScaleVector() {
	return vector3df(scaleX, scaleY, scaleZ);
}

vector3df GameObject::getPosVector() {
	return vector3df(posX, posY, posZ);
}

vector3df GameObject::getRotVector() {
	return vector3df(rotX, rotY, rotZ);
}

vector3df GameObject::getLineVel() {
	return vector3df(velX, velY, velZ);
}

vector3df GameObject::getRotVel() {
	return vector3df(rotvX, rotvY, rotvZ);
}

void GameObject::initEmotions() {
	emotions = EmotionEngine();
}

void GameObject::initEmotionVals(float js, float td, float fr, float sa, float jm, float sadm, float tm, float dm, float fm, float rm, float surpm, float am, float aov, float dov, float dr, float et) {
	emotions = EmotionEngine(js, td, fr, sa, jm, sadm, tm, dm, fm, rm, surpm, am, aov, dov, dr, et);
}

std::string GameObject::getEmotions() {
	//initialise empty string
	std::string emote = "";

	//add lines for each emotion axis
	emote = "Joy-Sadness: " + std::to_string(emotions.getJoySad()) + "\n";
	emote += "Trust-Disgust: " + std::to_string(emotions.getTrustDisgust()) + "\n";
	emote += "Fear-Rage: " + std::to_string(emotions.getFearAnger()) + "\n";
	emote += "Surprise-Anticipation: " + std::to_string(emotions.getSurpriseAnticipation());

	return emote;
}

bool GameObject::isHungry(){
	if(hunger >= 50){
		return true;
	} else{
		return false;
	}
}

void GameObject::incHunger(float val){
	hunger += val * hungerRate;
	if (hunger > 100) {
		hunger = 100;
	}
}

void GameObject::decHunger(float val){
	hunger -= val * hungerRate;
	if (hunger < 0) {
		hunger = 0;
	}
}

int GameObject::changeEmotion(float j, float s, float t, float d, float f, float r, float su, float a) {
	
	if (emotions.addJoy(j) != 0 ||
		emotions.addSad(s) != 0 ||
		emotions.addTrust(t) != 0 ||
		emotions.addDisgust(d) != 0 ||
		emotions.addFear(f) != 0 ||
		emotions.addAnger(r) != 0 ||
		emotions.addSurprise(su) != 0 ||
		emotions.addAnticipation(a) != 0) {
			
		setEmotionResponse(1);
		return 1;
	}
	else {
		setEmotionResponse(0);
		return 0;
	}
}

void GameObject::setObjMesh(irr::scene::IAnimatedMesh* mesh) {
	ObjectMesh = mesh;
}

void GameObject::setNode(irr::scene::ISceneNode* mesh) {
	ObjectNode = mesh;
}

void GameObject::setPosVec(vector3df vec) {
	posX = vec.X;
	posY = vec.Y;
	posZ = vec.Z;
}

void GameObject::setRotVec(vector3df vec) {
	rotX = vec.X;
	rotY = vec.Y;
	rotZ = vec.Z;
}

void GameObject::setScaleVec(vector3df vec) {
	scaleX = vec.X;
	scaleY = vec.Y;
	scaleZ = vec.Z;
}

void GameObject::updatePosition() {
	ObjectNode->setPosition(getPosVector());
}
void GameObject::updateRotation() {
	ObjectNode->setRotation(getRotVector());
}