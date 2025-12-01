#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
struct song
{
    string genre;
    int idx;
    int playCount;
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> playsOfGenre;
    for(int i=0; i<genres.size(); ++i)
    {
        playsOfGenre[genres[i]]+=plays[i];
    }
    vector<pair<string, int>> rank(playsOfGenre.begin(), playsOfGenre.end());
    sort(rank.begin(), rank.end(), 
         [](const auto& a, const auto& b)
         {
             return a.second>b.second;
         });
    for(const auto& p:rank)
    {
        string genre = p.first;
        vector<song> temp;
        for(int i=0; i<plays.size(); ++i)
        {
            if(genres[i] == genre)
            {
                temp.push_back({genre, i, plays[i]});
            }
        }
        sort(temp.begin(), temp.end(), 
             [](const auto& a, const auto& b)
             {
                 if(a.playCount==b.playCount) return a.idx<b.idx;
                 else return a.playCount>b.playCount;
             });
        
        for(int i=0; i<2; ++i)
        {
            answer.push_back(temp[i].idx);
            if(temp.size()<2) break;
        }
    }
    return answer;
}