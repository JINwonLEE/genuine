#include <iostream>
int gcd(int x, int y);

int gcd(int x, int y) {
    int n;
    while (true) {
        n = x % y;
        if (n == 0) return y;
        x = y;
        y = n;
    }    
}

int main() {
    int M, N, x, y;
    int count = 1;
    int test_case;
    std::cin >> test_case;
    
    for (int i = 0; i < test_case; i++) {
        std::cin >> M >> N >> x >> y;
        bool find = false;
        int lcm = M * N / gcd(M, N);
        int m = lcm / M;
        int n = lcm / N;
        int m_ = 0;
        int n_ = 0;
        
        while (m_ <= m || n_ <= n) {
            if (M * m_ + x == N * n_ + y) {
                count = M * m_ + x;
                find = true;
                break;
            }
            else if (M * m_ + x > N * n_ + y) {
                n_++;
            }
            else {
                m_++;
            }
        }
        if (find) {
            std::cout << count << std::endl;
        }
        else {
            std::cout << "-1" << std::endl;
        }
            
    }
    return 0;
}
