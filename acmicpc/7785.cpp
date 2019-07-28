#include <iostream>
#include <stack>
#include <set>
using namespace std;

int main()
{
	int n;
	set<string> m;
	stack<string> st;

	cin >> n;
	while (n--) {
		string s, t;
		cin >> s >> t;
		if (t == "enter") {
			m.insert(s);
		} else {
			if (m.count(s))
				m.erase(s);
		}
	}
	for (auto it : m)
		st.push(it);

	while (!st.empty()) {
		cout << st.top() << '\n';
		st.pop();
	}

	return 0;
}
