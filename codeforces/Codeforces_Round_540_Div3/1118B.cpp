#include <iostream>
#include <vector>
using namespace std;

int n, k, even, odd, cur_odd, cur_even, ans;
vector<int> vec;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
		if (i % 2)
			odd += k;
		else
			even += k;
	}

	for (int i=0; i<n; ++i) {
		if (i % 2)
			odd -= vec[i];
		else
			even -= vec[i];

		if (even + cur_even == odd + cur_odd)
			ans++;

		if (i % 2)
			cur_even += vec[i];
		else
			cur_odd += vec[i];
	}
	cout << ans << '\n';

	return 0;
}
