#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    // id별 신고자 리스트
    unordered_map<string, vector<string>> id_report;
    // 신고 중복 삭제
    set<string> setReport(report.begin(), report.end());
    
    // id별 신고자 리스트
    for(auto& s:setReport)
    {
        string id = s.substr(0, s.find(" "));
        string reportedId = s.substr(s.find(" ")+1);
        
        id_report[reportedId].push_back(id);
    }
    
    // k이상 신고받은 회원 신고자별 메일 받은 횟수 확인
    for(auto& p:id_report)
    {
        if(p.second.size() >= k) 
        {
            for(string& id:p.second)
            {
                answer[find(id_list.begin(), id_list.end(), id) - id_list.begin()] += 1;
            }
            
        } 
    }   
    
    return answer;
}