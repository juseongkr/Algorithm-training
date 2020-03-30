class Solution {
public:
	bool check(int mid, vector<int> &nums, int m) {
		int cnt = 1;
		long long sum = 0;
		for (const auto i : nums) {
			if (sum + i <= mid) {
				sum += i;
			} else {
				sum = i;
				cnt++;
			}
		}
		return cnt <= m;
	}

	int splitArray(vector<int>& nums, int m) {
		long long l = 0, r = 0;
		for (const auto i : nums) {
			l = max(l, i * 1LL);
			r += i;
		}

		while (l <= r) {
			long long mid = (l+r)/2;
			if (check(mid, nums, m))
				r = mid-1;
			else
				l = mid+1;
		}
		return l;
	}
};
