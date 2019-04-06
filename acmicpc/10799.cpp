#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> st;
	string s;
	int cnt = 0;

	cin >> s;
	for (int i=0; i<s.size(); ++i) {
		if (s[i] == '(') {
			st.push(s[i]);
		} else {
			st.pop();
			if (s[i-1] == '(')
				cnt += st.size();
			else
				cnt += 1;
		}
	}

	cout << cnt << '\n';

	return 0;
}
