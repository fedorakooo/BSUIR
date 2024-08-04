#include <iostream>

void bubble_sort(long long* mass,long n) {
	for (int i = 0; i <= n; i++) {
		for (int k = 1; k <= n - i; k++) {
			if (mass[k - 1] > mass[k]) {
				long long change = mass[k];
				mass[k] = mass[k - 1];
				mass[k - 1] = change;
			}
		}
	}
}

void selection_sort(long long* mass, long long n) {
	for (int i = 0; i <= n; i++) {
		long long minimum = mass[i];
		long long index_minimum = i;
		for (int k = i; k < n; k++) {
			if (mass[k] <= minimum) {
				minimum = mass[k];
				index_minimum = k;
			}
		}
		long long change = mass[i];
		mass[i] = minimum;
		mass[index_minimum] = change;
	}
}

long part_of_quick_sort(long long* mass, long left, long right) {
	long long pivot = mass[(left + right) / 2];
	while (left <= right) {
		while (mass[left] < pivot) left++;
		while (mass[right] > pivot) right--;
		if (left <= right) {
			long long temp = mass[left];
			mass[left] = mass[right];
			mass[right] = temp;
			left++;
			right--;
		}
	}
	return left;
}

void quick_sort(long long* mass,long start, long end) {
	if (start >= end) return;
	long right_start = part_of_quick_sort(mass, start, end);
	quick_sort(mass, start, right_start - 1);
	quick_sort(mass, right_start, end);
}

void insertion_sort(long long* mass, long n) {
	for (long i = 1; i <= n; i++) {
		long sorted = i - 1;
		while (sorted >= 0 && mass[sorted] > mass[sorted + 1]) {
			long long change = mass[sorted];
			mass[sorted] = mass[sorted + 1];
			mass[sorted + 1] = change;
			sorted--;
		}
	}
}

void shell_sort(int* mass, int size)
{
	for (int point = size / 2; point > 0; point /= 2)
	{
		for (int i = point; i < size; i++)
		{
			int change = mass[i];
			int t = i;
			for (; t >= point && mass[t - point] > change; t -= point)  mass[t] = mass[t - point];
			mass[t] = change;
		}
	}
}