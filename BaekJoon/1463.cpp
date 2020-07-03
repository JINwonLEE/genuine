#include <algorithm>
#include <iostream>

int main() {
    int number = 0;

    std::cin >> number;

    int count[1000000] = {0};
    count[0] = 0;
    count[1] = 0;
    count[2] = 1;
    count[3] = 1;
    count[4] = 2;

    for (int i = 5; i <= number; i++) {
        int method_1 = 1000000;
        int method_2 = 1000000;
        int method_3 = 1000000;

        if (i % 3 == 0) {
            method_1 = count[i / 3] + 1;
        }

        if (i % 2 == 0) {
            method_2 = count[i / 2] + 1;
        }

        method_3 = count[i - 1] + 1;

        count[i] = std::min(std::min(method_1, method_2), method_3);
    }

    std::cout << count[number] << std::endl;

    return 0;
}
