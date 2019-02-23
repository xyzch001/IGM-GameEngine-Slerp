#include "pch.h"
#include "SlowSlerp.h"


Quaternion SlowSlerp::SlerpSlow(Quaternion v0, Quaternion v1, double t)
{




	// Only unit quaternions are valid rotations.
	// Normalize to avoid undefined behavior.
	v0.normalize();
	v1.normalize();

	// Compute the cosine of the angle between the two vectors.
	double dot = dot_product(v0, v1);

	// If the dot product is negative, slerp won't take
	// the shorter path. Note that v1 and -v1 are equivalent when
	// the negation is applied to all four components. Fix by 
	// reversing one quaternion.
	if (dot < 0.0f) {
		v1 = Quaternion{ 0.0f, 0.0f, 0.0f, 0.0f } -v1;
		dot = -dot;
	}

	//const double DOT_THRESHOLD = 0.9995;
	//if (dot > DOT_THRESHOLD) {
	//	// If the inputs are too close for comfort, linearly interpolate
	//	// and normalize the result.

	//	Quaternion result = v0 + (v1 - v0) * t;
	//	result.normalize();


	//	std::cout << result.x << std::endl;

	//	return result;
	//}

	// Since dot is in range [0, DOT_THRESHOLD], acos is safe
	double theta_0 = acos(dot);        // theta_0 = angle between input vectors
	double theta = theta_0 * t;          // theta = angle between v0 and result
	double sin_theta = sin(theta);     // compute this value only once
	double sin_theta_0 = sin(theta_0); // compute this value only once

	double s0 = cos(theta) - dot * sin_theta / sin_theta_0;  // == sin(theta_0 - theta) / sin(theta_0)
	double s1 = sin_theta / sin_theta_0;
	//std::cout <<  << std::endl;
	return (v0 * s0) + (v1 * s1);
}

double SlowSlerp::dot_product(Quaternion v0, Quaternion v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
}

SlowSlerp::SlowSlerp()
{
}


SlowSlerp::~SlowSlerp()
{
}
