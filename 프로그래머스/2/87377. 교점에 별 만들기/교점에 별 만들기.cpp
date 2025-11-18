#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<long long,long long>> points;
    
    for(int i=0; i<line.size()-1; i++)
    {
        long long A1 = line[i][0], B1 = line[i][1], C1 = line[i][2];
        for(int j=i+1; j<line.size(); j++)
        {
            long long A2 = line[j][0], B2 = line[j][1], C2 = line[j][2];
            
            long long denominator = B2*A1-B1*A2;
            if(denominator == 0) continue;
            
            long long numeratorX = B1*C2-B2*C1;
            long long numeratorY = A2*C1-A1*C2;
            
            if(numeratorX%denominator==0 && numeratorY%denominator==0)
            {
                points.insert({numeratorX / denominator, numeratorY / denominator});
            }
        }
    }
    
    long long minX = 1e12, maxX = -1e12;
    long long minY = 1e12, maxY = -1e12;
    for(const auto& p:points)
    {
        long long x=p.first;
        long long y=p.second;
        if(x<minX) minX = x;
        if(x>maxX) maxX = x;
        if(y<minY) minY = y;
        if(y>maxY) maxY = y;
    }

    answer = vector<string>(maxY-minY+1,string(maxX-minX+1,'.'));
    for(const auto& p:points)
    {
        answer[maxY - p.second][p.first - minX] = '*';
    }
    return answer;
}