#include <iostream>
#include <queue>
using namespace std;

int visit[10000001];
int dept[10000001];
int f, s, g, u, d;

void bfs()
{
	queue<int> que;
	que.push(s);
	visit[s] = 1;

	while (!que.empty()) {
		int pos = que.front();
		que.pop();

		int up = pos + u;
		int down = pos - d;
		if (up <= f && visit[up] == 0) {
			que.push(up);
			visit[up] = 1;
			dept[up] = dept[pos] + 1;
		}

		if (down > 0 && visit[down] == 0) {
			que.push(down);
			visit[down] = 1;
			dept[down] = dept[pos] + 1;
		}
	}
}

int main()
{
	cin >> f >> s >> g >> u >> d;

	bfs();
	
	if (visit[g])
		cout << dept[g] << '\n';
	else
		cout << "use the stairs\n";

	return 0;
}
