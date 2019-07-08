#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int main()
{
	map<int, int> visit;
	string s;
	char c;

	for (int i=0; i<9; ++i) {
		cin >> c;
		if (c == '0')
			c = '9';
		s += c;
	}

	queue<int> que;
	que.push(stoi(s.c_str()));

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (cur == 123456789) {
			cout << visit[123456789] << '\n';
			return 0;
		}

		s = to_string(cur);
		int k = s.find('9');
		int y = k / 3;
		int x = k % 3;

		for (int i=0; i<4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (next_y < 0 || next_x < 0 || next_y >= 3 || next_x >= 3)
				continue;

			string t = s;
			swap(t[y * 3 + x], t[next_y * 3 + next_x]);
			int next = stoi(t.c_str());

			if (!visit.count(next)) {
				visit[next] = visit[cur] + 1;
				que.push(next);
			}
		}
	}
	cout << "-1\n";

	return 0;
}
