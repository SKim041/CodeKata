#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int arr1_row=0; arr1_row<arr1.size(); arr1_row++)
    {
        answer.push_back(vector<int>(arr2[0].size()));
        for(int arr2_col=0; arr2_col<arr2[0].size(); arr2_col++)
        {
            for(int arr2_row=0; arr2_row<arr2.size(); arr2_row++)
            {
                int arr1_num = arr1[arr1_row][arr2_row];
                int arr2_num = arr2[arr2_row][arr2_col];
                answer[arr1_row][arr2_col]+=arr1_num * arr2_num;
            }
        }        
    }
    
    return answer;
}