#include <iostream>
#include <vector>
#include <cmath>
long long mod = 1000000007;
using namespace std;
long long power(long long base, long long exp)
{
    long long result =1;
    base %= mod;
    while(exp>0)
    {
        if(exp%2 == 1)
        {
            result = (result*base) % mod;
        }
        base = (base*base)%mod;
        exp/=2;
    }
    return result;
}
int main()
{
    int n, k;
    cin>>n>>k;
    if(k==0 || k==n)
    {
        cout<<1<<endl;
        return 0;
    }
    vector<long long> fact(n+1,1);
    fact[0] = 1;
    for(int i=1; i<=n; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
    }
    long long a = fact[n];
    long long b = (fact[n-k]*fact[k])%mod;
    long long result = (a*power(b, mod-2))%mod;
    cout<<result<<endl;
    return 0;
}