#ifndef SMOL_SPACE3D_REGION_DEFINED
#define SMOL_SPACE3D_REGION_DEFINED


#include "./vector.hpp"


namespace Smol::Space3D
{
	struct Block;
	struct Bounds;
	
	// Region in 3D space defined by a minimum and maximum vector.
	struct Region
	{
		Vector min, max;
		
		
	 public:
		// Construct an empty region from zero to zero.
		constexpr Region() noexcept:
			min(0.0f), max(0.0f)
		{}
		
		// Construct a region from min to max.
		constexpr Region(const Vector& min, const Vector& max) noexcept:
			min(min), max(max)
		{}
		
		// Construct a region from a block.
		explicit Region(const Block& block) noexcept;
		
		// Construct a region from bounds.
		explicit Region(const Bounds& bounds) noexcept;
		
		
		// Get the size of this region.
		Vector GetSize() const;
		
		// Get the center of this region.
		Vector GetCenter() const;
		
		// Check whether this region contain the given point.
		bool Contains(const Vector& point) const;
		
		// Check whether this region overlap with the other region.
		bool Overlaps(const Region& other) const;
	};
}


#else // SMOL_SPACE3D_REGION_DEFINED


namespace Smol::Space3D
{
	struct Region;
}


#endif // SMOL_SPACE3D_REGION_DEFINED