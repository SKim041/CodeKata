#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct point
{
    int node;
    int dist;
};
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    unordered_map<int, unordered_set<int>> nodes;
    vector<bool> visited(n+1, false);
    queue<point> q;
    vector<point> points;
    
    q.push({1,0});
    visited[1] = true;
    
    for(auto v:edge)
    {
        nodes[v[0]].insert(v[1]);
        nodes[v[1]].insert(v[0]);
    }
    
    while(!q.empty())
    {
        point temp = q.front();
        q.pop();
        bool isLeafNode = true;
        for(int i:nodes[temp.node])
        {
            if(!visited[i])
            {
                isLeafNode = false;
                visited[i] = true;
                q.push({i,temp.dist+1});
            }
        }
        if(isLeafNode)
        {
            points.push_back(temp);
        }
    }
    sort(points.begin(), points.end(), 
        [](const auto& a, const auto& b)
         {
             return a.dist>b.dist;
         });
    int maxDist = points[0].dist;
    for(const point& p:points)
    {
        if(p.dist<maxDist)
        {
            break;
        }
        answer++;
    }
    return answer;
}