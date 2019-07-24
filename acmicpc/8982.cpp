#include <iostream>
#include <vector>
using namespace std;
#define MAX 40001

int level[MAX], loss[MAX];

int main()
{
	vector<int> hole;
	int n, m, x, y, x1, x2, y1, y2;

	cin >> n >> x >> y;
	for (int i=0; i<n/2-1; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j=x1; j<x2; ++j)
			level[j] = y1;
	}
	cin >> x >> y >> m;

	for (int i=0; i<m; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		hole.push_back(x1);
	}

	for (int i=0; i<hole.size(); ++i) {
		int height = level[hole[i]];
		loss[hole[i]] = height;

		for (int j=hole[i]; j>=0; j--) {
			height = min(height, level[j]);
			loss[j] = max(loss[j], height);
		}

		height = level[hole[i]];
		for (int j=hole[i]+1; j<x; ++j) {
			height = min(height, level[j]);
			loss[j] = max(loss[j], height);
		}
	}

	int ans = 0 ;
	for (int i=0; i<x; ++i)
		ans += level[i] - loss[i];

	cout << ans << '\n';

	return 0;
}
