#pragma once

#include "GameData.h"

struct Player
{
	Vector2 position;
	Vector2 size;
	Vector2 speed;
	Vector2 textureSize;
	int availableLives;
	int texture;
	int points;
	int ammo;
	bool isAlive;
	bool firstTime = true;
};

struct Ball
{
	Vector2 position;
	Vector2 speed;
	Vector2 textureSize;
	int texture;
	float radius;
	float maxSpeed;
	bool isAlive;
	bool isOut;
};

struct Brick
{
	Vector2 position;
	Vector2 size;
	Vector2 textureSize;
	int texture;
	bool isAlive;
	bool isAcid;
	bool isIce;
	bool isBig;
	bool isStone;
};