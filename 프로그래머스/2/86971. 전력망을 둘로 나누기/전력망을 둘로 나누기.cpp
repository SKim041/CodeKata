#include <cmath>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& wires, vector<bool>& check, int v1, int& count)
{
    for(int i=0; i<wires.size(); i++)
    {
        if(check[i]) continue;
        
        check[i] = true;
        vector<int> v = wires[i];
        if(v[0]==v1 || v[1]==v1)
        {
            int temp_v1 = v[0]==v1? v[1] : v[0];
            count++;
            dfs(wires, check, temp_v1, count);
        }  
        check[i] = false;
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    vector<bool> check(wires.size(), false);
    for(int i=0; i<wires.size(); i++)
    {
        vector<int> v = wires[i];
        check[i] = true;
        int temp = 1;
        dfs(wires, check, v[0], temp);
        check[i] = false;
        temp = abs(n-temp*2); 
        answer = answer<0 || answer>=temp? temp : answer;
    }
    return answer;
}