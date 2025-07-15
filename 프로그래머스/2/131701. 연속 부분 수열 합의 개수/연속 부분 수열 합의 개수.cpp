#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    elements.insert(elements.end(), elements.begin(), elements.end());
    vector<int> subsquence;
    subsquence.reserve(size*size);
    for(int i=1; i<=size; i++)
    {
        for(int j=0; j<size; j++)
        {
            int sum=0;
            for(vector<int>::iterator it=elements.begin()+j; it<elements.begin()+j+i; it++)
            {
                sum+=*it;
            }
            subsquence.push_back(sum);
        }    
    }
    sort(subsquence.begin(), subsquence.end());
    subsquence.erase(unique(subsquence.begin(), subsquence.end()), subsquence.end());
    answer=subsquence.size();
    return answer;
}