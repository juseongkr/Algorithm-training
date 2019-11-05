#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001
const int INF = 1e6+1;
typedef pair<int, int> pii;

bool visit[MAX];
vector<pii> graph[MAX];
int n, m, s, e, x, y, z;

bool check(int k)
{
	fill(visit, visit+MAX, 0);
	queue<int> que;
	visit[s] = 1;
	que.push(s);

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == e)
			return true;
		
		for (int i=0; i<graph[cur].size(); ++i) {
			auto [next, cost] = graph[cur][i];

			if (!visit[next] && cost >= k) {
				visit[next] = 1;
				que.push(next);
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> s >> e;
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	int l = 1, r = INF;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout << r << '\n';

	return 0;
}
