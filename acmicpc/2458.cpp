#include <iostream>
using namespace std;

#define MAX_VAL 501
#define INF 100000000
int graph[MAX_VAL][MAX_VAL];

int main()
{
	int n, m, a, b, cnt, ans = 0;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;

	for (int i=1; i<=n; ++i) {
		cnt = 1;
		for (int j=1; j<=n; ++j)
			cnt += (graph[i][j] + graph[j][i]);
		if (cnt == n)
			ans++;
	}
	
	printf("%d\n", ans);

	return 0;
}
