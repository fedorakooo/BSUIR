#include <iostream>
#include <string>

int main() {
	int n = 0; 
	std::cin >> n;
	for (; n > 0; n--) {
		std::string s1, s2, t;
		std::cin >> s1 >> t;
		int size1 = s1.length(), size2 = t.length();
		int k1 = -1, k2 = -1;
		for (int i = 0; i < size2; i++) {
			if (s1.find(t, size2 - 1 - i) != -1) {
				std::cout << s1.find(t, size2 - 1 - i);
				return 0;
			}
		}
	}
}