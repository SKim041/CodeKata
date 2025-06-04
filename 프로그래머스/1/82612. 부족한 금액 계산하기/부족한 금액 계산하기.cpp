#include <algorithm>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = (long long)(count+1)*(count)/2*price - money;
    return max(answer, (long long)0);
}