#include <vector>
#include <algorithm>

using namespace std;

int parent[100];

int find(int x)
{
    // 경로 압축
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // parent 초기화
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(),
        [](const auto& a, const auto& b)
         {
             return a[2]<b[2];
         });
    int edgeCount = 0;
    for(const auto& cost:costs)
    {
        int from = cost[0];
        int to = cost[1];
        int weight = cost[2];
        
        // 최상위 부모가 같지 않으면 선택
        if(find(from)!=find(to))
        {
            unite(from, to);
            answer += weight;
            ++edgeCount;
            
            // n-1개의 간선을 선택하면 종료
            if(edgeCount == n-1)
            {
                break;
            }
        }
    }
    return answer;
}