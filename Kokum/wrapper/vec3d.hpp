#pragma once

extern "C" {
	void kokum_vec3d_add(const double* a, const double* b, double* result);
	void kokum_vec3d_sub(const double* a, const double* b, double* result);
	void kokum_vec3d_mul(const double* a, const double* b, double* result);
	void kokum_vec3d_div(const double* a, const double* b, double* result);
	void kokum_vec3d_scalar_mul(const double* a, const double* b, double* result);
	void kokum_vec3d_scalar_div(const double* a, const double* b, double* result);
	double kokum_vec3d_dot(const double* a, const double* b);
	void kokum_vec3d_negate(const double* a, double* result);
	void kokum_vec3d_abs(const double* a, double* result);
	void kokum_vec3d_min(const double* a, const double* b, double* result);
	void kokum_vec3d_max(const double* a, const double* b, double* result);
	void kokum_vec3d_norm(const double* a, double* result);
}

namespace kokum{
	class alignas(16) vec3d {
	public:
		inline vec3d() : x(0.f), y(0.f), z(0.f), _padding(0.f) {}
		inline vec3d(const double x_, const double y_) : x(x_), y(y_), z(0.f), _padding(0.f) {}
		inline explicit vec3d(vec2f a) : x(a.X()), y(a.Y()), z(0), _padding(0.f) {}
		inline vec3d(vec2f a, const double z_) : x(a.X()), y(a.Y()), z(z_), _padding(0.f) {}
		inline vec3d(const double x_, const double y_, const double z_) : x(x_), y(y_), z(z_), _padding(0.f) {}

	public:
		[[nodiscard]] inline double X() const { return x; }
		[[nodiscard]] inline double Y() const { return y; }
		[[nodiscard]] inline double Z() const { return z; }
		inline double& X() { return x; }
		inline double& Y() { return y; }
		inline double& Z() { return z; }

		inline double operator [](const int i) const {
			return i == 0 ? x : i == 1 ? y : z;
		}

		inline double& operator [](const int i) {
			return i == 0 ? x : i == 1 ? y : z;
		}

		inline vec3d operator +=(const vec3d& b) {
			*this = Add(*this, b);
			return *this;
		}

		inline vec3d operator -=(const vec3d& b) {
			*this = Sub(*this, b);
			return *this;
		}

		inline vec3d operator *=(const vec3d& b) {
			*this = Mul(*this, b);
			return *this;
		}

		inline vec3d operator *=(const double b) {
			*this = Mul(*this, b);
			return *this;
		}

		inline vec3d operator /=(const double b) {
			*this = Div(*this, b);
			return *this;
		}

		inline vec3d operator /=(const vec3d& b) {
			*this = Div(*this, b);
			return *this;
		}

		inline bool operator ==(const vec3d& b) {
			return this.x == b.x && this.y == b.y && this.z == b.z;
		}

		inline bool operator !=(const vec3d& b) {
			return this.x != b.x || this.y != b.y || this.z != b.z;
		}

		inline vec3d operator +(const vec3d& b) const {
			return Add(*this, b);
		}

		inline vec3d operator -(const vec3d& b) const {
			return Sub(*this, b);
		}

		inline vec3d operator -() const {
			return Negate(*this);
		}

		inline vec3d operator *(const vec3d& b) const {
			return Mul(*this, b);
		}

		inline vec3d operator *(const double b) const {
			return Mul(*this, b);
		}

		inline vec3d operator /(const double b) const {
			return Div(*this, b);
		}

		inline vec3d operator /(const vec3d& b) const {
			return Div(*this, b);
		}

		inline static vec3d Add(const vec3d& a, const vec3d& b) {
			vec3d r;
			kokum_vec3d_add(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3d Sub(const vec3d& a, const vec3d& b) {
			vec3d r;
			kokum_vec3d_sub(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3d Mul(const vec3d& a, const vec3d& b) {
			vec3d r;
			kokum_vec3d_mul(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3d Div(const vec3d& a, const vec3d& b) {
			vec3d r;
			kokum_vec3d_div(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3d Div(const vec3d& a, const double b) {
			vec3d r;
			kokum_vec3d_scalar_div(&a.x, &b, &r.x);
			return r;
		}

		inline static vec3d Mul(const vec3d& a, const double b) {
			vec3d r;
			kokum_vec3d_scalar_mul(&a.x, &b, &r.x);
			return r;
		}

		inline static vec3d Mul(const double a, const vec3d& b) {
			return Mul(b, a);
		}

		inline static double Dot(const vec3d& a, const vec3d& b) {
			return kokum_vec3d_dot(&a.x, &b.x);
		}

		inline static vec3d Negate(const vec3d& a) {
			vec3d r;
			kokum_vec3d_negate(&a.x, &r.x);
			return r;
		}

		inline static vec3d Abs(const vec3d& a) {
			vec3d r;
			kokum_vec3d_abs(&a.x, &r.x);
			return r;
		}

		inline static vec3d Min(const vec3d& a, const vec3d& b) {
			vec3d r;
			kokum_vec3d_min(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3d Max(const vec3d& a, const vec3d& b) {
			vec3d r;
			kokum_vec3d_max(&a.x, &b.x, &r.x);
			return r;
		}

		inline static vec3d Norm(const vec3d& a) {
			vec3d r;
			kokum_vec3d_norm(&a.x, &r.x);
			return r;
		}

	private:
		double x, y, z;
		double _padding;
	};
} // namespace kokum
