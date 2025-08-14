#include <kokum/vec2.hpp>
#include <kokum/vec3.hpp>
#include <kokum/vec4.hpp>
#include <iostream>
#include <chrono>

using namespace kokum;

void Runvec2iFullTest() {
	vec2i a(6, -3);
	vec2i b(2, 4);

	auto start = std::chrono::high_resolution_clock::now();

	vec2i add = vec2i::Add(a, b);
	vec2i sub = vec2i::Sub(a, b);
	vec2i mul = vec2i::Mul(a, b);
	int32_t dot = vec2i::Dot(a, b);
	vec2i neg = vec2i::Negate(a);
	vec2i abs = vec2i::Abs(a);
	vec2i min = vec2i::Min(a, b);
	vec2i max = vec2i::Max(a, b);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> micros = end - start;

	std::cout << "a = (" << a.X() << ", " << a.Y() << ")\n";
	std::cout << "b = (" << b.X() << ", " << b.Y() << ")\n\n";

	std::cout << "Add:      (" << add.X() << ", " << add.Y() << ")\n";
	std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ")\n";
	std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ")\n";
	std::cout << "Dot:      " << dot << "\n";
	std::cout << "Negate a: (" << neg.X() << ", " << neg.Y() << ")\n";
	std::cout << "Abs a:    (" << abs.X() << ", " << abs.Y() << ")\n";
	std::cout << "Min:      (" << min.X() << ", " << min.Y() << ")\n";
	std::cout << "Max:      (" << max.X() << ", " << max.Y() << ")\n";

	std::cout << "\nTest Time: " << std::fixed << std::setprecision(3) << micros.count() << " microseconds.\n";
}

void Runvec2fFullTest() {
	vec2f a(4.6, -5.2);
	vec2f b(2.5, 2.7);

	auto start = std::chrono::high_resolution_clock::now();

	vec2f add = a + b;
	vec2f sub = a - b;
	vec2f mul = a * b;
	vec2f mul_scal = a * 4.f;
	vec2f div = a / b;
	vec2f div_scal = a / 4.f;
	float dot = vec2f::Dot(a, b);
	vec2f neg = -a;
	vec2f abs = vec2f::Abs(a);
	vec2f min = vec2f::Min(a, b);
	vec2f max = vec2f::Max(a, b);
	vec2f norm = vec2f::Norm(a);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> micros = end - start;

	std::cout << "a = (" << a.X() << ", " << a.Y() << ")\n";
	std::cout << "b = (" << b.X() << ", " << b.Y() << ")\n\n";

	std::cout << "Add:      (" << add.X() << ", " << add.Y() << ")\n";
	std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ")\n";
	std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ")\n";
	std::cout << "Mul scal: (" << mul_scal.X() << ", " << mul_scal.Y() << ")\n";
	std::cout << "Div:      (" << div.X() << ", " << div.Y() << ")\n";
	std::cout << "Div scal: (" << div_scal.X() << ", " << div_scal.Y() << ")\n";
	std::cout << "Dot:      " << dot << "\n";
	std::cout << "Negate a: (" << neg.X() << ", " << neg.Y() << ")\n";
	std::cout << "Abs a:    (" << abs.X() << ", " << abs.Y() << ")\n";
	std::cout << "Min:      (" << min.X() << ", " << min.Y() << ")\n";
	std::cout << "Max:      (" << max.X() << ", " << max.Y() << ")\n";
	std::cout << "Norm:     (" << norm.X() << ", " << norm.Y() << ")\n";

	std::cout << "\nTest Time: " << std::fixed << std::setprecision(3) << micros.count() << " microseconds.\n";
}

void Runvec2dFullTest() {
	kokum::vec2d a(4.6, -5.2);
	kokum::vec2d b(2.5, 2.7);

	auto start = std::chrono::high_resolution_clock::now();

	auto add = a + b;
	auto sub = a - b;
	auto mul = a * b;
	auto mul_scal = a * 4.0;
	auto div = a / b;
	auto div_scal = a / 4.0;
	double dot = kokum::vec2d::Dot(a, b);
	auto neg = -a;
	auto abs = kokum::vec2d::Abs(a);
	auto min = kokum::vec2d::Min(a, b);
	auto max = kokum::vec2d::Max(a, b);
	auto norm = kokum::vec2d::Norm(a);

	auto end = std::chrono::high_resolution_clock::now();
	auto micros = std::chrono::duration<double, std::micro>(end - start);

	std::cout << "\n=== vec2d Test ===\n";
	std::cout << "a = (" << a.X() << ", " << a.Y() << ")\n";
	std::cout << "b = (" << b.X() << ", " << b.Y() << ")\n\n";

	std::cout << "Add:      (" << add.X() << ", " << add.Y() << ")\n";
	std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ")\n";
	std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ")\n";
	std::cout << "Mul scal: (" << mul_scal.X() << ", " << mul_scal.Y() << ")\n";
	std::cout << "Div:      (" << div.X() << ", " << div.Y() << ")\n";
	std::cout << "Div scal: (" << div_scal.X() << ", " << div_scal.Y() << ")\n";
	std::cout << "Dot:      " << dot << "\n";
	std::cout << "Negate:   (" << neg.X() << ", " << neg.Y() << ")\n";
	std::cout << "Abs:      (" << abs.X() << ", " << abs.Y() << ")\n";
	std::cout << "Min:      (" << min.X() << ", " << min.Y() << ")\n";
	std::cout << "Max:      (" << max.X() << ", " << max.Y() << ")\n";
	std::cout << "Norm:     (" << norm.X() << ", " << norm.Y() << ")\n";

	std::cout << "Test Time: " << micros.count() << " us\n";
}

void Runvec3iFullTest() {
	vec3i a(6, -3, 9);
	vec3i b(2, 4, -5);

	auto start = std::chrono::high_resolution_clock::now();

	vec3i add = vec3i::Add(a, b);
	vec3i sub = vec3i::Sub(a, b);
	vec3i mul = vec3i::Mul(a, b);
	int32_t dot = vec3i::Dot(a, b);
	vec3i neg = vec3i::Negate(a);
	vec3i abs = vec3i::Abs(a);
	vec3i min = vec3i::Min(a, b);
	vec3i max = vec3i::Max(a, b);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> micros = end - start;

	std::cout << "a = (" << a.X() << ", " << a.Y() << ", " << a.Z() << ")\n";
	std::cout << "b = (" << b.X() << ", " << b.Y() << ", " << b.Z() << ")\n\n";

	std::cout << "Add:      (" << add.X() << ", " << add.Y() << ", " << add.Z() << ")\n";
	std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ", " << sub.Z() << ")\n";
	std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ", " << mul.Z() << ")\n";
	std::cout << "Dot:      " << dot << "\n";
	std::cout << "Negate a: (" << neg.X() << ", " << neg.Y() << ", " << neg.Z() << ")\n";
	std::cout << "Abs a:    (" << abs.X() << ", " << abs.Y() << ", " << abs.Z() << ")\n";
	std::cout << "Min:      (" << min.X() << ", " << min.Y() << ", " << min.Z() << ")\n";
	std::cout << "Max:      (" << max.X() << ", " << max.Y() << ", " << max.Z() << ")\n";

	std::cout << "\nTest Time: " << std::fixed << std::setprecision(3) << micros.count() << " microseconds.\n";
}

void Runvec3fFullTest() {
	kokum::vec3f a(1.2f, -3.4f, 5.6f);
	kokum::vec3f b(7.8f, 9.0f, -1.2f);

	auto start = std::chrono::high_resolution_clock::now();

	auto add = a + b;
	auto sub = a - b;
	auto mul = a * b;
	auto mul_scal = a * 4.0f;
	auto div = a / b;
	auto div_scal = a / 4.0f;
	float dot = kokum::vec3f::Dot(a, b);
	auto neg = -a;
	auto abs = kokum::vec3f::Abs(a);
	auto min = kokum::vec3f::Min(a, b);
	auto max = kokum::vec3f::Max(a, b);
	auto norm = kokum::vec3f::Norm(a);

	auto end = std::chrono::high_resolution_clock::now();
	auto micros = std::chrono::duration<double, std::micro>(end - start);

	std::cout << "\n=== vec3f Test ===\n";
	std::cout << "a = (" << a.X() << ", " << a.Y() << ", " << a.Z() << ")\n";
	std::cout << "b = (" << b.X() << ", " << b.Y() << ", " << b.Z() << ")\n\n";

	std::cout << "Add:      (" << add.X() << ", " << add.Y() << ", " << add.Z() << ")\n";
	std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ", " << sub.Z() << ")\n";
	std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ", " << mul.Z() << ")\n";
	std::cout << "Mul scal: (" << mul_scal.X() << ", " << mul_scal.Y() << ", " << mul_scal.Z() << ")\n";
	std::cout << "Div:      (" << div.X() << ", " << div.Y() << ", " << div.Z() << ")\n";
	std::cout << "Div scal: (" << div_scal.X() << ", " << div_scal.Y() << ", " << div_scal.Z() << ")\n";
	std::cout << "Dot:      " << dot << "\n";
	std::cout << "Negate:   (" << neg.X() << ", " << neg.Y() << ", " << neg.Z() << ")\n";
	std::cout << "Abs:      (" << abs.X() << ", " << abs.Y() << ", " << abs.Z() << ")\n";
	std::cout << "Min:      (" << min.X() << ", " << min.Y() << ", " << min.Z() << ")\n";
	std::cout << "Max:      (" << max.X() << ", " << max.Y() << ", " << max.Z() << ")\n";
	std::cout << "Norm:     (" << norm.X() << ", " << norm.Y() << ", " << norm.Z() << ")\n";

	std::cout << "Test Time: " << micros.count() << " us\n";
}

void Runvec3dFullTest() {
	kokum::vec3d a(1.2, -3.4, 5.6);
	kokum::vec3d b(7.8, 9.0, -1.2);

	auto start = std::chrono::high_resolution_clock::now();

	auto add = a + b;
	auto sub = a - b;
	auto mul = a * b;
	auto mul_scal = a * 4.0;
	auto div = a / b;
	auto div_scal = a / 4.0;
	double dot = kokum::vec3d::Dot(a, b);
	auto neg = -a;
	auto abs = kokum::vec3d::Abs(a);
	auto min = kokum::vec3d::Min(a, b);
	auto max = kokum::vec3d::Max(a, b);
	auto norm = kokum::vec3d::Norm(a);

	auto end = std::chrono::high_resolution_clock::now();
	auto micros = std::chrono::duration<double, std::micro>(end - start);

	std::cout << "\n=== vec3d Test ===\n";
	std::cout << "a = (" << a.X() << ", " << a.Y() << ", " << a.Z() << ")\n";
	std::cout << "b = (" << b.X() << ", " << b.Y() << ", " << b.Z() << ")\n\n";

	std::cout << "Add:      (" << add.X() << ", " << add.Y() << ", " << add.Z() << ")\n";
	std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ", " << sub.Z() << ")\n";
	std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ", " << mul.Z() << ")\n";
	std::cout << "Mul scal: (" << mul_scal.X() << ", " << mul_scal.Y() << ", " << mul_scal.Z() << ")\n";
	std::cout << "Div:      (" << div.X() << ", " << div.Y() << ", " << div.Z() << ")\n";
	std::cout << "Div scal: (" << div_scal.X() << ", " << div_scal.Y() << ", " << div_scal.Z() << ")\n";
	std::cout << "Dot:      " << dot << "\n";
	std::cout << "Negate:   (" << neg.X() << ", " << neg.Y() << ", " << neg.Z() << ")\n";
	std::cout << "Abs:      (" << abs.X() << ", " << abs.Y() << ", " << abs.Z() << ")\n";
	std::cout << "Min:      (" << min.X() << ", " << min.Y() << ", " << min.Z() << ")\n";
	std::cout << "Max:      (" << max.X() << ", " << max.Y() << ", " << max.Z() << ")\n";
	std::cout << "Norm:     (" << norm.X() << ", " << norm.Y() << ", " << norm.Z() << ")\n";

	std::cout << "Test Time: " << micros.count() << " us\n";
}

void Runvec4fFullTest() {
    kokum::vec4f a(1.f, 2.f, 3.f, 4.f);
    kokum::vec4f b(5.f, 6.f, 7.f, 8.f);

    auto start = std::chrono::high_resolution_clock::now();

    auto add = a + b;
    auto sub = a - b;
    auto mul = a * b;
    auto mul_scal = a * 4.f;
    auto div = a / b;
    auto div_scal = a / 4.f;
    float dot = kokum::vec4f::Dot(a, b);
    auto neg = -a;
    auto abs = kokum::vec4f::Abs(a);
    auto min = kokum::vec4f::Min(a, b);
    auto max = kokum::vec4f::Max(a, b);
    auto norm = kokum::vec4f::Norm(a);

    auto end = std::chrono::high_resolution_clock::now();
    auto micros = std::chrono::duration<double, std::micro>(end - start);

    std::cout << "\n=== vec4f Test ===\n";
    std::cout << "a = (" << a.X() << ", " << a.Y() << ", " << a.Z() << ", " << a.W() << ")\n";
    std::cout << "b = (" << b.X() << ", " << b.Y() << ", " << b.Z() << ", " << b.W() << ")\n\n";

    std::cout << "Add:      (" << add.X() << ", " << add.Y() << ", " << add.Z() << ", " << add.W() << ")\n";
    std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ", " << sub.Z() << ", " << sub.W() << ")\n";
    std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ", " << mul.Z() << ", " << mul.W() << ")\n";
    std::cout << "Mul scal: (" << mul_scal.X() << ", " << mul_scal.Y() << ", " << mul_scal.Z() << ", " << mul_scal.W() << ")\n";
    std::cout << "Div:      (" << div.X() << ", " << div.Y() << ", " << div.Z() << ", " << div.W() << ")\n";
    std::cout << "Div scal: (" << div_scal.X() << ", " << div_scal.Y() << ", " << div_scal.Z() << ", " << div_scal.W() << ")\n";
    std::cout << "Dot:      " << dot << "\n";
    std::cout << "Negate:   (" << neg.X() << ", " << neg.Y() << ", " << neg.Z() << ", " << neg.W() << ")\n";
    std::cout << "Abs:      (" << abs.X() << ", " << abs.Y() << ", " << abs.Z() << ", " << abs.W() << ")\n";
    std::cout << "Min:      (" << min.X() << ", " << min.Y() << ", " << min.Z() << ", " << min.W() << ")\n";
    std::cout << "Max:      (" << max.X() << ", " << max.Y() << ", " << max.Z() << ", " << max.W() << ")\n";
    std::cout << "Norm:     (" << norm.X() << ", " << norm.Y() << ", " << norm.Z() << ", " << norm.W() << ")\n";

    std::cout << "Test Time: " << micros.count() << " us\n";
}

void Runvec4dFullTest() {
    kokum::vec4d a(1.0, 2.0, 3.0, 4.0);
    kokum::vec4d b(5.0, 6.0, 7.0, 8.0);

    auto start = std::chrono::high_resolution_clock::now();

    auto add = a + b;
    auto sub = a - b;
    auto mul = a * b;
    auto mul_scal = a * 4.0;
    auto div = a / b;
    auto div_scal = a / 4.0;
    double dot = kokum::vec4d::Dot(a, b);
    auto neg = -a;
    auto abs = kokum::vec4d::Abs(a);
    auto min = kokum::vec4d::Min(a, b);
    auto max = kokum::vec4d::Max(a, b);
    auto norm = kokum::vec4d::Norm(a);

    auto end = std::chrono::high_resolution_clock::now();
    auto micros = std::chrono::duration<double, std::micro>(end - start);

    std::cout << "\n=== vec4d Test ===\n";
    std::cout << "a = (" << a.X() << ", " << a.Y() << ", " << a.Z() << ", " << a.W() << ")\n";
    std::cout << "b = (" << b.X() << ", " << b.Y() << ", " << b.Z() << ", " << b.W() << ")\n\n";

    std::cout << "Add:      (" << add.X() << ", " << add.Y() << ", " << add.Z() << ", " << add.W() << ")\n";
    std::cout << "Sub:      (" << sub.X() << ", " << sub.Y() << ", " << sub.Z() << ", " << sub.W() << ")\n";
    std::cout << "Mul:      (" << mul.X() << ", " << mul.Y() << ", " << mul.Z() << ", " << mul.W() << ")\n";
    std::cout << "Mul scal: (" << mul_scal.X() << ", " << mul_scal.Y() << ", " << mul_scal.Z() << ", " << mul_scal.W() << ")\n";
    std::cout << "Div:      (" << div.X() << ", " << div.Y() << ", " << div.Z() << ", " << div.W() << ")\n";
    std::cout << "Div scal: (" << div_scal.X() << ", " << div_scal.Y() << ", " << div_scal.Z() << ", " << div_scal.W() << ")\n";
    std::cout << "Dot:      " << dot << "\n";
    std::cout << "Negate:   (" << neg.X() << ", " << neg.Y() << ", " << neg.Z() << ", " << neg.W() << ")\n";
    std::cout << "Abs:      (" << abs.X() << ", " << abs.Y() << ", " << abs.Z() << ", " << abs.W() << ")\n";
    std::cout << "Min:      (" << min.X() << ", " << min.Y() << ", " << min.Z() << ", " << min.W() << ")\n";
    std::cout << "Max:      (" << max.X() << ", " << max.Y() << ", " << max.Z() << ", " << max.W() << ")\n";
    std::cout << "Norm:     (" << norm.X() << ", " << norm.Y() << ", " << norm.Z() << ", " << norm.W() << ")\n";

    std::cout << "Test Time: " << micros.count() << " us\n";
}


int main() {
	Runvec2iFullTest();
	Runvec2fFullTest();
	Runvec2dFullTest();
	Runvec3iFullTest();
	Runvec3fFullTest();
	Runvec3dFullTest();
	Runvec4fFullTest();
	Runvec4dFullTest();
	return 0;
}
