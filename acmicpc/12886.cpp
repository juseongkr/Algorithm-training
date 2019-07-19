#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
using namespace std;

int main()
{
	int num[3];

	for (int i=0; i<3; ++i)
		cin >> num[i];

	if ((num[0] + num[1] + num[2]) % 3 != 0) {
		cout << "0\n";
		return 0;
	}
	
	sort(num, num+3);
	set<tuple<int, int, int>> st;
	queue<tuple<int, int, int>> que;

	que.push({num[0], num[1], num[2]});
	st.insert({num[0], num[1], num[2]});

	while (!que.empty()) {
		auto [a, b, c] = que.front();
		que.pop();

		if (a == b && b == c) {
			cout << "1\n";
			return 0;
		}

		int next[3];
		if (a != b) {
			next[0] = a + a;
			next[1] = b - a;
			next[2] = c;

			sort(next, next+3);
			if (!st.count({next[0], next[1], next[2]})) {
				st.insert({next[0], next[1], next[2]});
				que.push({next[0], next[1], next[2]});
			}
			next[0] = a + a;
			next[1] = b;
			next[2] = c - a;

			sort(next, next+3);
			if (!st.count({next[0], next[1], next[2]})) {
				st.insert({next[0], next[1], next[2]});
				que.push({next[0], next[1], next[2]});
			}
		}

		if (b != c) {
			next[0] = a;
			next[1] = b + b;
			next[2] = c - b;

			sort(next, next+3);
			if (!st.count({next[0], next[1], next[2]})) {
				st.insert({next[0], next[1], next[2]});
				que.push({next[0], next[1], next[2]});
			}
		}
	}
	cout << "0\n";

	return 0;
}
