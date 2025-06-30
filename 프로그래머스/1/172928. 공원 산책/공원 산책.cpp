#include <string>
#include <vector>

using namespace std;

vector<int> findRoutes(vector<string>& park, vector<int> startPoint, int e, int s)
{
    vector<int> result(2);
    int i = e > 0 || s > 0 ? 1 : -1;
    // 공원 범위 확인
    if (startPoint[1] + e >= park[0].length() || startPoint[1] + e < 0) return startPoint;
    else if (startPoint[0] + s >= park.size() || startPoint[0] + s < 0) return startPoint;
    // 장애물 찾기
    while (e != 0)
    {
        result = { startPoint[0], startPoint[1] + i };
        if (e > 0) e--;
        else e++;
        if (park[startPoint[0]][startPoint[1] + i] == 'X')
        {
            return startPoint;
        }
        else
        {
            i = i > 0 ? i + 1 : i - 1;
        }

    }
    while (s != 0)
    {
        result = { startPoint[0] + i, startPoint[1] };
        if (s > 0) s--;
        else s++;
        if (park[startPoint[0] + i][startPoint[1]] == 'X')
        {
            return startPoint;
        }
        else
        {
            i = i > 0 ? i + 1 : i - 1;
        }

    }
    return result;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    int idx_w = park[0].length();
    int idx_h = park.size();

    vector<int> startPoint;

    // 시작점 찾기
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[0].length(); j++)
        {
            if (park[i][j] == 'S')
            {
                startPoint = { i, j };
                break;
            }
        }
        if (startPoint.size() == 2) break;
    }

    // 가는 길에 장애물을 마주치거나 공원 범위를 벗어나는 명령은 무시한다.
    for (auto& str : routes)
    {
        int e = 0;
        int s = 0;
        switch (str[0])
        {
        case 'E':
            e = str[2] - '0';
            break;
        case 'W':
            e = (str[2] - '0') * (-1);
            break;
        case 'S':
            s = str[2] - '0';
            break;
        case 'N':
            s = (str[2] - '0') * (-1);
            break;
        }
        startPoint = findRoutes(park, startPoint, e, s);
    }
    return startPoint;
}