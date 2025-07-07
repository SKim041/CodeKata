#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int i = 1;
    // a가 더 작은 값
    if(a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while(n > 1)
    {
        if(a % 2 == 1 && a + 1 == b) break;
        a = ceil(a/2.0f);
        b = ceil(b/2.0f);
        n /= 2;
        i++;
    }
    return i;
}