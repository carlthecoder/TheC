#define _USE_MATH_DEFINES
#include "../headers/vector3.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>

void Vector3_AddVectors(const Vector3D* vec1, const Vector3D* vec2, Vector3D* returnVec)
{
	returnVec->x = vec1->x + vec2->x;
	returnVec->y = vec1->y + vec2->y;
	returnVec->z = vec1->z + vec2->z;
}

void Vector3_SubstractVectors(const Vector3D* vec1, const Vector3D* vec2, Vector3D* returnVec)
{
	returnVec->x = vec1->x - vec2->x;
	returnVec->y = vec1->y - vec2->y;
	returnVec->z = vec1->z - vec2->z;
}

void Vector3_ScalarMultiplication(const Vector3D* vec, double scalar, Vector3D* returnVec)
{
	returnVec->x = vec->x * scalar;
	returnVec->y = vec->y * scalar;
	returnVec->z = vec->z * scalar;
}

double Vector3_Magnitude(const Vector3D* vec)
{
	return sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
}

void Vector3_GetNormalizedVector(const Vector3D* vec, Vector3D* returnVec)
{
	double magnitude = Vector3_Magnitude(vec);

	returnVec->x = vec->x / magnitude;
	returnVec->y = vec->y / magnitude;
	returnVec->z = vec->z / magnitude;
}

double Vector3_DotProduct(const  Vector3D* vec1, const  Vector3D* vec2)
{
	double result = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
	return result;
}

void Vector3_CrossProduct(const  Vector3D* vec1, const  Vector3D* vec2,  Vector3D* returnVec)
{
	returnVec->x = (vec1->y * vec2->z) - (vec1->z * vec2->y);
	returnVec->y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	returnVec->z = (vec1->x * vec2->y) - (vec1->y * vec2->x);

	//// Assert that the new vector is 0 or approaches zero
	////constexpr double eps = std::numeric_limits<double>::epsilon();/*
	//assert(DotProduct(tempVec, vec1) <= eps);
	//assert(DotProduct(tempVec, vec2) <= eps);*/
}

double Vector3_GetVectorsAngle(const  Vector3D* vec1, const  Vector3D* vec2)
{
	double dotProd = Vector3_DotProduct(vec1, vec2);
	double vec1Magnitude = Vector3_Magnitude(vec1);
	double vec2Magnitude = Vector3_Magnitude(vec2);
	double angle = acos(dotProd / (vec1Magnitude * vec2Magnitude));

	return angle;
}

int Vector3_Equality(const  Vector3D* vec1, const  Vector3D* vec2)
{
	 Vector3D norm1;
	 Vector3D norm2;

	Vector3_GetNormalizedVector(vec1, &norm1);
	Vector3_GetNormalizedVector(vec2, &norm2);
	return (abs((int)(norm1.x - norm2.x)) <= DBL_EPSILON) && (abs((int)(norm1.y - norm2.y)) <= DBL_EPSILON) && (abs((int)(norm1.z - norm2.z)) <= DBL_EPSILON);
}