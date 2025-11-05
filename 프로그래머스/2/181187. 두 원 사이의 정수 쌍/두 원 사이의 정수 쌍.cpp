#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long temp=0;
    for(long long x=1; x<=r2; x++)
    {
        long long minY = x >= r1 ? 1 : (long long)ceil(sqrt((long long)r1*r1 - x*x));
        long long maxY = (long long)sqrt((long long)r2*r2 - x*x);
        if(maxY >= minY) 
        {
            temp += maxY - minY + 1;
        }
    }
    
    answer += (r2-r1+1)*4 + temp*4;
    return answer;
}