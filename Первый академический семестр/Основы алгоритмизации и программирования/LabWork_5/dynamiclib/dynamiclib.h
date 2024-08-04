#pragma once
#include <cmath>

extern "C" __declspec(dllexport) int Sum(int, int);
extern "C" __declspec(dllexport)bool Is_cos_plus(int mass);
extern "C" __declspec(dllexport) bool Is_mass_cos_plus(int* mass, int start, int end);