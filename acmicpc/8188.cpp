#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000001

int n, m, k;
int num[MAX];
vector<int> vec[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec[k].push_back(i);
	}

	cin >> m;
	while (m--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		int idx = -1;
		bool flag = true;
		for (int i=0; i<n; ++i) {
			int p = num[i];
			auto it = upper_bound(vec[p].begin(), vec[p].end(), idx);
			if (it == vec[p].end()) {
				flag = false;
				cout << "NIE\n";
				break;
			} else {
				idx = *it;
			}
		}

		if (flag)
			cout << "TAK\n";
	}

	return 0;
}
