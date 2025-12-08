#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct job
{
    int idx;
    int requestTime;
    int taskTime;
};
struct comp
{
    // 소요시간, 시작시각, 작업번호
    bool operator()(const job& a,const job& b)
    {
        if(a.taskTime==b.taskTime)
        {
            if(a.requestTime==b.requestTime)
            {
                return a.idx>b.idx;
            }
            return a.requestTime>b.requestTime;
        }
        return a.taskTime>b.taskTime;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 요청 시각 순으로 정렬
    vector<job> jobOrder;
    for(int i=0; i<jobs.size(); ++i)
    {
        jobOrder.push_back({i, jobs[i][0], jobs[i][1]});
    }
    sort(jobOrder.begin(), jobOrder.end(), 
         [](const auto& a,const auto& b)
         {
             return a.requestTime<b.requestTime;
         });
    
    // 작업
    priority_queue<job, vector<job>, comp> q;
    int jobOrderIdx = 0;
    int currentTime = 0;
    do 
    {
        if(q.empty())
        {
            currentTime = jobOrder[jobOrderIdx].requestTime;
        }
        else
        {
            job temp = q.top();
            q.pop();
            currentTime += temp.taskTime;
            answer += currentTime - temp.requestTime;
        }
        while(jobOrderIdx<jobOrder.size() 
              && currentTime>=jobOrder[jobOrderIdx].requestTime)
        {
            q.push(jobOrder[jobOrderIdx]);
            jobOrderIdx++;
        }
    }
    while(!q.empty() || jobOrderIdx<jobOrder.size());

    answer/=jobs.size();
    return answer;
}