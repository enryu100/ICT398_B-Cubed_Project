#include "Player.h"


Player::~Player()
{
}

void Player::setPlayerHealth(int value)
{
	playerHealth = value;
	if (playerHealth > 100)
		playerHealth = 100;

	if (playerHealth < 0)
		playerHealth = 0;
}

void Player::setPlayerAmmo(int value)
{
	playerAmmo = value;
	if (playerAmmo > 100)
		playerAmmo = 100;

	if (playerAmmo < 0)
		playerAmmo = 0;
}

void Player::increasePlayerHealth(int value)
{
	playerHealth += value;
	if (playerHealth > 100)
		playerHealth = 100;
}

void Player::increaseAmmo(int value)
{
	playerAmmo += value;
	if (playerAmmo > 100)
		playerAmmo = 100;
}

void Player::decreasePlayerHealth(int value)
{
	playerHealth -= value;
	if (playerHealth < 0)
		playerHealth = 0;
}

void Player::decreaseAmmo(int value)
{
	playerAmmo -= value;
	if (playerAmmo < 0)
		playerAmmo = 0;
}

int Player::getPlayerHealth()
{
	return playerHealth;
}

int Player::getAmmo()
{
	return playerAmmo;
}

std::string Player::getPlayerHealthStr()
{
	std::string str = std::to_string(playerHealth);

	return(str);
}

std::string Player::getAmmoStr()
{
	std::string str = std::to_string(playerAmmo);

	return(str);
}