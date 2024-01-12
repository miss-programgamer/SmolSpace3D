#ifndef SMOL_SPACE3D_RAY_DEFINED
#define SMOL_SPACE3D_RAY_DEFINED


#include "./vector.hpp"


namespace Smol::Space3D
{
	struct Ray
	{
		Vector pos, dir;
		
		
	 public:
		// Construct a ray at zero pointing forward.
		constexpr Ray() noexcept:
			pos(0.0f), dir(Forward)
		{}
		
		// Construct a ray at a given position and direction.
		constexpr Ray(const Vector& pos, const Vector& dir) noexcept:
			pos(pos), dir(dir)
		{}
	};
}


#else // SMOL_SPACE3D_RAY_DEFINED


namespace Smol::Space3D
{
	struct Ray;
}


#endif // SMOL_SPACE3D_RAY_DEFINED