#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, x, y;
int graph[MAX];
vector<pair<int, int>> edge;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		x--;
		y--;
		edge.push_back({x, y});
		graph[x]++;
		graph[y]++;
	}

	int l = 0, r = n-2;
	for (int i=0; i<n-1; ++i) {
		int go = edge[i].first;
		int end = edge[i].second;
		if (graph[go] == 1 || graph[end] == 1)
			cout << l++ << '\n';
		else
			cout << r-- << '\n';
	}

	return 0;
}
