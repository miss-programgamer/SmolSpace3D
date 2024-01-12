#include "vector.hpp"

#include <cmath>


// Vector must be aligned to four bytes
static_assert(alignof(Smol::Space3D::Vector) == 4);


void Smol::Space3D::Vector::Normalize()
{
	// TODO: handle case where length is 0
	
	float length = std::sqrtf(x * x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;
}


float Smol::Space3D::Vector::GetLength() const
{
	return std::sqrtf(x * x + y * y + z * z);
}


Smol::Space3D::Vector Smol::Space3D::Vector::GetNormal() const
{
	// TODO: handle case where length is 0
	
	float length = std::sqrtf(x * x + y * y + z * z);
	return { x / length, y / length, z / length };
}


/* ==================================================
	OPERATOR OVERLOAD IMPLEMENTATIONS
================================================== */

Smol::Space3D::Vector Smol::Space3D::operator+(const Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z }; }

Smol::Space3D::Vector Smol::Space3D::operator-(const Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z }; }

Smol::Space3D::Vector Smol::Space3D::operator*(const Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z }; }

Smol::Space3D::Vector Smol::Space3D::operator/(const Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z }; }

Smol::Space3D::Vector Smol::Space3D::operator*(float lhs, const Smol::Space3D::Vector& rhs)
{ return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z }; }

Smol::Space3D::Vector Smol::Space3D::operator*(const Smol::Space3D::Vector& lhs, float rhs)
{ return { lhs.x * rhs, lhs.y * rhs, lhs.z * rhs }; }

Smol::Space3D::Vector Smol::Space3D::operator/(const Smol::Space3D::Vector& lhs, float rhs)
{ return { lhs.x / rhs, lhs.y / rhs, lhs.z / rhs }; }

Smol::Space3D::Vector& Smol::Space3D::operator+=(Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ lhs = lhs + rhs; return lhs; }

Smol::Space3D::Vector& Smol::Space3D::operator-=(Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ lhs = lhs - rhs; return lhs; }

Smol::Space3D::Vector& Smol::Space3D::operator*=(Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ lhs = lhs * rhs; return lhs; }

Smol::Space3D::Vector& Smol::Space3D::operator/=(Smol::Space3D::Vector& lhs, const Smol::Space3D::Vector& rhs)
{ lhs = lhs / rhs; return lhs; }

Smol::Space3D::Vector& Smol::Space3D::operator*=(Smol::Space3D::Vector& lhs, float rhs)
{ lhs = lhs * rhs; return lhs; }

Smol::Space3D::Vector& Smol::Space3D::operator/=(Smol::Space3D::Vector& lhs, float rhs)
{ lhs = lhs / rhs; return lhs; }