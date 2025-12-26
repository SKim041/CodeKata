#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 2;
    
    int size = a.size();
    if(size<=2) return size;
    
    vector<int> minLeft(size);
    vector<int> minRight(size);
    
    minLeft[0] = a[0];
    for(int i=1; i<size; i++)
    {
        minLeft[i] = min(minLeft[i-1], a[i]);
    }
    
    minRight[size-1] = a[size-1];
    for(int i=size-2; i>=0; i--)
    {
        minRight[i] = min(minRight[i+1], a[i]);
    }
    
    for(int i=1; i<a.size()-1; i++)
    {       
        if(a[i]>minLeft[i-1] && a[i]>minRight[i+1])
        {
            continue;
        }
        answer++;
    }
    return answer;
}