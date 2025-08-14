#pragma once
#include <stdexcept>

extern "C" {
	void kokum_vec2f_add(const float* a, const float* b, float* result);
	void kokum_vec2f_sub(const float* a, const float* b, float* result);
	void kokum_vec2f_mul(const float* a, const float* b, float* result);
	void kokum_vec2f_div(const float* a, const float* b, float* result);
	void kokum_vec2f_scalar_mul(const float* a, const float* b, float* result);
	void kokum_vec2f_scalar_div(const float* a, const float* b, float* result);
	float kokum_vec2f_dot(const float* a, const float* b);
	void kokum_vec2f_negate(const float* a, float* result);
	void kokum_vec2f_abs(const float* a, float* result);
	void kokum_vec2f_min(const float* a, const float* b, float* result);
	void kokum_vec2f_max(const float* a, const float* b, float* result);
	void kokum_vec2f_norm(const float* a, float* result);
}

namespace kokum{
	class alignas(16) vec2f {
	public:
		inline vec2f() : x(0.f), y(0.f), _padding{0.f, 0.f} {}
		inline vec2f(const float x_, const float y_) : x(x_), y(y_), _padding{0.f, 0.f} {}

	public:
		[[nodiscard]] inline float X() const { return x; }
		[[nodiscard]] inline float Y() const { return y; }
		inline float& X() { return x; }
		inline float& Y() { return y; }

		inline float operator [](const int i) const {
			if (i == 0) return x;
			if (i == 1) return y;
			throw std::out_of_range("vec2f index out of range");
		}

		inline float& operator[](const int i) {
			if (i == 0) return x;
			if (i == 1) return y;
			throw std::out_of_range("vec2f index out of range");
		}

		inline vec2f operator +=(const vec2f& b) {
			*this = Add(*this, b);
			return *this;
		}

		inline vec2f operator -=(const vec2f& b) {
			*this = Sub(*this, b);
			return *this;
		}

		inline vec2f operator *=(const vec2f& b) {
			*this = Mul(*this, b);
			return *this;
		}

		inline vec2f operator *=(const float b) {
			*this = Mul(*this, b);
			return *this;
		}

		inline vec2f operator /=(const float b) {
			*this = Div(*this, b);
			return *this;
		}

		inline vec2f operator /=(const vec2f& b) {
			*this = Div(*this, b);
			return *this;
		}

		inline bool operator ==(const vec2f& b) const {
			return x == b.x && y == b.y;
		}

		inline bool operator !=(const vec2f& b) const {
			return x != b.x || y != b.y;
		}

		inline vec2f operator +(const vec2f& b) const {
			return Add(*this, b);
		}

		inline vec2f operator -(const vec2f& b) const {
			return Sub(*this, b);
		}

		inline vec2f operator -() const {
			return Negate(*this);
		}

		inline vec2f operator *(const vec2f& b) const {
			return Mul(*this, b);
		}

		inline vec2f operator /(const vec2f& b) const {
			return Div(*this, b);
		}

		inline vec2f operator *(const float b) const {
			return Mul(*this, b);
		}

		inline vec2f operator /(const float b) const {
			return Div(*this, b);
		}

		static vec2f Add(const vec2f& a, const vec2f& b) {
			vec2f r;
			kokum_vec2f_add(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2f Sub(const vec2f& a, const vec2f& b) {
			vec2f r;
			kokum_vec2f_sub(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2f Mul(const vec2f& a, const vec2f& b) {
			vec2f r;
			kokum_vec2f_mul(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2f Div(const vec2f& a, const vec2f& b) {
			vec2f r;
			kokum_vec2f_div(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2f Mul(const vec2f& a, const float b) {
			vec2f r;
			kokum_vec2f_scalar_mul(&a.x, &b, &r.x);
			return r;
		}

		inline static vec2f Mul(const float a, const vec2f& b) {
			return Mul(b, a);
		}

		inline static vec2f Div(const vec2f& a, const float b) {
			vec2f r;
			kokum_vec2f_scalar_div(&a.x, &b, &r.x);
			return r;
		}

		inline static float Dot(const vec2f& a, const vec2f& b) {
			return kokum_vec2f_dot(&a.x, &b.x);
		}

		inline static vec2f Negate(const vec2f& a) {
			vec2f r;
			kokum_vec2f_negate(&a.x, &r.x);
			return r;
		}

		inline static vec2f Abs(const vec2f& a) {
			vec2f r;
			kokum_vec2f_abs(&a.x, &r.x);
			return r;
		}

		inline static vec2f Min(const vec2f& a, const vec2f& b) {
			vec2f r;
			kokum_vec2f_min(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2f Max(const vec2f& a, const vec2f& b) {
			vec2f r;
			kokum_vec2f_max(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2f Norm(const vec2f& a) {
			vec2f r;
			kokum_vec2f_norm(&a.x, &r.x);
			return r;
		}

	private:
		float x, y;
		float _padding[2];
	};
}
