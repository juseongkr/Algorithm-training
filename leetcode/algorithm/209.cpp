class Solution {
public:
	bool check(int mid, vector<int> nums, int s) {
		int sum = 0;
		for (int i=0; i<mid; ++i)
			sum += nums[i];

		for (int i=mid; i<nums.size(); ++i) {
			if (sum >= s)
				return true;
			sum += nums[i];
			sum -= nums[i-mid];
		}
		return sum >= s;
	}

	int minSubArrayLen(int s, vector<int>& nums) {
		int sum = 0;
		for (const auto i : nums)
			sum += i;

		if (sum < s)
			return 0;

		int l = 0, r = nums.size();
		while (l <= r) {
			int mid = (l+r)/2;
			if (check(mid, nums, s))
				r = mid-1;
			else
				l = mid+1;
		}
		return l;
	}
};
