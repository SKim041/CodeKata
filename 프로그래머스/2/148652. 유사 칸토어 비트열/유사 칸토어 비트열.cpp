#include <string>
#include <cmath>

using namespace std;

// 1
// 11011
// 11011 11011 00000 11011 11011 -> 5^(n-1)
int CheckOne(long long idx, int n)
{
    if(n==0) return 1;
    long long group = pow(5, n-1);
    long long i = idx/group;
    if(i==2) return 0;
    return CheckOne(idx%group, n-1);
}
int solution(int n, long long l, long long r) {
    int answer = 0;
    for(long long i=l-1; i<r; ++i)
    {
        answer += CheckOne(i,n);
    }
    return answer;
}