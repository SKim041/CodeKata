#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;
vector<string> splitString(string s, char delimiter) 
{
	vector<string> result;
	stringstream ss(s);
	string token;
	while (getline(ss, token, delimiter)) 
	{
		if(!token.empty()) result.push_back(token);
	}
	return result;
}
vector<int> solution(string s) 
{
	vector<int> result;

	// {} 다른 문자로 변경
	for (int i=0; i<s.size(); i++) 
	{
		if (s[i] == '{' || s[i] == '}') s[i] = '.';
	}

	// 집합 추출
	vector<string> group = splitString(s, '.');
	// 원소 개수 적은 순으로 정렬
	sort(group.begin(), group.end(),
		[](string a, string b)
		{
			return count(a.begin(), a.end(), ',') < count(b.begin(), b.end(), ',');
		});
	unordered_set<int> check;
	for (string element : group) 
	{
		vector<string> temp = splitString(element, ',');
		
		for (string n : temp) 
		{
            // 중복 체크 후 입력
            int num = stoi(n);
			int prev = check.size();
			check.insert(num);
			if (prev != check.size()) result.push_back(num);
		}
	}
	return result;
}