#include <iostream>

const int SIZE = 1000;

int translate(long long n, int* mass) {
	int result = 0;
	while (n > 0) {
		if (n % 3 == 0) {
			mass[result] = 3;
			n -= 3;
			result++;
		}
		else {
			mass[result] = n % 3;
			result++;
		}
		n = (n - n % 3) / 3;
	}
	return result;
}

int main() {
	int* mass = new int[SIZE];
	long long n;
	std::cin >> n;
	int number = translate(n, mass);
	for (int i = number - 1; i >= 0; i--) {
		std::cout << mass[i];
	}
}