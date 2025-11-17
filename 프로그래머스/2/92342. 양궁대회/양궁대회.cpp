#include <string>
#include <vector>
using namespace std;

int scoreDiff=0;
vector<int> finalVector;

vector<int> calcScore(const vector<int>& apeach,const vector<int>& lion)
{
    vector<int> result(2,0);
    for(int i=0; i<apeach.size(); i++)
    {
        if(apeach[i] < lion[i])
        {
            result[1] += 10-i;
        }
        else if(apeach[i]>0)
        {
            result[0] += 10-i;
        }
    }
    return result;
}
void dfs(int i, vector<int>& answer, int n, const vector<int>& info)
{
    if(i==info.size())
    {
        if(n>0) answer[answer.size()-1] += n;
        vector<int> score = calcScore(info, answer);
        int apeachScore = score[0];
        int myScore = score[1];
        int tempDiff = myScore-apeachScore;
        if(tempDiff>scoreDiff)
        {
            scoreDiff = tempDiff;
            finalVector = answer;
        }
        else if(tempDiff>0 && tempDiff == scoreDiff)
        {
            for(int i=info.size()-1; i>=0; i--)
            {
                if(answer[i]>finalVector[i])
                {
                    finalVector = answer;
                    break;
                }
                else if(finalVector[i]>answer[i])
                {
                    break;
                }
            }
        }
        if(n>0) answer[answer.size()-1] -= n; ;
        return;
    }
    // 어피치보다 많이 맞히기
    if(n-info[i]-1>=0)
    {
        answer[i] = info[i] + 1;
        dfs(i+1, answer, n-info[i]-1, info);
        answer[i] = 0;
    }
    // 넘기기
    dfs(i+1, answer, n,info);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(info.size(),0);
    scoreDiff = 0;
    finalVector.clear();
    
    dfs(0,answer, n, info);
    if(scoreDiff<=0) finalVector = {-1};
    return finalVector;
}