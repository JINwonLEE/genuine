#include <iostream>
#include <algorithm>

int main() {
    int n, m;
    int map[1000][1000];
    int result[1000][1000];

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
            result[i][j] = 0;
        }
    }

    result[0][0] = map[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int upper = 0;
            int left = 0;
            int diag = 0;

            if (i - 1 >= 0) {
                upper = result[i - 1][j] + map[i][j];
            }

            if (j - 1 >= 0) {
                left = result[i][j - 1] + map[i][j];
            }

            if (i - 1 >= 0 && j - 1 >= 0) {
                diag = result[i - 1][j - 1] + map[i][j];
            }

            result[i][j] = std::max(std::max(std::max(upper, left), diag), result[i][j]);
        }
    }

    std::cout << result[n-1][m-1] << std::endl;
    return 0;
}
