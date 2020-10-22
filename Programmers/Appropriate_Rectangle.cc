using namespace std;

long long gcd(long long  a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long solution(int w,int h) {
    long long answer = 1;
    long long l_w = w;
    long long l_h = h;
    long long gc = gcd(w, h);
    if (gc == 1) {
        answer = l_w + l_h -1;
    } else {
        answer = l_w + l_h - gc;
    }
    
    return l_w * l_h - answer;
}
