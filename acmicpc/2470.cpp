#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#define ll long long

int main()
{
	pair<int, int> ans;
	vector<ll> num;
	int n;
	ll t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%lld", &t);
		num.push_back(t);
	}

	sort(num.begin(), num.end());

	int left = 0;
	int right = n-1;
	ll min_val = LLONG_MAX;

	while (left < right) {
		ll sum = num[left] + num[right];
		if (llabs(sum) < min_val) {
			min_val = llabs(sum);
			ans = {left, right};
		}
		if (sum < 0)
			left++;
		else
			right--;
	}

	printf("%lld %lld\n", num[ans.first], num[ans.second]);

	return 0;
}
