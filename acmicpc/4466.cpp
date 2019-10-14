#include <iostream>
#include <stack>
using namespace std;

bool calc(char a, char op, char b)
{
	if (op == '|')
		return (a == 't' || b == 't');
	return (a == 't' && b == 't');
}

int main()
{
	int k;
	string s, flush;

	cin >> k;
	getline(cin, flush);
	for (int t=1; t<=k; ++t) {
		getline(cin, s);
		stack<char> st;
		int len = s.length();
		for (int i=0; i<len; ++i) {
			if (s[i] == ')') {
				int idx = 0;
				char x[2], op;
				while (!st.empty()) {
					char p = st.top();
					st.pop();
					if (p == '(')
						break;
					if (p == '&' || p == '|')
						op = p;
					else if (p == '!')
						x[idx-1] = x[idx-1] == 't' ? 'f' : 't';
					else
						x[idx++] = p;
				}
				st.push(calc(x[0], op, x[1]) == true ? 't' : 'f');
			} else {
				st.push(s[i]);
			}
		}
		string ans;
		while (!st.empty()) {
			ans = st.top() + ans;
			st.pop();
		}

		if (ans == "t = t" || ans == "f = f" || ans == "!f = t" || ans == "!t = f")
			cout << t << ": Good brain\n";
		else
			cout << t << ": Bad brain\n";
	}

	return 0;
}
