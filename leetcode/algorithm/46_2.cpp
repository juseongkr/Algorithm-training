class Solution {
public:
	vector<vector<int>> ret;
	vector<bool> visit;
	vector<int> num, vec;

	void permutation(void) {
		if (vec.size() == num.size()) {
			ret.push_back(vec);
			return;
		}

		for (int i=0; i<num.size(); ++i) {
			if (!visit[i]) {
				visit[i] = 1;
				vec.push_back(num[i]);
				permutation();
				vec.pop_back();
				visit[i] = 0;
			}
		}

	}

	vector<vector<int>> permute(vector<int>& nums) {
		visit.resize(nums.size(), 0);
		num = nums;
		permutation();
		return ret;
	}
};
