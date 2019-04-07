#include <iostream>
#include <vector>
using namespace std;

int n, m;
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
		if (vec.size() == 0 || vec[vec.size()-1] <= i) {
			vec.push_back(i);
			dfs();
			vec.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	dfs();

	return 0;
}
