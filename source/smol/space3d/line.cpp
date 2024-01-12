#include "line.hpp"

#include "ray.hpp"


Smol::Space3D::Vector Smol::Space3D::Line::GetSize() const
{
	return b - a;
}


Smol::Space3D::Ray Smol::Space3D::Line::GetRay() const
{
	return { a, (b - a).GetNormal() };
}