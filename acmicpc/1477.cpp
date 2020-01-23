#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, l, k;
vector<int> vec;

bool check(int mid)
{
	int ret = 0;
	for (int i=0; i<vec.size()-1; ++i)
		ret += (vec[i+1] - vec[i] - 1) / mid;

	return ret > m;
}

int main()
{
	cin >> n >> m >> l;
	vec.push_back(0);
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}
	vec.push_back(l);

	sort(vec.begin(), vec.end());

	int x = 0, y = l;
	while (x <= y) {
		int mid = (x+y)/2;
		if (check(mid))
			x = mid+1;
		else
			y = mid-1;
	}
	cout << x << '\n';

	return 0;
}
