#define _USE_MATH_DEFINES

#include "../headers/vector2.h"
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

void Vector2_AddVectors(const Vector2D* vec1, const Vector2D* vec2, Vector2D* returnVec)
{
	returnVec->x = vec1->x + vec2->x;
	returnVec->y = vec1->y + vec2->y;
}

void Vector2_SubstractVectors(const Vector2D* vec1, const Vector2D* vec2, Vector2D* returnVec)
{
	returnVec->x = vec1->x - vec2->x;
	returnVec->y = vec1->y - vec2->y;
}

void Vector2_ScalarMultiplication(const Vector2D* vec, double scalar, Vector2D* returnVec)
{
	returnVec->x = vec->x * scalar;
	returnVec->y = vec->y * scalar;
}

double Vector2_Magnitude(const Vector2D* vec)
{
	return sqrt(pow(vec->x, 2) + pow(vec->y, 2));
}

void Vector2_GetNormalizedVector(const Vector2D* vec, Vector2D* returnVec)
{
	double magnitude = Vector2_Magnitude(vec);

	returnVec->x = vec->x / magnitude;
	returnVec->y = vec->y / magnitude;
}

double Vector2_DotProduct(const Vector2D* vec1, const Vector2D* vec2)
{
	double result = (vec1->x * vec2->x) + (vec1->y * vec2->y);
	return result;
}

double Vector2_GetVectorsAngle(const Vector2D* vec1, const Vector2D* vec2)
{
	double dotProd = Vector2_DotProduct(vec1, vec2);
	double vec1Magnitude = Vector2_Magnitude(vec1);
	double vec2Magnitude = Vector2_Magnitude(vec2);
	double angle = acos(dotProd / (vec1Magnitude * vec2Magnitude));

	return angle;
}

int Vector2_Equality(const Vector2D* vec1, const Vector2D* vec2)
{
	Vector2D norm1;
	Vector2D norm2;

	Vector2_GetNormalizedVector(vec1, &norm1);
	Vector2_GetNormalizedVector(vec2, &norm2);
	return (abs((int)(norm1.x - norm2.x)) <= DBL_EPSILON) && (abs((int)(norm1.y - norm2.y)) <= DBL_EPSILON);
}

void Vector2_GetPerpendicularVector(const Vector2D* vec, Vector2D* returnVec)
{
	returnVec->x = -vec->y;
	returnVec->y = vec->x;
}