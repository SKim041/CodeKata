#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns,0));
    // 초기화
    for(int i=0;i<rows; i++)
    {
        for(int j=0;j<columns; j++)
        {
            matrix[i][j] = i*columns + j+1;
        }   
    }
    
        for (vector<int>& v : queries)
    {
        int row = v[0] - 1;
        int col = v[1] - 1;
        int min = matrix[row][col];
        int prev, temp;
        prev = matrix[row][col];

        for (int i = 0; i < v[3] - v[1]; i++)
        {
            temp = matrix[row][col + 1];
            matrix[row][col + 1] = prev;
            if (temp < min) min = temp;
            prev = temp;
            col++;
        }
        for (int i = 0; i < v[2] - v[0]; i++)
        {
            temp = matrix[row+1][col];
            matrix[row + 1][col] = prev;
            if (temp < min) min = temp;
            prev = temp;
            row++;
        }
        for (int i = 0; i < v[3] - v[1]; i++)
        {
            temp = matrix[row][col-1];
            matrix[row][col - 1] = prev;
            if (temp < min) min = temp;
            prev = temp;
            col--;
        }
        for (int i = 0; i < v[2] - v[0]; i++)
        {
            temp = matrix[row-1][col];
            matrix[row - 1][col] = prev;
            if (temp < min) min = temp;
            prev = temp;
            row--;
        }
        answer.push_back(min);
    }
    return answer;
}