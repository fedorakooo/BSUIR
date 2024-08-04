#include <iostream>

long long calculation(long long n) {
	if (n == 1) {
		return 1;
	}
	if (n != 0) {

		return calculation(n / 2) + ((n + 1) / 2) * ((n + 1) / 2);
	}
}

int main() {
	long long k;
	std::cin >> k;
	long long mass[1000];
	long long number;
	int size = 0;
	for (int i = 0; k > 0; k--, i++, size++) {
		std::cin >> number;
		if (number == 0) {
			mass[i] = 0;
		}
		else {
			mass[i] = calculation(f);
		}
	}
	for (int i = 0; i < size; i++) {
		std::cout << mass[i] << '\n';
	}
}
