#pragma once
#include "MathX.h"
#include <chrono>
#include <iostream>

using namespace Math;

class FastSlerp
{
public:
	XQuaternion SlerpFast(XQuaternion v0, XQuaternion v1, double t);
	double dot_product(XQuaternion v0, XQuaternion v1);

	FastSlerp();
	~FastSlerp();
};

