#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0,0};
    multiset<int> ms;
    
    for(string& o:operations)
    {
        int n = stoi(o.substr(2));
        if(o[0]=='I')
        {
            ms.insert(n);
            continue;
        }
        if(ms.size()==0)
        {
            continue;
        }
        if(n>0)
        {
            ms.erase(ms.find(*ms.rbegin()));
        }
        else
        {
            ms.erase(ms.find(*ms.begin()));
        }
    }
    
    if(ms.size()>0)
    {
        answer = {*ms.rbegin(), *ms.begin()};
    }
    return answer;
}