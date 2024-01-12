#ifndef SMOL_SPACE3D_LINE_DEFINED
#define SMOL_SPACE3D_LINE_DEFINED


#include "vector.hpp"


namespace Smol::Space3D
{
	struct Ray;
	
	// A line, stored as two points A and B.
	struct Line
	{
		Vector a, b;
		
		
	 public:
		// Construct a line from zero to zero.
		constexpr Line() noexcept:
			a(0.0f), b(0.0f)
		{}
		
		
		// Get the size of this line.
		Vector GetSize() const;
		
		// Get a ray from point A pointing to point B.
		Ray GetRay() const;
	};
}


#else // SMOL_SPACE3D_LINE_DEFINED


namespace Smol::Space3D
{
	struct Line;
}


#endif // SMOL_SPACE3D_LINE_DEFINED