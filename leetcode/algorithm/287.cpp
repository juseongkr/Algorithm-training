class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		set<int> st;
		for (const auto x : nums) {
			if (st.count(x))
				return x;
			st.insert(x);
		}

		return -1;
	}
};
