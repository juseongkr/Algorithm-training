#include <iostream>
using namespace std;

int n, t, cnt;
int student[100001], visit[100001], finish[100001];

void dfs(int s)
{
	visit[s] = 1;
	int next = student[s];

	if (visit[next] == 0) {
		dfs(next);
	} else if (finish[next] == 0) {
		cnt++;
		for (int i=next; i!=s; i=student[i])
			cnt++;
	}
	finish[s] = 1;
}

int main()
{
	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		scanf("%d", &n);

		for (int j=1; j<=n; ++j)
			scanf("%d", &student[j]);

		for (int j=1; j<=n; ++j) {
			visit[j] = 0;
			finish[j] = 0;
		}

		cnt = 0;
		for (int j=1; j<=n; ++j)
			if (visit[j] == 0)
				dfs(j);

		printf("%d\n", n - cnt);
	}

	return 0;
}
