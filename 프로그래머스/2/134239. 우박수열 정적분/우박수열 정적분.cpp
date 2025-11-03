#include <vector>

using namespace std;

struct point
{
    int k;
    double area;
};

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<point> collatz;
    int n=0;
    collatz.push_back({k,0});
    while(k>1)
    {
        ++n;
        if(k%2==0) k/=2;
        else k = k*3 +1;
        double area = collatz[n-1].k + 0.5*(k-collatz[n-1].k);
        collatz.push_back({k,area});
    }
    for(auto& v: ranges)
    {
        double sum=0;
        int end = n+v[1];
        if(v[1]==0 && v[0]==0)
        {
            end = n;
        }
        else if(end < v[0])
        {
            answer.push_back(-1);
            continue;
        }
        else if(end == v[0])
        {
            answer.push_back(0);
            continue;
        }
        for(int i=v[0]+1; i<=end; i++)
        {
            sum+=collatz[i].area;
        }
        answer.push_back(sum);        
    }
    return answer;
}