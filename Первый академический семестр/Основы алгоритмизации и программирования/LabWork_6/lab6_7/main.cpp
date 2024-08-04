#include <iostream>
#include <string>

long long const SIZE = 26;

bool check_to_include_in_start(std::string str1, std::string str2) {
    for (int i = 0; i < str2.size(); i++) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

bool check_to_include_in_end(std::string str1, std::string str2) {
    for (int i = 1; i <= str2.size(); i++) {
        if (str1[str1.size() - i] != str2[str2.size() - i])
            return false;
    }
    return true;
}

long long binpow(long long n, long long k, long long mod) {
    if (k == 0) return 1;
    else if (k % 2 == 0) return  (binpow(n, k / 2, mod) * binpow(n, k / 2, mod)) % mod;
    else return (binpow(n, k - 1, mod) * n) % mod;
}

bool check_to_general(std::string str1, std::string str2, long long length) {
    long long bspace = length - str2.size();
    for (int i = bspace; i < str1.size(); i++) {
        if (str1[i] != str2[i - bspace])
            return false;
    }
    return true;
}

int main() {
    long long quantity;
    std::cin >> quantity;
    while (quantity > 0) {
        long long length;
        long long mod;
        std::cin >> length >> mod;
        std::string str1, str2;
        std::cin >> str1 >> str2;
        long long result;
        if (str1.size() < str2.size()) std::swap(str1, str2);
        if (str1.size() > length) result = 0;
        else if (str1.size() + str2.size() >= length) {
            result = 0;
            if (check_to_general(str1, str2, length)) result++;
            if (!check_to_include_in_end(str1, str2) && check_to_general(str2, str1, length)) result++;
        }
        else {
            result = binpow(SIZE, length - str1.size() - str2.size(), mod) * 2;
            if (check_to_include_in_start(str1, str2) && check_to_include_in_end(str1, str2)) {
                if (2 * str1.length() >= length) {
                    std::string str_check = str1.substr(0, length - str1.length()) + str1;
                    if (check_to_include_in_start(str_check, str1) && check_to_include_in_end(str_check, str2)) {
                        result--;
                    }
                }
                else {
                    result -= binpow(26, length - 2 * str1.length(), mod);
                    result %= mod;
                }
            }
        }
        std::cout << result % mod << '\n';
    }
    return 0;
}
