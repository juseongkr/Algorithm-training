#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int count[1000007] = {1, 0};
	stack<int> s;
	string b;
	int cnt = 0;
	int max_len = 0;

	cin >> b;

	for (int i=0; i<b.length(); ++i) {
		if (b[i] == ')') {
			if (!s.empty() && b[s.top()] == '(') {
				s.pop();
				if (s.empty())
					cnt = i + 1;
				else
					cnt = i - s.top();
				count[cnt]++;
				max_len = max(max_len, cnt);
			} else {
				s.push(i);
			}
		} else {
			s.push(i);
		}
	}

	cout << max_len << ' ' << count[max_len] << '\n';

	return 0;
}

