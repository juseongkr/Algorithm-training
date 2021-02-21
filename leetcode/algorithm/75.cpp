class Solution {
public:
	void sortColors(vector<int>& nums) {
		int x, y, z;
		x = y = z = 0;

		for (const auto n : nums) {
			if (n == 0)
				x++;
			else if (n == 1)
				y++;
			else
				z++;
		}

		int idx = 0;
		for (int i=0; i<x; ++i)
			nums[idx++] = 0;

		for (int i=0; i<y; ++i)
			nums[idx++] = 1;

		for (int i=0; i<z; ++i)
			nums[idx++] = 2;
	}
};
