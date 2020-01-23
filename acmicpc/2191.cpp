#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 101
typedef pair<double, double> pdd;

double x, y;
int n, m, s, v;
vector<pdd> rat, hole;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];

bool dfs(int a)
{
	visit[a] = 1;
	for (int i=0; i<graph[a].size(); ++i) {
		int b = graph[a][i];
		if (B[b] == -1 || (!visit[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int match()
{
	int ret = 0;
	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	for (int i=0; i<MAX; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			ret++;
	}
	return ret;
}

inline double dist(pdd a, pdd b)
{
	double x = a.first - b.first;
	double y = a.second - b.second;
	return sqrt(x*x + y*y);
}

int main()
{
	cin >> n >> m >> s >> v;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		rat.push_back({x, y});
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		hole.push_back({x, y});
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (s * v >= dist(rat[i], hole[j]))
				graph[i].push_back(j);

	cout << n - match() << '\n';

	return 0;
}
