#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // 중복 제거
    sort(tangerine.begin(), tangerine.end());
    vector<int> temp=tangerine;
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    // 사이즈, 개수
    vector<int> order;
    order.reserve(temp.size());
    unordered_map<int, int> sizes;
    for(int& i:tangerine)
    {
        if(sizes.find(i)==sizes.end())
        {
            order.push_back(i);            
        }
        sizes[i]+=1;
    }
    sort(order.begin(), order.end(),
        [&sizes](int a, int b)
         {
             return sizes[a]>sizes[b];
         });
    for(int i=0; i<order.size(); i++)
    {
        k-=sizes[order[i]];
        answer++;
        if(k<=0) break;
        
    }
    return answer;
}