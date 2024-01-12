#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
using namespace Catch::Matchers;
#include <smol/space3d.hpp>
using namespace Smol::Space3D;
#include <cmath>


TEST_CASE("Vector Constructors", "[unit, vector]")
{
	Vector v1;
	Vector v2{ 15.0f };
	Vector v3{ 3.0f, 5.0f, 9.0f };
	
	SECTION("Empty Constructor")
	{
		REQUIRE(v1.x == 0.0f);
		REQUIRE(v1.y == 0.0f);
		REQUIRE(v1.z == 0.0f);
	}
	
	SECTION("Single-value Constructor")
	{
		REQUIRE(v2.x == 15.0f);
		REQUIRE(v2.y == 15.0f);
		REQUIRE(v2.z == 15.0f);
	}
	
	SECTION("Memberwise Constructor")
	{
		REQUIRE(v3.x == 3.0f);
		REQUIRE(v3.y == 5.0f);
		REQUIRE(v3.z == 9.0f);
	}
}


TEST_CASE("Vector Operators", "[unit, vector]")
{
	Vector v1{ 15.0f, 8.0f, 4.0f };
	Vector v2{ 23.0f, 1.0f, 9.0f };
	
	SECTION("Addition")
	{
		const auto r1 = v1 + v2;
		REQUIRE(r1.x == 38.0f);
		REQUIRE(r1.y == 9.0f);
		REQUIRE(r1.z == 13.0f);
	}
	
	SECTION("Subtraction")
	{
		const auto r1 = v1 - v2;
		REQUIRE(r1.x == -8.0f);
		REQUIRE(r1.y == 7.0f);
		REQUIRE(r1.z == -5.0f);
	}
	
	SECTION("Multiplication")
	{
		const auto r1 = v1 * v2;
		REQUIRE(r1.x == 345.0f);
		REQUIRE(r1.y == 8.0f);
		REQUIRE(r1.z == 36.0f);
		
		const auto r2 = v1 * 2.0f;
		REQUIRE(r2.x == 30.0f);
		REQUIRE(r2.y == 16.0f);
		REQUIRE(r2.z == 8.0f);
		
		const auto r3 = 3.0f * v2;
		REQUIRE(r3.x == 69.0f);
		REQUIRE(r3.y == 3.0f);
		REQUIRE(r3.z == 27.0f);
	}
	
	SECTION("Division")
	{
		const auto r1 = v1 / v2;
		REQUIRE(r1.x == (15.0f / 23.0f));
		REQUIRE(r1.y == 8.0f);
		REQUIRE(r1.z == (4.0f / 9.0f));
		
		const auto r2 = v1 / 2.0f;
		REQUIRE(r2.x == 7.5f);
		REQUIRE(r2.y == 4.0f);
		REQUIRE(r2.z == 2.0f);
	}
}


TEST_CASE("Vector Methods", "[unit, vector]")
{
	const auto epsilon = 0.001f;
	Vector v1{ 3.0f, 5.0f, 8.0f };
	
	SECTION("Length")
	{
		REQUIRE_THAT(v1.GetLength(), WithinAbs(9.899f, epsilon));
	}
	
	SECTION("Normals")
	{
		const auto n1 = v1.GetNormal();
		REQUIRE_THAT(n1.x, WithinAbs(0.303f, epsilon));
		REQUIRE_THAT(n1.y, WithinAbs(0.505f, epsilon));
		REQUIRE_THAT(n1.z, WithinAbs(0.808f, epsilon));
		
		auto copy = v1;
		copy.Normalize();
		REQUIRE_THAT(copy.x, WithinAbs(0.303f, epsilon));
		REQUIRE_THAT(copy.y, WithinAbs(0.505f, epsilon));
		REQUIRE_THAT(copy.z, WithinAbs(0.808f, epsilon));
	}
}