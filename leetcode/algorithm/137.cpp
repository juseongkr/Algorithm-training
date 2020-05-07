class Solution {
public:
	int singleNumber(vector<int>& nums) {
		vector<int> bit(32, 0);
		for (auto i : nums) 
			for (int j=0; j<32; ++j)
				if (i & (1 << j))
					bit[j]++;

		int ans = 0;
		for (int i=0; i<32; ++i)
			if (bit[i] % 3 == 1)
				ans |= (1 << i);

		return ans;
	}
};
