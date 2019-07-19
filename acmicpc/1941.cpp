#include <iostream>
#include <queue>
using namespace std;
#define MAX 25

const int dy[4] = {1, 0, 0, -1};
const int dx[4] = {0, 1, -1, 0};
int visit[MAX], picked[MAX];
string map[5];
int ans;

int get_size()
{
	int ret = 0;
	queue<int> que;
	fill(visit, visit+MAX, 0);
	for (int i=0; i<MAX; ++i) {
		if (picked[i]) {
			que.push(i);
			visit[i] = 1;
			ret++;
			break;
		}
	}

	while (!que.empty()) {
		int k = que.front();
		que.pop();

		for (int i=0; i<4; ++i) {
			int next_y = k/5 + dy[i];
			int next_x = k%5 + dx[i];
			int next = 5 * next_y + next_x;

			if (next_y < 0 || next_x < 0 || next_y >= 5 || next_x >= 5)
				continue;

			if (!visit[next] && picked[next]) {
				visit[next] = 1;
				que.push(next);
				ret++;
			}
		}
	}
	return ret;
}

bool is_win()
{
	int cnt = 0;
	for (int i=0; i<MAX; ++i)
		if (picked[i] && map[i/5][i%5] == 'S')
			cnt++;

	if (cnt >= 4)
		return true;
	return false;
}

void pick(int cnt, int k)
{
	if (k >= MAX)
		return;

	if (cnt == 7) {
		if (is_win() && get_size() == 7)
			ans++;
		return;
	}

	for (int i=k+1; i<MAX; ++i) {
		picked[i] = 1;
		pick(cnt+1, i);
		picked[i] = 0;
	}
}

int main()
{
	for (int i=0; i<5; ++i)
		cin >> map[i];

	pick(0, -1);

	cout << ans << '\n';

	return 0;
}
