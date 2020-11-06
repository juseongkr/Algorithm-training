class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int bit = 0;
		for (const auto n: nums)
			bit ^= n;
		bit &= (~(bit-1));

		int x = 0, y = 0;
		for (const auto n: nums) {
			if (bit & n)
				x ^= n;
			else
				y ^= n;
		}

		return {x, y};
	}
};
