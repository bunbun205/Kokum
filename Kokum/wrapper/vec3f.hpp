#pragma once

extern "C" {
	void kokum_vec3f_add(const float* a, const float* b, float* result);
	void kokum_vec3f_sub(const float* a, const float* b, float* result);
	void kokum_vec3f_mul(const float* a, const float* b, float* result);
	void kokum_vec3f_div(const float* a, const float* b, float* result);
	void kokum_vec3f_scalar_mul(const float* a, const float* b, float* result);
	void kokum_vec3f_scalar_div(const float* a, const float* b, float* result);
	float kokum_vec3f_dot(const float* a, const float* b);
	void kokum_vec3f_negate(const float* a, float* result);
	void kokum_vec3f_abs(const float* a, float* result);
	void kokum_vec3f_min(const float* a, const float* b, float* result);
	void kokum_vec3f_max(const float* a, const float* b, float* result);
	void kokum_vec3f_norm(const float* a, float* result);
}

namespace kokum{
	class alignas(16) vec3f {
	public:
		inline vec3f() : x(0.f), y(0.f), z(0.f), _padding(0.f) {}
		inline vec3f(const float x_, const float y_) : x(x_), y(y_), z(0.f), _padding(0.f) {}
		inline explicit vec3f(vec2f a) : x(a.X()), y(a.Y()), z(0), _padding(0.f) {}
		inline vec3f(vec2f a, const float z_) : x(a.X()), y(a.Y()), z(z_), _padding(0.f) {}
		inline vec3f(const float x_, const float y_, const float z_) : x(x_), y(y_), z(z_), _padding(0.f) {}

	public:
		[[nodiscard]] inline float X() const { return x; }
		[[nodiscard]] inline float Y() const { return y; }
		[[nodiscard]] inline float Z() const { return z; }
		inline float& X() { return x; }
		inline float& Y() { return y; }
		inline float& Z() { return z; }

		inline float operator [](const int i) const {
			return i == 0 ? x : i == 1 ? y : z;
		}

		inline float& operator [](const int i) {
			return i == 0 ? x : i == 1 ? y : z;
		}

		inline vec3f operator +(const vec3f& b) const {
			return Add(*this, b);
		}

		inline vec3f operator -(const vec3f& b) const {
			return Sub(*this, b);
		}

		inline vec3f operator -() const {
			return Negate(*this);
		}

		inline vec3f operator *(const vec3f& b) const {
			return Mul(*this, b);
		}

		inline vec3f operator /(const vec3f& b) const {
			return Div(*this, b);
		}

		inline vec3f operator *(const float b) const {
			return Mul(*this, b);
		}

		inline vec3f operator /(const float b) const {
			return Div(*this, b);
		}

		inline static vec3f Add(const vec3f& a, const vec3f& b) {
			vec3f r;
			kokum_vec3f_add(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3f Sub(const vec3f& a, const vec3f& b) {
			vec3f r;
			kokum_vec3f_sub(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3f Mul(const vec3f& a, const vec3f& b) {
			vec3f r;
			kokum_vec3f_mul(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3f Div(const vec3f& a, const vec3f& b) {
			vec3f r;
			kokum_vec3f_div(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3f Mul(const vec3f& a, const float b) {
			vec3f r;
			kokum_vec3f_scalar_mul(&a.x, &b, &r.x);
			return r;
		}

		inline static vec3f Mul(const float a, const vec3f& b) {
			return Mul(b, a);
		}

		inline static vec3f Div(const vec3f& a, const float b) {
			vec3f r;
			kokum_vec3f_scalar_div(&a.x, &b, &r.x);
			return r;
		}

		inline static float Dot(const vec3f& a, const vec3f& b) {
			return kokum_vec3f_dot(&a.x, &b.x);
		}

		inline static vec3f Negate(const vec3f& a) {
			vec3f r;
			kokum_vec3f_negate(&a.x, &r.x);
			return r;
		}

		inline static vec3f Abs(const vec3f& a) {
			vec3f r;
			kokum_vec3f_abs(&a.x, &r.x);
			return r;
		}

		inline static vec3f Min(const vec3f& a, const vec3f& b) {
			vec3f r;
			kokum_vec3f_min(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3f Max(const vec3f& a, const vec3f& b) {
			vec3f r;
			kokum_vec3f_max(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3f Norm(const vec3f& a) {
			vec3f r;
			kokum_vec3f_norm(&a.x, &r.x);
			return r;
		}

	private:
		float x, y, z;
		float _padding;
	};
} // namespace kokum
