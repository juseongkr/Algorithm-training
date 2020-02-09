#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, k;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}

	int cnt, idx;
	for (int i=31; i>=0; i--) {
		cnt = 0, idx = -1;
		for (int j=0; j<n; ++j) {
			if ((1 << i) & vec[j]) {
				cnt++;
				idx = j;
			}
		}
		if (cnt == 1)
			break;
	}

	if (!cnt)
		idx = 0;
	cout << vec[idx] << " ";
	for (int i=0; i<n; ++i)
		if (i != idx)
			cout << vec[i] << " ";

	return 0;
}
