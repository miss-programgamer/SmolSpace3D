#ifndef SMOL_SPACE3D_BOUNDS_DEFINED
#define SMOL_SPACE3D_BOUNDS_DEFINED


#include "./vector.hpp"


namespace Smol::Space3D
{
	// Bounds in 3D space defined by a center and extents in each direction.
	struct Bounds
	{
		Vector center, extents;
		
		
	 public:
		// Construct empty bounds from zero to zero.
		constexpr Bounds() noexcept:
			center(0.0f), extents(0.0f)
		{}
		
		// Construct bounds from min to max.
		constexpr Bounds(const Vector& center, const Vector& extents) noexcept:
			center(center), extents(extents)
		{}
		
		
		// Grow these bounds by v in every direction.
		void Grow(float v);
		
		// Grow these bounds by v in each direction.
		void Grow(const Vector& v);
		
		// Grow these bounds to encompass the other bounds.
		void Encompass(const Bounds& other);
		
		
		// Get the minimum point of these bounds.
		Vector GetMin() const;
		
		// Get the maximum point of these bounds.
		Vector GetMax() const;
		
		// Get the size of these bounds.
		Vector GetSize() const;
	};
}


#else // SMOL_SPACE3D_BOUNDS_DEFINED


namespace Smol::Space3D
{
	struct Bounds;
}


#endif // SMOL_SPACE3D_BOUNDS_DEFINED