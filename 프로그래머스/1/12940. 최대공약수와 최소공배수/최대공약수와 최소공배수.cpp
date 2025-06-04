#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    int gcd = 1;
    int lcm = 1;
    int maxNum = max(n, m);
    int minNum = min(n, m);
    int i = 2;

    while (1) {
        if (minNum % i == 0 && maxNum % i == 0) {
            minNum /= i;
            maxNum /= i;
            gcd *= i;
        }
        else {
            i++;
        }
        if (i > minNum) {
            break;
        }
    }
    lcm = gcd * minNum * maxNum;

    return vector<int>{gcd, lcm};
}