#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

vector<int> vec;
int n, m, p, k, x, y, h;

bool check(int mid)
{
	int cur = vec[0], cnt = 1;
	for (int i=1; i<vec.size(); ++i) {
		if (cur + mid <= vec[i]) {
			cur = vec[i];
			cnt++;
		}
	}
	return cnt <= p;
}

int main()
{
	cin >> n >> m >> p >> k;
	for (int i=0; i<k; ++i) {
		cin >> x >> y;
		h = max(h, x);
		vec.push_back(y);
	}

	sort(vec.begin(), vec.end());

	int l = h, r = 1e9+7;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
