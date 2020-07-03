#include <iostream>

int main() {
    int num_card = 0;

    std::cin >> num_card;

    int card_price[1001];
    int max_price[1001] = {0};
    max_price[0] = 0;

    for (int i = 1; i <= num_card; i++) {
        std::cin >> card_price[i];
    }

    max_price[1] = card_price[1];

    for (int i = 1; i <= num_card; i++) {
        int ith_max_price = 0;
        for (int j = 1; j <= i; j++) {
            if (ith_max_price < card_price[j] + max_price[i - j]) {
                ith_max_price = card_price[j] + max_price[i - j];
            }
        }
        max_price[i] = ith_max_price;
    }

    std::cout << max_price[num_card] << std::endl;

    return 0;
}
