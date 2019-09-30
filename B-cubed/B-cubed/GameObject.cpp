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

GameObject::GameObject(std::string mPath, std::string tPath, float x, float y, float z, float rx, float ry, float rz, float sx, float sy, float sz, float m, int pick, bool phys, bool interact) {
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