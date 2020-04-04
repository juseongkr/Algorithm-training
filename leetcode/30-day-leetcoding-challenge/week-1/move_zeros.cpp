class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int idx = 0;
		for (int i=0; i<nums.size(); ++i)
			if (nums[i])
				nums[idx++] = nums[i];

		for(int i=idx; i<nums.size(); ++i)
			nums[i] = 0;
	}
};
