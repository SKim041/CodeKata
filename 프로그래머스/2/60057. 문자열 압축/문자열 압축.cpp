#include <string>
using namespace std;

int solution(string s) {
	int size = (int)s.size();
	int result = size;
	int n = 0;

	while (n <= size / 2)
	{
		n++;
		string base = "";
		int count = 1;
		int tempSize = 0;
		for (int i = 0; i < size; i += n)
		{
			string temp = s.substr(i, n);
			if (i == 0)
			{
				base = temp;
				tempSize = temp.size();
				continue;
			}
			if (base == temp)
			{
				count++;
			}
			else
			{
				tempSize = count == 1 ? tempSize : tempSize + to_string(count).size();
				base = temp;
				tempSize += temp.size();
				count = 1;
			}
		}
		if (count > 1) 
		{
			tempSize += to_string(count).size();
		}
		result = result > tempSize ? tempSize : result;
	}

	return result;
}