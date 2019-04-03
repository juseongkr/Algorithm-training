#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[123458];
char type[123458];
long long value[123458];
int n, c;

long long dfs(int s)
{
	long long ret = 0;
	for (int i=0; i<graph[s].size(); ++i)
		ret += dfs(graph[s][i]);

	if (type[s] == 'W') {
		if (ret - value[s] < 0)
			return 0;
		else
			return ret - value[s];
	} else {
		return ret + value[s];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=2; i<=n; ++i) {
		cin >> type[i] >> value[i] >> c;
		graph[c].push_back(i);
	}
	
	printf("%lld\n", dfs(1));

	return 0;
}
