#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool IsPrime(long long n)
{
    if(n<=1) return false;
    for(long long i = 2; i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string base_k;
    if(k==10) base_k = to_string(n);
    else{
        while(n>0)
        {
            base_k+=to_string(n%k);
            n = n/k;
        }
        reverse(base_k.begin(), base_k.end());
    }
    string::size_type idx=0;
    while(1)
    {   
        if(base_k[idx]=='0') 
        {
            idx++;
            if(idx>=base_k.size()) break;
            continue;
        }
        
        string temp="";
        if(base_k.find('0', idx)!=string::npos)
        {   
            temp = base_k.substr(idx, base_k.find('0', idx)-idx);  
            if(IsPrime(stoll(temp))) answer++;
            idx = base_k.find('0', idx);            
        }
        else
        {
            temp = base_k.substr(idx);
            if(IsPrime(stoll(temp))) answer++;
            break;
        }
    }
    return answer;
}