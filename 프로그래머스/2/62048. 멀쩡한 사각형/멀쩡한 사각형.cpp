using namespace std;


int getGcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return getGcd(b, a % b);
}

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    int gcd = getGcd(w, h);
    long long count = (long long)w + h - gcd;      
    return answer - count;
}