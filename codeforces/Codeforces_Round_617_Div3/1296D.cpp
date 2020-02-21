#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b, k, p;
vector<int> vec;

int main()
{
	cin >> n >> a >> b >> k;
	for (int i=0; i<n; ++i) {
		cin >> p;
		int val = p % (a+b);
		if (val == 0)
			vec.push_back((b-1)/a+1);
		else
			vec.push_back((val-1)/a);
	}

	sort(vec.begin(), vec.end());

	int cnt = 0;
	for (int i=0; i<n; ++i) {
		if (k >= vec[i]) {
			cnt++;
			k -= vec[i];
		} else {
			break;
		}
	}
	cout << cnt << '\n';

	return 0;
}
