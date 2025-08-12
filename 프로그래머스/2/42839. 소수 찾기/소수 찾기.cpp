#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPrime(int num)
{
    if (num<2) return false;
    int i=2;
    while(i*i<=num)
    {
        if(num%i==0) return false;
        i++;
    }
    return true;   
}
void findPrime(string& numbers, vector<bool> used, string num, vector<int>& primenums)
{
    for(int i=0; i<numbers.size(); i++)
    {
        if(used[i]) continue;
        
        num+=numbers[i];
        used[i] = true;
        
        if(IsPrime(stoi(num))) primenums.push_back(stoi(num));
        findPrime(numbers, used, num, primenums);
        
        used[i] = false;
        num.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> used(numbers.size(), false); 
    vector<int> primenums;
    findPrime(numbers, used, "", primenums);
    sort(primenums.begin(), primenums.end());
    primenums.erase(unique(primenums.begin(), primenums.end()),primenums.end());
    answer = primenums.size();
    return answer;
}