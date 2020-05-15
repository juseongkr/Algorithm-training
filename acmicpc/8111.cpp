#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 20001

int T, n;
bool visit[MAX];
int pre[MAX];
char cha[MAX];

string solve()
{
	queue<int> que;
	visit[1] = 1;
	que.push(1);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<2; ++i) {
			int next = (cur * 10 + i) % n;
			if (!visit[next]) {
				visit[next] = 1;
				pre[next] = cur;
				cha[next] = i;
				que.push(next);
			}
		}
	}

	string ret;
	for (int cur=0; cur!=1; cur=pre[cur])
		ret += cha[cur]+'0';
	ret += '1';

	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;

		fill(visit, visit+MAX, 0);
		fill(pre, pre+MAX, 0);
		fill(cha, cha+MAX, 0);

		cout << solve() << '\n';
	}

	return 0;
}
