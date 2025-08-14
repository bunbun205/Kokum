#pragma once
#include <stdexcept>

extern "C" {
	void kokum_vec2d_add(const double* a, const double* b, double* result);
	void kokum_vec2d_sub(const double* a, const double* b, double* result);
	void kokum_vec2d_mul(const double* a, const double* b, double* result);
	void kokum_vec2d_div(const double* a, const double* b, double* result);
	void kokum_vec2d_scalar_mul(const double* a, const double* b, double* result);
	void kokum_vec2d_scalar_div(const double* a, const double* b, double* result);
	double kokum_vec2d_dot(const double* a, const double* b);
	void kokum_vec2d_negate(const double* a, double* result);
	void kokum_vec2d_abs(const double* a, double* result);
	void kokum_vec2d_min(const double* a, const double* b, double* result);
	void kokum_vec2d_max(const double* a, const double* b, double* result);
	void kokum_vec2d_norm(const double* a, double* result);
}

namespace kokum{
	class alignas(16) vec2d {
	public:
		inline vec2d() : x(0.f), y(0.f), _padding{0.f, 0.f} {}
		inline vec2d(const double x_, const double y_) : x(x_), y(y_), _padding{0.f, 0.f} {}

	public:
		[[nodiscard]] inline double X() const { return x; }
		[[nodiscard]] inline double Y() const { return y; }
		inline double& X() { return x; }
		inline double& Y() { return y; }

		inline double operator [](const int i) const {
			if (i == 0) return x;
			if (i == 1) return y;
			throw std::out_of_range("vec2d index out of range");
		}

		inline double& operator[](const int i) {
			if (i == 0) return x;
			if (i == 1) return y;
			throw std::out_of_range("vec2d index out of range");
		}

		inline vec2d operator +=(const vec2d& b) {
			*this = Add(*this, b);
			return *this;
		}

		inline vec2d operator -=(const vec2d& b) {
			*this = Sub(*this, b);
			return *this;
		}

		inline vec2d operator *=(const vec2d& b) {
			*this = Mul(*this, b);
			return *this;
		}

		inline vec2d operator *=(const double b) {
			*this = Mul(*this, b);
			return *this;
		}

		inline vec2d operator /=(const double b) {
			*this = Div(*this, b);
			return *this;
		}

		inline vec2d operator /=(const vec2d& b) {
			*this = Div(*this, b);
			return *this;
		}

		inline bool operator ==(const vec2d& b) const {
			return x == b.x && y == b.y;
		}

		inline bool operator !=(const vec2d& b) const {
			return x != b.x || y != b.y;
		}

		inline vec2d operator +(const vec2d& b) const {
			return Add(*this, b);
		}

		inline vec2d operator -(const vec2d& b) const {
			return Sub(*this, b);
		}

		inline vec2d operator -() const {
			return Negate(*this);
		}

		inline vec2d operator *(const vec2d& b) const {
			return Mul(*this, b);
		}

		inline vec2d operator /(const vec2d& b) const {
			return Div(*this, b);
		}

		inline vec2d operator *(const double b) const {
			return Mul(*this, b);
		}

		inline vec2d operator /(const double b) const {
			return Div(*this, b);
		}

		static vec2d Add(const vec2d& a, const vec2d& b) {
			vec2d r;
			kokum_vec2d_add(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2d Sub(const vec2d& a, const vec2d& b) {
			vec2d r;
			kokum_vec2d_sub(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2d Mul(const vec2d& a, const vec2d& b) {
			vec2d r;
			kokum_vec2d_mul(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2d Div(const vec2d& a, const vec2d& b) {
			vec2d r;
			kokum_vec2d_div(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2d Mul(const vec2d& a, const double b) {
			vec2d r;
			kokum_vec2d_scalar_mul(&a.x, &b, &r.x);
			return r;
		}

		inline static vec2d Mul(const double a, const vec2d& b) {
			return Mul(b, a);
		}

		inline static vec2d Div(const vec2d& a, const double b) {
			vec2d r;
			kokum_vec2d_scalar_div(&a.x, &b, &r.x);
			return r;
		}

		inline static double Dot(const vec2d& a, const vec2d& b) {
			return kokum_vec2d_dot(&a.x, &b.x);
		}

		inline static vec2d Negate(const vec2d& a) {
			vec2d r;
			kokum_vec2d_negate(&a.x, &r.x);
			return r;
		}

		inline static vec2d Abs(const vec2d& a) {
			vec2d r;
			kokum_vec2d_abs(&a.x, &r.x);
			return r;
		}

		inline static vec2d Min(const vec2d& a, const vec2d& b) {
			vec2d r;
			kokum_vec2d_min(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2d Max(const vec2d& a, const vec2d& b) {
			vec2d r;
			kokum_vec2d_max(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec2d Norm(const vec2d& a) {
			vec2d r;
			kokum_vec2d_norm(&a.x, &r.x);
			return r;
		}

	private:
		double x, y;
		double _padding[2];
	};
}
