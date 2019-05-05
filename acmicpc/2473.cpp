#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;

#define ll long long

int main()
{
	tuple<int, int, int> ans;
	vector<ll> num;
	int n;
	ll t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%lld", &t);
		num.push_back(t);
	}

	sort(num.begin(), num.end());

	ll min_val = LLONG_MAX;
	for (int left=0; left<n; ++left) {
		int mid = left+1;
		int right = n-1;
		while (mid < right) {
			ll sum = num[left] + num[mid] + num[right];
			if (llabs(sum) < min_val) {
				min_val = llabs(sum);
				ans = {left, mid, right};
			}
			if (sum < 0)
				mid++;
			else
				right--;
		}
	}

	printf("%lld %lld %lld\n", num[get<0>(ans)], num[get<1>(ans)], num[get<2>(ans)]);

	return 0;
}
