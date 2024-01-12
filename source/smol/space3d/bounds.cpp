#include "./bounds.hpp"

#include <algorithm>


void Smol::Space3D::Bounds::Grow(float v)
{
	extents.x += v;
	extents.y += v;
	extents.z += v;
}


void Smol::Space3D::Bounds::Grow(const Vector& v)
{
	extents.x += v.x;
	extents.y += v.y;
	extents.z += v.z;
}


void Smol::Space3D::Bounds::Encompass(const Bounds& other)
{
	const auto min = center - extents;
	const auto max = center + extents;
	const auto omin = other.GetMin();
	const auto omax = other.GetMax();
	
	const auto minx = std::min(min.x, omin.x);
	const auto miny = std::min(min.y, omin.y);
	const auto minz = std::min(min.z, omin.z);
	
	const auto maxx = std::max(max.x, omax.x);
	const auto maxy = std::max(max.y, omax.y);
	const auto maxz = std::max(max.z, omax.z);
	
	center = {
		0.5f * (minx + maxx),
		0.5f * (miny + maxy),
		0.5f * (minz + maxz),
	};
	
	extents = {
		0.5f * (maxx - minx),
		0.5f * (maxy - miny),
		0.5f * (maxz - minz),
	};
}


Smol::Space3D::Vector Smol::Space3D::Bounds::GetMin() const
{
	return center - extents;
}


Smol::Space3D::Vector Smol::Space3D::Bounds::GetMax() const
{
	return center + extents;
}


Smol::Space3D::Vector Smol::Space3D::Bounds::GetSize() const
{
	return 2.0f * extents;
}