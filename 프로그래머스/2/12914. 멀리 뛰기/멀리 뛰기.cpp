using namespace std;

long long solution(int n) {
    if(n<2) return 1;
    int a=1;
    int b=1;
    for(int i=2; i<=n; i++)
    {   
        int temp = (a+b) % 1234567;
        a=b;
        b=temp;
    }
    return b;
}