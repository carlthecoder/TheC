#ifndef LIBKIT_CTC_VECTOR3_H
#define LIBKIT_CTC_VECTOR3_H

// #ifdef LIBKIT_EXPORTS
// #define DECLSPEC_API __declspec(dllexport)
// #else
// #define DECLSPEC_API __declspec(dllimport)
// #endif

#include "vectors.h"

/// <summary>
/// Returns the addition of 2 vectors as a new vector.
/// Vector addition maps the second vector onto the end of the first vector.
/// </summary>
void Vector3_AddVectors(const  Vector3D* vec1, const  Vector3D* vec2, Vector3D* returnVec);

/// <summary>
/// Returns the substraction of 2 vectors as a new vector.
/// Vector substraction results in the vector going from the end of the second vector to the end of the first vector.
/// </summary>
void Vector3_SubstractVectors(const  Vector3D* vec1, const  Vector3D* vec2, Vector3D* returnVec);

/// <summary>
/// Returns the scalar multiplication of a vector as a new vector.
/// Scalar multiplication lengthens, shortens or flips a vector.
/// - a scalar larger than 1 will lengthen.
/// - a scalar smaller than 1 but larger than 0 will shorten.
/// - a negative scalar will flip the direction.
/// - multiplying with 0 will create a zero vector.
/// </summary>
void Vector3_ScalarMultiplication(const Vector3D* vec, double scalar, Vector3D* returnVec);

/// <summary>
/// Returns the magnituted of a vector (i.e. the length of a vector).
/// The magnitude of a 2D vector is calculated by applying Pythagorean on the x and y of the vector.
/// - Magnitude = Sqrt(x� + y�)
/// </summary>
double Vector3_Magnitude(const Vector3D* vec);

/// <summary>
/// Returns the normalized vector.
/// Normalizing a vector is converting a vector to have a agnitude of 1.
/// Normalizing is done by dividing both the x and the y conponent by the vectors magnitude.
/// </summary>
void Vector3_GetNormalizedVector(const Vector3D* vec, Vector3D* returnVec);

/// <summary>
/// Returns a scalar that is the direct result of vector multiplication.
/// - DotProd = vec1 * vec2 = (vec1.x * vec2.x) + (vec1.y * vec2.y)
/// </summary>
double Vector3_DotProduct(const Vector3D* vec1, const Vector3D* vec2);

/// <summary>
/// Returns the cross product.
/// The cross product calculates a new vector that is perpendicular to both given 3 dimensional vectors.
/// - crossproduct = > vec1 x vec2 = Vector3D( (vec1.y * vec2.z - vec1.z * vec2.y), (vec1.z * vec2.x - vec1.x * vec2.z), (vec1.x * vec2.y - vec1.y * vec2.x) );
/// </summary>
void Vector3_CrossProduct(const Vector3D* vec1, const Vector3D* vec2, Vector3D* returnVec);

/// <summary>
/// Returns the angle between 2 vectors.
/// The angle is returned in radians. Multiply the result with 180 / M_PI to get degrees.
/// The angle is calculated by using trigonometry: the inverse cosine of the ratio of the dotproduct over the product of the vectors magnitudes.
/// angle = acos((vec1 * vec2) / (magnitudeVec1 * magnitudeVec2))
/// </summary>
double Vector3_GetVectorsAngle(const Vector3D* vec1, const Vector3D* vec2);

/// <summary>
/// Checks if 2 vectors are equal.
/// Equality is true if the both vectors have the same direction and magnitude.
/// </summary>
int Vector3_Equality(const Vector3D* vec1, const Vector3D* vec2);

#endif