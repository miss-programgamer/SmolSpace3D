#ifndef SMOL_SPACE3D_VECTOR_DEFINED
#define SMOL_SPACE3D_VECTOR_DEFINED


namespace Smol::Space3D
{
	// A vector composed of three float components.
	struct Vector
	{
		float x, y, z;
		
		
	 public:
		// Construct a zero vector.
		constexpr Vector() noexcept:
			x(0.0f), y(0.0f), z(0.0f)
		{}
		
		// Construct a vector where all elements are v.
		explicit constexpr Vector(float v) noexcept:
			x(v), y(v), z(v)
		{}
		
		// Construct a vector composed of x, y, and z.
		constexpr Vector(float x, float y, float z) noexcept:
			x(x), y(y), z(z)
		{}
		
		
		// Normalize this vector.
		void Normalize();
		
		
		// Get the length of this vector.
		float GetLength() const;
		
		// Construct and return the normal of this vector.
		Vector GetNormal() const;
	};
	
	
	constexpr Vector Zero    = {  0.0f,  0.0f,  0.0f };
	constexpr Vector One     = {  1.0f,  1.0f,  1.0f };
	
	constexpr Vector Up      = {  0.0f,  1.0f,  0.0f };
	constexpr Vector Down    = {  0.0f, -1.0f,  0.0f };
	constexpr Vector Left    = { -1.0f,  0.0f,  0.0f };
	constexpr Vector Right   = {  1.0f,  0.0f,  0.0f };
	constexpr Vector Forward = {  0.0f,  0.0f,  1.0f };
	constexpr Vector Back    = {  0.0f,  0.0f, -1.0f };
	
	
	Vector operator+(const Vector& lhs, const Vector& rhs);
	Vector operator-(const Vector& lhs, const Vector& rhs);
	Vector operator*(const Vector& lhs, const Vector& rhs);
	Vector operator/(const Vector& lhs, const Vector& rhs);
	
	Vector operator*(float lhs, const Vector& rhs);
	Vector operator*(const Vector& lhs, float rhs);
	Vector operator/(const Vector& lhs, float rhs);
	
	Vector& operator+=(Vector& lhs, const Vector& rhs);
	Vector& operator-=(Vector& lhs, const Vector& rhs);
	Vector& operator*=(Vector& lhs, const Vector& rhs);
	Vector& operator/=(Vector& lhs, const Vector& rhs);
	
	Vector& operator*=(Vector& lhs, float rhs);
	Vector& operator/=(Vector& lhs, float rhs);
}


#else // SMOL_SPACE3D_VECTOR_DEFINED


namespace Smol::Space3D
{
	struct Vector;
}


#endif // SMOL_SPACE3D_VECTOR_DEFINED