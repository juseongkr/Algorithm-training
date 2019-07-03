#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> a, b;
	string s;
	char op, k;
	int n;

	cin >> s >> n;
	for (int i=0; i<s.length(); ++i)
		a.push(s[i]);

	for (int i=0; i<n; ++i) {
		cin >> op;
		if (op == 'P') {
			cin >> k;
			a.push(k);
		} else if (op == 'L') {
			if (!a.empty()) {
				b.push(a.top());
				a.pop();
			}
		} else if (op == 'D') {
			if (!b.empty()) {
				a.push(b.top());
				b.pop();
			}
		} else {
			if (!a.empty())
				a.pop();
		}
	}

	while (!a.empty()) {
		b.push(a.top());
		a.pop();
	}

	while (!b.empty()) {
		cout << b.top();
		b.pop();
	}

	return 0;
}
