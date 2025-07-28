#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> charge;
    unordered_map<string, int> inTime;
    // 차 번호, 입차시간
    // out 이면 in 시간으로 계산해서 charge에 넣고 inTime에서 삭제
    // 다 끝나고 inTime에 남은 차들은 출차 23:59분으로 계산해서 추가
    // 요금 계산
    for(auto& s:records)
    {
        string type = s.substr(11);
        int time = stoi(s.substr(0, 2))*60 + stoi(s.substr(3, 2));
        string carNum = s.substr(6,4);
        if(type == "IN") 
        {
            inTime[carNum] = time;
        }
        else
        {
            charge[carNum] += time - inTime[carNum];
            inTime.erase(carNum);
        }       
    }
    for(auto& p : inTime)
    {
        charge[p.first] += 1439 - p.second;
    }
    answer.reserve(charge.size());
    for(auto& p : charge)
    {
        int fee = p.second <= fees[0]? fees[1] : fees[1] + ceil((float)(p.second-fees[0])/fees[2])*fees[3];
        answer.push_back(fee);
    }
    return answer;
}