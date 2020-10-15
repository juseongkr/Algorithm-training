#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 4000001

int n, m, k, p;
vector<int> x;
bool visit[MAX];
int y[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> p;
		x.push_back(p);
	}

	for (int i=0; i<k; ++i)
		cin >> y[i];

	sort(x.begin(), x.end());

	for (int i=0; i<k; ++i) {
		auto it = upper_bound(x.begin(), x.end(), y[i]) - x.begin();

		while (visit[it])
			it++;

		visit[it] = 1;
		cout << x[it] << '\n';
	}

	return 0;
}
