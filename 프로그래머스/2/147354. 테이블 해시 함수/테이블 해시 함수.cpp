#include <vector>
#include <algorithm>

using namespace std;
int getMod(vector<int>& v, int modNum)
{
    int result = 0;
    for(int& i:v)
    {
        result += i % modNum;
    }
    return result;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    col-= 1;
    sort(data.begin(), data.end(),
        [&](vector<int> a, vector<int> b)
         {
            if(a[col]<b[col]) return true;
            else if(a[col] == b[col] && a[0]>b[0]) return true;
            else return false;
         });
    
    for(int i=row_begin; i<=row_end; i++)
    {
        vector<int> v = data[i-1];
        int si = getMod(v,i);
        if(i==row_begin)
        {
            answer = si;
        }
        else
        {
            answer = answer^si;
        }
    }

    return answer;
}