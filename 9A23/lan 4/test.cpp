#include <iostream>
#include <string>

// Hàm chuy?n d?i t? h? 10 sang h? co s? 5
std::string decimalToBase5(int number) {
    const char digits[] = "01234";
    std::string result = "";
    int quotient = number;

    if (number == 0) {
        return "0";
    }

    while (quotient > 0) {
        int remainder = quotient % 5;
        result = digits[remainder] + result;
        quotient /= 5;
    }

    return result;
}

int main() {
	for (int i = 1; i <= 50; i++) std::cout << decimalToBase5(i-5) << ' ';
}

