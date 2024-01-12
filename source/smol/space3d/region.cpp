#include "region.hpp"

#include "block.hpp"
#include "bounds.hpp"


Smol::Space3D::Region::Region(const Block& block) noexcept:
	min(block.pos), max(block.GetMax())
{}


Smol::Space3D::Region::Region(const Bounds& bounds) noexcept:
	min(bounds.GetMin()), max(bounds.GetMax())
{}


Smol::Space3D::Vector Smol::Space3D::Region::GetSize() const
{
	return max - min;
}


Smol::Space3D::Vector Smol::Space3D::Region::GetCenter() const
{
	return 0.5f * (min + max);
}


bool Smol::Space3D::Region::Contains(const Vector& point) const
{
	return
		point.x >= min.x && point.y >= min.y && point.z >= min.z &&
		point.x < max.x && point.y < max.y && point.z < max.z;
}


bool Smol::Space3D::Region::Overlaps(const Region& other) const
{
	return !(
		other.max.x <= min.x || other.max.y <= min.y || other.max.z <= min.z ||
		other.min.x >= max.x || other.min.y >= max.y || other.min.z >= max.z
	);
}