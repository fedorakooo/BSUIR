#include <iostream>
#include <string>

long long const quantity = 26;

long long binpow(long long n, long long k, long long m) {
	if (k == 0) {
		return 1;
	}
	if (k % 2 == 0) {
		return (binpow(n, k / 2, m) % m * binpow(n, k / 2, m) % m) % m;
	}
	else return (binpow(n, k - 1, m) % m * n % m) % m;
}

int main() {
	std::string first_line;
	std::string second_line;
	long long k;
	std::cin >> k;
	for (;k > 0; k--) {
		long long n, m;
		std::cin >> n >> m;
		std::cin >> first_line >> second_line;
		long long first_size = first_line.size(), second_size = second_line.size();

		long long same = 0;
		for (long long i = 0; i < std::min(first_size, second_size); i++) {
			if (first_line[i] == second_line[second_size - 1 - i]) same++;
			else break;
		}

		bool check = 1;
		for (int i = 0; i < first_size; i++) {
			if (first_line[i] != first_line[0]) {
				check = 0;
				break;
			}
		}
		for (int i = 0; i < second_size; i++) {
			if (second_line[i] != first_line[0]) {
				check = 0;
				break;
			}
		}
		if (first_line == second_line && first_size == second_size) std::cout << (binpow(quantity, n - first_size - second_size, m)) % m;
		else if (check == 1 && n >= first_size && n >= second_size) {
			std::cout << ((2 * binpow(quantity, n - first_size - second_size, m)) % m - 1) % m;
		}
		else if (same > 0 && std::max(first_size, second_size) > n / 2) {
			std::cout << (2 * binpow(quantity, n - first_size - second_size, m)) % m;
		}
		else if (same == 0 && n > first_size + second_size) {
			std::cout << (2 * binpow(quantity, n - first_size - second_size, m)) % m;
		}
		else if (same != 0 && n > first_size + second_size) {
			std::cout << ((2 * binpow(quantity, n - first_size - second_size, m) - (quantity * same) % m) % m) % m;
		}
		else if (first_line != second_line && n == first_size + second_size) {
			std::cout << 2;
		}
		else if (first_line == second_line && n == first_size + second_size) {
			std::cout << 1;
		}
		else if (n < first_size + second_size && n > first_size && n > second_size) {
			long long result = 0;
			long long different = first_size + second_size - n;
			for (int i = 0; i < different; i++) {
				if (first_line[i] != second_line[second_size - different + i]) break;
				else if (first_line[i] == second_line[second_size - different + i] && i == different - 1) result++;
			}
			for (int i = 0; i < different; i++) {
				if (second_line[i] != first_line[first_size - different + i]) break;
				else if (second_line[i] == first_line[first_size - different + i] && i == different - 1) result++;
			}
			std::cout << result % m;
		}
		else 
			std::cout << 0;
		std::cout << '\n';
	}
}