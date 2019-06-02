#include <iostream>
using namespace std;
#define MAX 30

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
int n, visit[MAX][MAX];
double step[4];

double dfs(int y, int x, int d)
{
	if (d == 0)
		return 1.0;

	double ret = 0.0;
	visit[y][x] = 1;
	for (int i=0; i<4; ++i) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		if (!visit[next_y][next_x])
			ret += dfs(next_y, next_x, d-1) * step[i];
	}
	visit[y][x] = 0;

	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<4; ++i) {
		scanf("%lf", &step[i]);
		step[i] /= 100.0;
	}

	printf("%.10lf\n", dfs(15, 15, n));

	return 0;
}
