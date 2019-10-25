#include "GameObject.h"


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

GameObject::GameObject(std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float p, int h, float m, int pick, bool phys, bool interact) {
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
}

GameObject::GameObject(std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float p, float m, int pick, bool phys, bool interact) {
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
	setMass(m);
	setPickable(pick);
	setPhysics(phys);
	setInteractible(interact);
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

std::string GameObject::getEmotions() {
	//initialise empty string
	std::string emote = "";

	//add lines for each emotion axis
	emote = "Joy-Sadness: " + std::to_string(emotions.getJoySad()) + "\n";
	emote += "Trust-Disgust: " + std::to_string(emotions.getTrustDisgust()) + "\n";
	emote = "Fear-Rage: " + std::to_string(emotions.getFearAnger()) + "\n";
	emote = "Surprise-Anticipation: " + std::to_string(emotions.getSurpriseAnticipation());

	return emote;
}

bool GameObject::isHungry(){
	if(hunger >= 10){
		return true;
	} else{
		return false;
	}
}

void GameObject::incHunger(float val){
	hunger += val * hungerRate;
}

void GameObject::decHunger(float val){
	hunger -= val * hungerRate;
}