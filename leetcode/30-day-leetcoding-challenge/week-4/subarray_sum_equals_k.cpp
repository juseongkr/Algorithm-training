class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		mp[0] = 1;
		int sum = 0, ret = 0;
		for (const auto i : nums) {
			sum += i;
			ret += mp[sum - k];
			mp[sum]++;
		}
		return ret;
	}
};
