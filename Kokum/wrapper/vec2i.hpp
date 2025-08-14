#pragma once

#include <stdexcept>

namespace kokum{
	class vec2f;
}

extern "C" {
void kokum_vec2i_add(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec2i_sub(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec2i_mul(const int32_t* a, const int32_t* b, int32_t* result);
int32_t kokum_vec2i_dot(const int32_t* a, const int32_t* b);
void kokum_vec2i_negate(const int32_t* a, int32_t* result);
void kokum_vec2i_abs(const int32_t* a, int32_t* result);
void kokum_vec2i_min(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec2i_max(const int32_t* a, const int32_t* b, int32_t* result);
}

namespace kokum{
	class alignas(16) vec2i {
	public:
		inline vec2i() : x(0), y(0), _padding{0, 0} {}
		inline vec2i(const int32_t x_, const int32_t y_) : x(x_), y(y_), _padding{0, 0} {}

	public:
		[[nodiscard]] inline int32_t X() const { return x; }
		[[nodiscard]] inline int32_t Y() const { return y; }
		inline int32_t& X() { return x; }
		inline int32_t& Y() { return y; }

		inline int32_t operator [](const int i) const {
			if (i == 0) return x;
			if (i == 1) return y;
			throw std::out_of_range("vec2f index out of range");
		}

		inline int32_t& operator[](const int i) {
			if (i == 0) return x;
			if (i == 1) return y;
			throw std::out_of_range("vec2f index out of range");
		}

		inline vec2i operator +(const vec2i& b) const {
			return Add(*this, b);
		}

		inline vec2i operator -(const vec2i& b) const {
			return Sub(*this, b);
		}

		inline vec2i operator -() const {
			return Negate(*this);
		}

		inline vec2i operator *(const vec2i& b) const {
			return Mul(*this, b);
		}

		inline static vec2i Add(const vec2i& a, const vec2i& b) {
			vec2i r;
			kokum_vec2i_add(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2i Sub(const vec2i& a, const vec2i& b) {
			vec2i r;
			kokum_vec2i_sub(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2i Mul(const vec2i& a, const vec2i& b) {
			vec2i r;
			kokum_vec2i_mul(&a.x, &b.x, &r.x);
			return r;
		}

		inline static int32_t Dot(const vec2i& a, const vec2i& b) {
			return kokum_vec2i_dot(&a.x, &b.x);
		}

		inline static vec2i Negate(const vec2i& a) {
			vec2i r;
			kokum_vec2i_negate(&a.x, &r.x);
			return r;
		}

		inline static vec2i Abs(const vec2i& a) {
			vec2i r;
			kokum_vec2i_abs(&a.x, &r.x);
			return r;
		}

		inline static vec2i Min(const vec2i& a, const vec2i& b) {
			vec2i r;
			kokum_vec2i_min(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2i Max(const vec2i& a, const vec2i& b) {
			vec2i r;
			kokum_vec2i_max(&a.x, &b.x, &r.x);
			return r;
		}

	private:
		int32_t x, y;
		int32_t _padding[2];
	};
} // namespace kokum
