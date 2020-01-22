#include <iostream>

int main() {
    int n, m, num_case;

    scanf("%d%d", &n, &m);

    int map[300][300];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    scanf("%d", &num_case);

    for (int test_case = 0; test_case < num_case; test_case++) {
        int i, j, x, y;
        int sum = 0;

        scanf("%d%d%d%d", &i, &j, &x, &y);

        for (int tmp_i = i - 1; tmp_i < x; tmp_i++) {
            for (int tmp_j = j - 1; tmp_j < y; tmp_j++) {
                sum += map[tmp_i][tmp_j];
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
