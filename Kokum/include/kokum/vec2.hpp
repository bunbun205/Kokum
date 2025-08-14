#pragma once

#include "vec2i.hpp"
#include "vec2f.hpp"
#include "vec2d.hpp"
#include <concepts>

namespace kokum {

	template<typename T>
	concept isInt = std::integral<T>;

	template<typename T>
	concept isFloat = std::floating_point<T>;

	// (int, int) -> Vector2i
	template<typename T1, typename T2>
	requires (isInt<T1> && isInt<T2>)
	auto vec2(T1 x, T2 y) {
		return vec2i(static_cast<int32_t>(x), static_cast<int32_t>(y));
	}

	// (float, float) -> Vector2f
	template<typename T1, typename T2>
	requires (isFloat<T1> && isFloat<T2>)
	auto vec2(T1 x, T2 y) {
		return vec2f(static_cast<float>(x), static_cast<float>(y));
	}

	// Mixed (int,float) or (float,int) -> Vector2f
	template<typename T1, typename T2>
	requires (
	    (isInt<T1> && isFloat<T2>) ||
	    (isFloat<T1> && isInt<T2>)
	)
	auto vec2(T1 x, T2 y) {
		return vec2f(static_cast<float>(x), static_cast<float>(y));
	}

} // namespace kokum
