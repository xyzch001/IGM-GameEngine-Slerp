#pragma once
#include "Math.h"
#include <chrono>
#include <iostream>
using namespace Math;

class SlowSlerp
{
public:
	Quaternion SlerpSlow(Quaternion v0, Quaternion v1, double t);
	double dot_product(Quaternion v0, Quaternion v1);
	SlowSlerp();
	~SlowSlerp();



};

