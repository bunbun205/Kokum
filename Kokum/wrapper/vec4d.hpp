
#pragma once

extern "C" {
    void kokum_vec4d_add(const double* a, const double* b, double* result);
    void kokum_vec4d_sub(const double* a, const double* b, double* result);
    void kokum_vec4d_mul(const double* a, const double* b, double* result);
    void kokum_vec4d_div(const double* a, const double* b, double* result);
    void kokum_vec4d_scalar_mul(const double* a, const double* b, double* result);
    void kokum_vec4d_scalar_div(const double* a, const double* b, double* result);
    double kokum_vec4d_dot(const double* a, const double* b);
    void kokum_vec4d_negate(const double* a, double* result);
    void kokum_vec4d_abs(const double* a, double* result);
    void kokum_vec4d_min(const double* a, const double* b, double* result);
    void kokum_vec4d_max(const double* a, const double* b, double* result);
    void kokum_vec4d_norm(const double* a, double* result);
}

namespace kokum{
    class alignas(16) vec4d {
    public:
        inline vec4d() : x(0), y(0), z(0), w(0), _padding(0) {}
        inline vec4d(const double x_, const double y_) : x(x_), y(y_), z(0), w(0), _padding(0) {}
        inline explicit vec4d(vec2f a) : x(a.X()), y(a.Y()), z(0), w(0), _padding(0) {}
        inline vec4d(vec2f a, const double z_) : x(a.X()), y(a.Y()), z(z_), w(0), _padding(0) {}
        inline vec4d(vec2f a, const double z_, const double w_) : x(a.X()), y(a.Y()), z(z_), w(w_), _padding(0) {}
        inline explicit vec4d(vec3f a) : x(a.X()), y(a.Y()), z(a.Z()), w(0), _padding(0) {}
        inline vec4d(vec3f a, const double w_) : x(a.X()), y(a.Y()), z(a.Z()), w(w_), _padding(0) {}
        inline vec4d(vec2f a, vec2f b) : x(a.X()), y(a.Y()), z(b.X()), w(b.Y()), _padding(0) {}
        inline vec4d(const double x_, const double y_, const double z_) : x(x_), y(y_), z(z_), w(0), _padding(0) {}
        inline vec4d(double const x_, const double y_, const double z_, const double w_) : x(x_), y(y_), z(z_), w(w_), _padding(0) {}

        public:
        [[nodiscard]] inline double X() const { return x; }
        [[nodiscard]] inline double Y() const { return y; }
        [[nodiscard]] inline double Z() const { return z; }
        [[nodiscard]] inline double W() const { return w; }
        inline double& X() { return x; }
        inline double& Y() { return y; }
        inline double& Z() { return z; }
        inline double& W() { return w; }

        inline double operator [](const int i) const {
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }

        inline double& operator [](const int i) {
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }

        inline vec4d operator +(const vec4d& b) const {
            return Add(*this, b);
        }

        inline vec4d operator -(const vec4d& b) const {
            return Sub(*this, b);
        }

        inline vec4d operator -() const {
            return Negate(*this);
        }

        inline vec4d operator *(const vec4d& b) const {
            return Mul(*this, b);
        }

        inline vec4d operator *(const double b) const {
            return Mul(*this, b);
        }

        inline vec4d operator /(const double b) const {
            return Div(*this, b);
        }

        inline vec4d operator /(const vec4d& b) const {
            return Div(*this, b);
        }

        inline static vec4d Add(const vec4d& a, const vec4d& b) {
            vec4d r;
            kokum_vec4d_add(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4d Sub(const vec4d& a, const vec4d& b) {
            vec4d r;
            kokum_vec4d_sub(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4d Mul(const vec4d& a, const vec4d& b) {
            vec4d r;
            kokum_vec4d_mul(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4d Div(const vec4d& a, const vec4d& b) {
            vec4d r;
            kokum_vec4d_div(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4d Div(const vec4d& a, const double b) {
            vec4d r;
            kokum_vec4d_scalar_div(&a.x, &b, &r.x);
            return r;
        }

        inline static vec4d Mul(const vec4d& a, const double b) {
            vec4d r;
            kokum_vec4d_scalar_mul(&a.x, &b, &r.x);
            return r;
        }

        inline static vec4d Mul(const double a, const vec4d& b) {
            return Mul(b, a);
        }

        inline static double Dot(const vec4d& a, const vec4d& b) {
            return kokum_vec4d_dot(&a.x, &b.x);
        }

        inline static vec4d Negate(const vec4d& a) {
            vec4d r;
            kokum_vec4d_negate(&a.x, &r.x);
            return r;
        }

        inline static vec4d Abs(const vec4d& a) {
            vec4d r;
            kokum_vec4d_abs(&a.x, &r.x);
            return r;
        }

        inline static vec4d Min(const vec4d& a, const vec4d& b) {
            vec4d r;
            kokum_vec4d_min(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4d Max(const vec4d& a, const vec4d& b) {
            vec4d r;
            kokum_vec4d_max(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4d Norm(const vec4d& a) {
            vec4d r;
            kokum_vec4d_norm(&a.x, &r.x);
            return r;
        }

        private:
        double x, y, z, w;
        double _padding;
    };
} // namespace kokum
