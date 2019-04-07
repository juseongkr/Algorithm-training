#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int visit[10001];
vector<int> li;
vector<int> vec;

void dfs()
{
	if (vec.size() == m) {
		for (int i=0; i<vec.size(); ++i)
			printf("%d ", vec[i]);
		printf("\n");

		return;
	}

	for (int i=0; i<li.size(); ++i) {
		if (visit[li[i]] == 0) {
			visit[li[i]] = 1;
			if (vec.size() == 0) {
				vec.push_back(li[i]);
				dfs();
				vec.pop_back();
			} else if (vec[vec.size()-1] < li[i]) {
				vec.push_back(li[i]);
				dfs();
				vec.pop_back();
			}
			visit[li[i]] = 0;
		}
	}
}

int main()
{
	int t;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		li.push_back(t);
	}
	sort(li.begin(), li.end());

	dfs();

	return 0;
}
