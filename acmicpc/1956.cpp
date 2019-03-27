#include <iostream>
using namespace std;
#define MAX_VAL 10000001

int graph[401][401];

int main()
{
	int v, e, a, b, c, min_val = MAX_VAL;

	scanf("%d %d", &v, &e);

	for (int i=1; i<=v; ++i)
		graph[i][i] = MAX_VAL;

	for (int i=0; i<e; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
	}

	for (int k=1; k<=v; ++k) {
		for (int i=1; i<=v; ++i) {
			for (int j=1; j<=v; ++j) {
				if (graph[i][j] == 0 || graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	for (int i=1; i<=v; ++i)
		min_val = min(min_val, graph[i][i]);

	if (min_val == MAX_VAL)
		printf("-1\n");
	else
		printf("%d\n", min_val);

	return 0;
}
