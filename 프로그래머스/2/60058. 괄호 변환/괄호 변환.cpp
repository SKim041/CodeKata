#include <string>
using namespace std;
bool isRight(string s) 
{
	if (s[0] == ')') return false;
	int cnt = 0; 
	for (char c : s) 
	{
		if (c == '(') cnt++;
		else 
		{
			cnt--;
			if (cnt < 0) return false;
		}
	}
	return cnt==0;
}

int findBalance(string s)
{
	int cnt = 0;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i] == '(') cnt++;
		else cnt--;
		if (cnt == 0) return i;
	}
	return cnt == 0 ? s.size() - 1 : -1;
}

string rf(string s) 
{
	string result = "";
	int tempIdx = findBalance(s);
	if (tempIdx < 0) return s;
	string u = s.substr(0, tempIdx + 1);
	string v = s.substr(tempIdx + 1);
	if (isRight(u))
	{
		result += u+rf(v);
	}
	else
	{
		result += "(" + rf(v) +")";
		for (int i = 1; i < u.size() - 1; i++) 
		{
			if (u[i] == '(') result += ')';
			else result += '(';
		}
	}
	return result;
}
string solution(string p) 
{
	string result = "";
	if (p == "" || isRight(p)) return p;
	result = rf(p);
	return result;
}