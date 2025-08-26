#include <deque>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    // 1. 초기화
    long long sum1=0, sum2=0;
    deque<int> q1;
    deque<int> q2;
    for(int i = 0; i<queue1.size(); i++)
    {
        sum1+=queue1[i];
        sum2+=queue2[i];
        q1.push_back(queue1[i]);
        q2.push_back(queue2[i]);
    }
    
    // 2. 계산
    int maxTry = queue1.size()*3;
    if((sum1+sum2)%2!=0) return -1;
    while(answer<maxTry)
    {
        int temp=0;
        if(sum1==sum2) return answer;
        if(sum1>sum2)
        {
            temp = q1.front();
            q1.pop_front();
            sum1-=temp;
            sum2+=temp;
            q2.push_back(temp);            
        }
        else
        {
            temp = q2.front();
            q2.pop_front();
            sum2-=temp;
            sum1+=temp;
            q1.push_back(temp); 
        }
        answer++;
    }
    return -1;
}