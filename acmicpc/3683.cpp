#include <iostream>
#include <vector>
using namespace std;
#define MAX 502

int t, c, d, v;
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
	fill(A, A+v+1, -1);
	fill(B, B+v+1, -1);
	for (int i=1; i<=v; ++i) {
		fill(visit, visit+v+1, 0);
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	pair<string, string> vec[MAX];
	string a, b;

	cin >> t;
	while (t--) {
		for (int i=0; i<MAX; ++i)
			graph[i].clear();

		cin >> c >> d >> v;
		for (int i=1; i<=v; ++i) {
			cin >> a >> b;
			vec[i] = {a, b};
		}

		for (int i=1; i<=v; ++i) {
			for (int j=i+1; j<=v; ++j) {
				if (vec[i].first == vec[j].second || vec[i].second == vec[j].first) {
					if (vec[i].first[0] == 'C')
						graph[i].push_back(j);
					else
						graph[j].push_back(i);
				}
			}
		}
		cout << v - match() << '\n';
	}

	return 0;
}
