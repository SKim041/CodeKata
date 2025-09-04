#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long D=d;
    for(int i=0; i*k<=D; i++)
    {
        long long x = i*k;
        long long y = sqrt(D*D-x*x);
        answer += y/k +1;
    }
    return answer;
}