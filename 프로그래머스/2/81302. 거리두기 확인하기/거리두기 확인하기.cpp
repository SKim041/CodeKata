#include <string>
#include <vector>

using namespace std;

void covid(vector<string>& place, int i, int j, int count, bool& result, vector<vector<bool>>& visited)
{
    int sides[2] = { -1,1 };
    if (count >= 2 || !result) return;
    for (int n = 0; n < 4; n++) {
        int row = n < 2 ? i + sides[n] : i;
        int col = n < 2 ? j : j + sides[n - 2];

        if (row < 0 || col < 0 || row >= place.size() || col >= place.size()) continue;

        if (!visited[row][col]) {
            visited[row][col] = true;
            if (place[row][col] == 'P') { result = false; return; }
            else if (place[row][col] == 'X') continue;
            else covid(place, row, col, count + 1, result, visited);
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& v : places)
    {
        bool result = true;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                // 상하좌우확인
                if (v[i][j] == 'P')
                {
                    vector<vector<bool>> visited(v.size(), vector<bool>(v[0].size(), false));
                    visited[i][j] = true;
                    covid(v, i, j, 0, result, visited);
                }
                if (!result) break;
            }
            if (!result) break;
        }
        if (result) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}