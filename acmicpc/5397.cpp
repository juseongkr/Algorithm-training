#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int t;

	cin >> t;
	while (t--) {
		stack<char> a, b;
		string s;
		cin >> s;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '<' && !a.empty()) {
				b.push(a.top());
				a.pop();
			}
			if (s[i] == '>' && !b.empty()) {
				a.push(b.top());
				b.pop();
			}
			if (s[i] == '-' && !a.empty())
				a.pop();
			if (('A' <= s[i] && s[i] <= 'Z') ||
			    ('a' <= s[i] && s[i] <= 'z') ||
			    ('0' <= s[i] && s[i] <= '9'))
				a.push(s[i]);
		}
		while (!a.empty()) {
			b.push(a.top());
			a.pop();
		}

		while (!b.empty()) {
			cout << b.top();
			b.pop();
		}
		cout << '\n';
	}

	return 0;
}
