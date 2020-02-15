#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int n;
int num[MAX];
bool visit[MAX];
vector<int> vec;

void dfs(int cur, int start)
{
	if (visit[cur] && cur == start)
		vec.push_back(cur);

	int next = num[cur];
	if (!visit[next]) {
		visit[next] = 1;
		dfs(next, start);
	}
}

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	for (int i=1; i<=n; ++i) {
		fill(visit, visit+MAX, 0);
		dfs(i, i);
	}

	cout << vec.size() << '\n';
	for (int i=0; i<vec.size(); ++i)
		cout << vec[i] << '\n';

	return 0;
}
