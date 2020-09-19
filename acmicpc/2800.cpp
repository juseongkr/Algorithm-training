#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;

string s;
stack<int> st;
set<string> ans;
vector<pair<int, int>> pos;

int main()
{
	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '(') {
			st.push(i);
		} else if (s[i] == ')') {
			pos.push_back({st.top(), i});
			st.pop();
		}
	}

	int len = pos.size();
	for (int i=1; i<(1 << len); ++i) {
		string p = s;
		for (int j=0; j<len; ++j) {
			auto [l, r] = pos[j];
			if (i & (1 << j))
				p[l] = p[r] = '~';
		}

		string k;
		for (int j=0; j<p.length(); ++j)
			if (p[j] != '~')
				k += p[j];
		ans.insert(k);
	}

	for (auto s : ans)
		cout << s << '\n';

	return 0;
}
