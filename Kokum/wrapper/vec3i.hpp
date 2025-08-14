#pragma once

#include <cstdint>

extern "C" {
void kokum_vec3i_add(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec3i_sub(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec3i_mul(const int32_t* a, const int32_t* b, int32_t* result);
int32_t kokum_vec3i_dot(const int32_t* a, const int32_t* b);
void kokum_vec3i_negate(const int32_t* a, int32_t* result);
void kokum_vec3i_abs(const int32_t* a, int32_t* result);
void kokum_vec3i_min(const int32_t* a, const int32_t* b, int32_t* result);
void kokum_vec3i_max(const int32_t* a, const int32_t* b, int32_t* result);
}

namespace kokum{
    class alignas(16) vec3i {
    public:
        inline vec3i() : x(0), y(0), z(0), _padding(0) {}
        inline vec3i(const int32_t x_, const int32_t y_) : x(x_), y(y_), z(0), _padding(0) {}
        inline explicit vec3i(vec2i a) : x(a.X()), y(a.Y()), z(0), _padding(0) {}
        inline vec3i(vec2i a, const int32_t z_) : x(a.X()), y(a.Y()), z(z_), _padding(0) {}
        inline vec3i(const int32_t x_, const int32_t y_, const int32_t z_) : x(x_), y(y_), z(z_), _padding(0) {}

        public:
        [[nodiscard]] inline int32_t X() const { return x; }
        [[nodiscard]] inline int32_t Y() const { return y; }
        [[nodiscard]] inline int32_t Z() const { return z; }
        inline int32_t& X() { return x; }
        inline int32_t& Y() { return y; }
        inline int32_t& Z() { return z; }

        inline int32_t operator [](const int i) const {
            return i == 0 ? x : i == 1 ? y : z;
        }

        inline int32_t& operator [](const int i) {
            return i == 0 ? x : i == 1 ? y : z;
        }

        inline vec3i operator +(const vec3i& b) const {
            return Add(*this, b);
        }

        inline vec3i operator -(const vec3i& b) const {
            return Sub(*this, b);
        }

        inline vec3i operator -() const {
            return Negate(*this);
        }

        inline vec3i operator *(const vec3i& b) const {
            return Mul(*this, b);
        }

        inline static vec3i Add(const vec3i& a, const vec3i& b) {
            vec3i r;
            kokum_vec3i_add(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec3i Sub(const vec3i& a, const vec3i& b) {
            vec3i r;
            kokum_vec3i_sub(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec3i Mul(const vec3i& a, const vec3i& b) {
            vec3i r;
            kokum_vec3i_mul(&a.x, &b.x, &r.x);
            return r;
        }

        inline static int32_t Dot(const vec3i& a, const vec3i& b) {
            return kokum_vec3i_dot(&a.x, &b.x);
        }

        inline static vec3i Negate(const vec3i& a) {
            vec3i r;
            kokum_vec3i_negate(&a.x, &r.x);
            return r;
        }

        inline static vec3i Abs(const vec3i& a) {
            vec3i r;
            kokum_vec3i_abs(&a.x, &r.x);
            return r;
        }

        inline static vec3i Min(const vec3i& a, const vec3i& b) {
            vec3i r;
            kokum_vec3i_min(&a.x, &b.x, &r.x);
            return r;
        }

        inline static vec3i Max(const vec3i& a, const vec3i& b) {
            vec3i r;
            kokum_vec3i_max(&a.x, &b.x, &r.x);
            return r;
        }

        private:
        int32_t x, y, z;
        int32_t _padding;
    };
} // namespace kokum
