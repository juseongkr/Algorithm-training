class Solution {
public:
	bool canJump(vector<int>& nums) {
		int prev = nums.size()-1;
		for (int i=nums.size()-1; i>=0; i--)
			if (nums[i] + i >= prev)
				prev = i;
		return prev == 0;
	}
};
