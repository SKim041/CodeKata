#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {

    vector<int> w_list;
    vector<int> h_list;
    
    for (int i = 0; i < sizes.size(); i++) {
        w_list.push_back(min(sizes[i][0], sizes[i][1]));
        h_list.push_back(max(sizes[i][0], sizes[i][1]));
    }
    
    int w = *(max_element(w_list.begin(), w_list.end()));
    int h = *(max_element(h_list.begin(), h_list.end()));

    return w * h;
}