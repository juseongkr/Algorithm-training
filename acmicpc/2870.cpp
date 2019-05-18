#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool check(char c) { return ('0' <= c && c <= '9'); }

int main()
{
	vector<vector<int>> ans;
	string s;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		queue<int> que;
		int len = s.length();
		for (int j=0; j<len; ++j) {
			if (check(s[j]))
				que.push(s[j]-'0');

			if ((!check(s[j]) || j == len-1) && que.size() != 0) {
				while (!que.empty() && que.front() == 0)
					que.pop();

				vector<int> vec;
				while (!que.empty()) {
					vec.push_back(que.front());
					que.pop();
				}

				if (vec.size() == 0)
					vec.push_back(0);
				ans.push_back(vec);
			}
		}
	}

	sort(ans.begin(), ans.end());

	for (int k=0; k<=100; ++k) {
		for (int i=0; i<ans.size(); ++i) {
			if (ans[i].size() == k) {
				for (int j=0; j<ans[i].size(); ++j)
					cout << ans[i][j];
				cout << '\n';
			}
		}
	}

	return 0;
}
