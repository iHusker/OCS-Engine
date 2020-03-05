#pragma once

#include <iostream>
#include <ostream>
#include <map>
#include <vector>
#include <typeindex>

//SDL
#include <SDL.h>
#include <SDL_image.h>

//BOX2D
#include <b2_body.h>
#include <b2_world.h>
#include <b2_fixture.h>
#include <b2_polygon_shape.h>

extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern Uint64 DELTATIME;

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;



struct Vector2
{
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float scalar) : x(scalar), y(scalar) {}
	Vector2(float x, float y) : x(x), y(y){	}

	Vector2& operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }
	Vector2& operator-=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }
	Vector2& operator+=(const float& scalar) { x += scalar; y += scalar; return *this; }
	Vector2& operator-=(const float& scalar) { x -= scalar; y -= scalar; return *this; }

	friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs) { return Vector2(lhs) += rhs; }
	friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs) { return Vector2(lhs) -= rhs; }

	float x, y;
};