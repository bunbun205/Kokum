
#pragma once

extern "C" {
    void kokum_vec4f_add(const float* a, const float* b, float* result);
    void kokum_vec4f_sub(const float* a, const float* b, float* result);
    void kokum_vec4f_mul(const float* a, const float* b, float* result);
    void kokum_vec4f_div(const float* a, const float* b, float* result);
    void kokum_vec4f_scalar_mul(const float* a, const float* b, float* result);
    void kokum_vec4f_scalar_div(const float* a, const float* b, float* result);
    float kokum_vec4f_dot(const float* a, const float* b);
    void kokum_vec4f_negate(const float* a, float* result);
    void kokum_vec4f_abs(const float* a, float* result);
    void kokum_vec4f_min(const float* a, const float* b, float* result);
    void kokum_vec4f_max(const float* a, const float* b, float* result);
    void kokum_vec4f_norm(const float* a, float* result);
}

namespace kokum{
    class alignas(16) vec4f {
    public:
        inline vec4f() : x(0), y(0), z(0), w(0), _padding(0) {}
        inline vec4f(const float x_, const float y_) : x(x_), y(y_), z(0), w(0), _padding(0) {}
        inline explicit vec4f(vec2f a) : x(a.X()), y(a.Y()), z(0), w(0), _padding(0) {}
        inline vec4f(vec2f a, const float z_) : x(a.X()), y(a.Y()), z(z_), w(0), _padding(0) {}
        inline vec4f(vec2f a, const float z_, const float w_) : x(a.X()), y(a.Y()), z(z_), w(w_), _padding(0) {}
        inline explicit vec4f(vec3f a) : x(a.X()), y(a.Y()), z(a.Z()), w(0), _padding(0) {}
        inline vec4f(vec3f a, const float w_) : x(a.X()), y(a.Y()), z(a.Z()), w(w_), _padding(0) {}
        inline vec4f(vec2f a, vec2f b) : x(a.X()), y(a.Y()), z(b.X()), w(b.Y()), _padding(0) {}
        inline vec4f(const float x_, const float y_, const float z_) : x(x_), y(y_), z(z_), w(0), _padding(0) {}
        inline vec4f(float const x_, const float y_, const float z_, const float w_) : x(x_), y(y_), z(z_), w(w_), _padding(0) {}

        public:
        [[nodiscard]] inline float X() const { return x; }
        [[nodiscard]] inline float Y() const { return y; }
        [[nodiscard]] inline float Z() const { return z; }
        [[nodiscard]] inline float W() const { return w; }
        inline float& X() { return x; }
        inline float& Y() { return y; }
        inline float& Z() { return z; }
        inline float& W() { return w; }

        inline float operator [](const int i) const {
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }

        inline float& operator [](const int i) {
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }

        inline vec4f operator +(const vec4f& b) const {
            return Add(*this, b);
        }

        inline vec4f operator -(const vec4f& b) const {
            return Sub(*this, b);
        }

        inline vec4f operator -() const {
            return Negate(*this);
        }

        inline vec4f operator *(const vec4f& b) const {
            return Mul(*this, b);
        }

        inline vec4f operator /(const vec4f& b) const {
            return Div(*this, b);
        }

        inline vec4f operator *(const float b) const {
            return Mul(*this, b);
        }

        inline vec4f operator /(const float b) const {
            return Div(*this, b);
        }

        inline static vec4f Add(const vec4f& a, const vec4f& b) {
            vec4f r;
            kokum_vec4f_add(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4f Sub(const vec4f& a, const vec4f& b) {
            vec4f r;
            kokum_vec4f_sub(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4f Mul(const vec4f& a, const vec4f& b) {
            vec4f r;
            kokum_vec4f_mul(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4f Div(const vec4f& a, const vec4f& b) {
            vec4f r;
            kokum_vec4f_div(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4f Mul(const vec4f& a, const float b) {
            vec4f r;
            kokum_vec4f_scalar_mul(&a.x, &b, &r.x);
            return r;
        }

        inline static vec4f Mul(const float a, const vec4f& b) {
            return Mul(b, a);
        }

        inline static vec4f Div(const vec4f& a, const float b) {
            vec4f r;
            kokum_vec4f_scalar_div(&a.x, &b, &r.x);
            return r;
        }

        inline static float Dot(const vec4f& a, const vec4f& b) {
            return kokum_vec4f_dot(&a.x, &b.x);
        }

        inline static vec4f Negate(const vec4f& a) {
            vec4f r;
            kokum_vec4f_negate(&a.x, &r.x);
            return r;
        }

        inline static vec4f Abs(const vec4f& a) {
            vec4f r;
            kokum_vec4f_abs(&a.x, &r.x);
            return r;
        }

        inline static vec4f Min(const vec4f& a, const vec4f& b) {
            vec4f r;
            kokum_vec4f_min(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4f Max(const vec4f& a, const vec4f& b) {
            vec4f r;
            kokum_vec4f_max(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4f Norm(const vec4f& a) {
            vec4f r;
            kokum_vec4f_norm(&a.x, &r.x);
            return r;
        }

        private:
        float x, y, z, w;
        float _padding;
    };
} // namespace kokum
