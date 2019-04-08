#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> li, vec;
int n, m, t;

void dfs()
{
	if (vec.size() == m) {
		for (int i=0; i<vec.size(); ++i) {
			printf("%d ", vec[i]);
		}
		printf("\n");
		return;
	}

	for (int i=0; i<li.size(); ++i) {
		vec.push_back(li[i]);
		dfs();
		vec.pop_back();
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		li.push_back(t);
	}

	sort(li.begin(), li.end());

	dfs();

	return 0;
}
