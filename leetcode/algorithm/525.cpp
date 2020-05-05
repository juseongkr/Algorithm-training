class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		vector<int> mp(nums.size()*2+1, -2);

		mp[nums.size()] = -1;
		int ans = 0, cnt = nums.size();
		for (int i=0; i<nums.size(); ++i) {
			cnt += nums[i] ? 1 : -1;
			if (mp[cnt] == -2)
				mp[cnt] = i;
			else
				ans = max(ans, i-mp[cnt]);
		}
		return ans;
	}
};
