#include <iostream>
#include <algorithm>

int main() {
    int num_stairs;

    std::cin >> num_stairs;

    int sum[300] = {0};
    int stairs[300] = {0};

    for (int i = 0 ;i < num_stairs; i++) {
        std::cin >> stairs[i];
    }
    sum[0] = stairs[0];
    sum[1] = stairs[0] + stairs[1];
    sum[2] = std::max(stairs[1] + stairs[2], sum[0] + stairs[2]);
    
    for (int i = 3; i < num_stairs; i++) {
        sum[i] = std::max(stairs[i] + sum[i-2], stairs[i] + stairs[i-1] + sum[i-3]);
    }

    std::cout << sum[num_stairs - 1] << std::endl;
    return 0;
}
