#ifndef SMOL_SPACE3D_BLOCK_DEFINED
#define SMOL_SPACE3D_BLOCK_DEFINED


#include "./vector.hpp"


namespace Smol::Space3D
{
	// Block in 3D space defined by a position and size.
	struct Block
	{
		Vector size, pos;
		
		
	 public:
		// Contruct a block of size zero at position zero.
		constexpr Block() noexcept:
			size(0.0f), pos(0.0f)
		{}
		
		// Construct a block of the given size at the given position.
		constexpr Block(const Vector& size, const Vector& pos) noexcept:
			size(size), pos(pos)
		{}
		
		
		// Get the corner of this block opposite of its origin.
		Vector GetMax() const;
	};
}


#else // SMOL_SPACE3D_BLOCK_DEFINED


namespace Smol::Space3D
{
	struct Block;
}


#endif // SMOL_SPACE3D_BLOCK_DEFINED