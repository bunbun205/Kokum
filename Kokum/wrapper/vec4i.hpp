#pragma once

#include <cstdint>

extern "C" {
void kokum_vec4i_add(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec4i_sub(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec4i_mul(const int32_t* a, const int32_t* b, int32_t* result);
int32_t kokum_vec4i_dot(const int32_t* a, const int32_t* b);
void kokum_vec4i_negate(const int32_t* a, int32_t* result);
void kokum_vec4i_abs(const int32_t* a, int32_t* result);
void kokum_vec4i_min(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec4i_max(const int32_t* a, const int32_t* b, int32_t* result);
}

namespace kokum{
    class alignas(16) vec4i {
        public:
        inline vec4i() : x(0), y(0), z(0), w(0), _padding(0) {}
        inline vec4i(const int32_t x_, const int32_t y_) : x(x_), y(y_), z(0), w(0), _padding(0) {}
        inline explicit vec4i(vec2i a) : x(a.X()), y(a.Y()), z(0), w(0), _padding(0) {}
        inline vec4i(vec2i a, const int32_t z_) : x(a.X()), y(a.Y()), z(z_), w(0), _padding(0) {}
        inline vec4i(vec2i a, const int32_t z_, const int32_t w_) : x(a.X()), y(a.Y()), z(z_), w(w_), _padding(0) {}
        inline explicit vec4i(vec3i a) : x(a.X()), y(a.Y()), z(a.Z()), w(0), _padding(0) {}
        inline vec4i(vec3i a, const int32_t w_) : x(a.X()), y(a.Y()), z(a.Z()), w(w_), _padding(0) {}
        inline vec4i(vec2i a, vec2i b) : x(a.X()), y(a.Y()), z(b.X()), w(b.Y()), _padding(0) {}
        inline vec4i(const int32_t x_, const int32_t y_, const int32_t z_) : x(x_), y(y_), z(z_), w(0), _padding(0) {}
        inline vec4i(const int32_t x_, const int32_t y_, const int32_t z_, const int32_t w_) : x(x_), y(y_), z(z_), w(w_), _padding(0) {}

        public:
        [[nodiscard]] inline int32_t X() const { return x; }
        [[nodiscard]] inline int32_t Y() const { return y; }
        [[nodiscard]] inline int32_t Z() const { return z; }
        [[nodiscard]] inline int32_t W() const { return w; }
        inline int32_t& X() { return x; }
        inline int32_t& Y() { return y; }
        inline int32_t& Z() { return z; }
        inline int32_t& W() { return w; }

        inline int32_t operator [](const int i) const {
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }

        inline int32_t& operator [](const int i) {
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }

        inline vec4i operator +(const vec4i& b) const {
            return Add(*this, b);
        }

        inline vec4i operator -(const vec4i& b) const {
            return Sub(*this, b);
        }

        inline vec4i operator -() const {
            return Negate(*this);
        }

        inline vec4i operator *(const vec4i& b) const {
            return Mul(*this, b);
        }

        inline static vec4i Add(const vec4i& a, const vec4i& b) {
            vec4i r;
            kokum_vec4i_add(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4i Sub(const vec4i& a, const vec4i& b) {
            vec4i r;
            kokum_vec4i_sub(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4i Mul(const vec4i& a, const vec4i& b) {
            vec4i r;
            kokum_vec4i_mul(&a.x, &b.x, &r.x);
            return r;
        }

        inline static int32_t Dot(const vec4i& a, const vec4i& b) {
            return kokum_vec4i_dot(&a.x, &b.x);
        }

        inline static vec4i Negate(const vec4i& a) {
            vec4i r;
            kokum_vec4i_negate(&a.x, &r.x);
            return r;
        }

        inline static vec4i Abs(const vec4i& a) {
            vec4i r;
            kokum_vec4i_abs(&a.x, &r.x);
            return r;
        }

        inline static vec4i Min(const vec4i& a, const vec4i& b) {
            vec4i r;
            kokum_vec4i_min(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec4i Max(const vec4i& a, const vec4i& b) {
            vec4i r;
            kokum_vec4i_max(&a.x, &b.x, &r.x);
            return r;
        }

        private:
        int32_t x, y, z, w;
        int32_t _padding;
    };
} // namespace kokum
