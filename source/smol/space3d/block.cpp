#include "block.hpp"


Smol::Space3D::Vector Smol::Space3D::Block::GetMax() const
{
	return pos + size;
}