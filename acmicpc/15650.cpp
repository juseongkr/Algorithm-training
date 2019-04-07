#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visit[10];
vector<int> vec;

void dfs()
{
	if (vec.size() == m) {
		for (int i=0; i<vec.size(); ++i)
			printf("%d ", vec[i]);
		printf("\n");

		return;
	}

	for (int i=1; i<=n; ++i) {
		if (visit[i] == 0) {
			visit[i] = 1;
			if (vec.size() == 0) {
				vec.push_back(i);
				dfs();
				vec.pop_back();
			} else if (vec.back() < i) {
				vec.push_back(i);
				dfs();
				vec.pop_back();
			}
			visit[i] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	dfs();

	return 0;
}
