#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double x = sqrt(n);
    answer = x == floor(x)? pow(x + 1, 2) : -1;
    return answer;
}