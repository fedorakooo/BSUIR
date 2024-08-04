#include <cmath>

extern "C" __declspec(dllexport) int Sum(int a, int b) {
	return a + b;
}

extern "C" __declspec(dllexport) bool Is_cos_plus(int mass) {
	return (std::cos(mass) > 0 ? 1 : 0);
}

extern "C" __declspec(dllexport) bool Is_mass_cos_plus(int* mass, int start, int end) {
	if (end - start == 1) return Is_cos_plus(mass[start]);
	else if (end - start == 2) return Is_cos_plus(mass[start]) && Is_cos_plus(mass[start + 1]);
}