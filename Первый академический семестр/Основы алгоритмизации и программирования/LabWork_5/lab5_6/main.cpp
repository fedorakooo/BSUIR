#include <iostream>

int calculation(int a) {
	long long result = 0;
	if (a % 10 > 0) {
		result += a % 10;
	}
	else if (a == 0) {
		return 0;
	}
	else {
		result += calculation(a / 10);
	}
	return result;
}

int main() {
	long long x, y;
	while (true) {
		std::cin >> x >> y;
		if (x < 0 && y < 0) {
			break;
		}
		else {
			long long result = 0;
			while(x <= y) {
				result += calculation(x);
				x++;
			}
			std::cout << result << '\n';
		}
	}
}