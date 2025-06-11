#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int n=0; n<commands.size(); n++){
        vector<int> temp(array.begin()+commands[n][0]-1,array.begin()+commands[n][1]);
        sort(temp.begin(), temp.end());
        int num = temp[commands[n][2]-1];
        answer.push_back(num);
    }
    return answer;
}