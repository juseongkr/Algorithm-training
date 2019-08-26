#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001

int n, t, len;
int a[MAX], b[MAX];
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<n; ++i) {
		cin >> t;
		b[t] = i;
	}

	vec.push_back(-1e9+7);
	for (int i=0; i<n; ++i) {
		if (vec.back() < b[a[i]]) {
			vec.push_back(b[a[i]]);
			len++;
		} else {
			auto it = lower_bound(vec.begin(), vec.end(), b[a[i]]);
			*it = b[a[i]];
		}
	}
	cout << len << '\n';

	return 0;
}
