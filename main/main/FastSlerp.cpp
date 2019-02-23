#include "pch.h"
#include "FastSlerp.h"


XQuaternion FastSlerp::SlerpFast(XQuaternion v0, XQuaternion v1, double t)
{
	v0.normalize();
	v1.normalize();

	// Compute the cosine of the angle between the two vectors.
	double dot = dot_product(v0, v1);

	// If the dot product is negative, slerp won't take
	// the shorter path. Note that v1 and -v1 are equivalent when
	// the negation is applied to all four components. Fix by 
	// reversing one quaternion.
	if (dot < 0.0f) {
		v1 = _mm_sub_ps(_mm_set1_ps(0.0),v1);
		dot = -dot;
	}

	//const double DOT_THRESHOLD = 0.9995;
	//if (dot > DOT_THRESHOLD) {
	//	// If the inputs are too close for comfort, linearly interpolate
	//	// and normalize the result.

	//	//_mm_add_ps(v0 , _mm_mul_ps(_mm_set1_ps(t), _mm_sub_ps(v1, v0)));
	//	XQuaternion result = _mm_add_ps(v0, _mm_mul_ps(_mm_set1_ps(t), _mm_sub_ps(v1, v0)));
	//	result.normalize();
	//	return result;
	//}

	// Since dot is in range [0, DOT_THRESHOLD], acos is safe
	double theta_0 = acos(dot);        // theta_0 = angle between input vectors
	double theta = theta_0 * t;          // theta = angle between v0 and result
	double sin_theta = sin(theta);     // compute this value only once
	double sin_theta_0 = sin(theta_0); // compute this value only once

	double s0 = cos(theta) - dot * sin_theta / sin_theta_0;  // == sin(theta_0 - theta) / sin(theta_0)
	double s1 = sin_theta / sin_theta_0;

	//_mm_add_ps(_mm_mul_ps(_mm_set1_ps(s0), v0), _mm_mul_ps(_mm_set1_ps(s1), v1));
	return _mm_add_ps(_mm_mul_ps(_mm_set1_ps(s0), v0), _mm_mul_ps(_mm_set1_ps(s1), v1));
}

double FastSlerp::dot_product(XQuaternion v0, XQuaternion v1)
{
	double dot = _mm_extract_ps(_mm_dp_ps(v0.getM_Vector(), v0.getM_Vector(), 0xff), 0);
	return dot;
}

FastSlerp::FastSlerp()
{
}


FastSlerp::~FastSlerp()
{
}
