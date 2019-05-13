#include <iostream>
#include <vector>
using namespace std;

int n;
int check[9];
vector<int> vec;

void dfs()
{
	if (vec.size() == n) {
		for (int i=0; i<n; ++i)
			cout << vec[i] << " ";
		cout << '\n';
	}

	for (int i=1; i<=n; ++i) {
		if (!check[i]) {
			check[i] = 1;
			vec.push_back(i);
			dfs();
			vec.pop_back();
			check[i] = 0;
		}
	}
}

int main()
{
	cin >> n;

	dfs();

	return 0;
}
