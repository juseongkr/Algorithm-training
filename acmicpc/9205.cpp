#include <iostream>
using namespace std;
#define fi first
#define se second

pair<int, int> shop[102];
int visit[102];
int t, n;

void dfs(int s)
{
	visit[s] = 1;
	for (int i=1; i<n+2; ++i) {
		if (visit[i] == 0) {
			int dist = abs(shop[s].fi - shop[i].fi) + abs(shop[s].se - shop[i].se);
			if (dist <= 1000) {
				dfs(i);
			}
		}
	}

}

int main()
{
	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		scanf("%d", &n);
		for (int j=0; j<n+2; ++j)
			scanf("%d %d", &shop[j].fi, &shop[j].se);

		dfs(0);

		if (visit[n+1])
			printf("happy\n");
		else
			printf("sad\n");

		for (int i=0; i<n+2; ++i)
			visit[i] = 0;
	}
	return 0;
}
