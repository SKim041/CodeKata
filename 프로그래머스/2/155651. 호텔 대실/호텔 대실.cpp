#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int convertTime(string s)
{
    int result = stoi(s.substr(0,2))*60 + stoi(s.substr(3));
    return result;
}

// 입실 시간으로 정렬
// 퇴실 시간 + 10 보다 큰 입실시간 예약 찾기

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<int>> room;
    sort(book_time.begin(), book_time.end(), 
        [](vector<string> a, vector<string> b)
         {
             return convertTime(a[0])<convertTime(b[0]);
         });
    room.push_back(vector<int>{0});
    for(int i=1; i<book_time.size(); i++)
    {
        bool isAssigned = false;
        for(vector<int>& v:room)
        {
            // 마지막 원소의 퇴실시간+10<입실시간 비교
            int idx = v[v.size() - 1];
            int last = convertTime(book_time[idx][1]);
            if (last + 10 <= convertTime(book_time[i][0]))
            {
                v.push_back(i);
                isAssigned = true;
                break;
            }
        }
        if (!isAssigned)
        {
            room.push_back(vector<int>{i});
        }
    }
    answer = room.size();
    return answer;
}