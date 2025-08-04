#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int>Slice1;
    unordered_map<int, int>Slice2;
    
    for(int i=0; i<topping.size(); i++)
    {
        Slice2[topping[i]]++;
    }
    
    for(int i=0; i<topping.size(); i++)
    {
        Slice1[topping[i]]++;
        Slice2[topping[i]]--;
        if(Slice2[topping[i]] == 0)
        {
            Slice2.erase(topping[i]);
        }
        if(Slice1.size() == Slice2.size()) answer++;
        else if(Slice1.size() > Slice2.size()) break;
    }
    
    return answer;
}