class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> ans;

		for (int i=0; i<input.size(); ++i) {
			char c = input[i];
			if (c == '+' || c == '-' || c == '*') {
				auto left = diffWaysToCompute(input.substr(0, i));
				auto right = diffWaysToCompute(input.substr(i+1));

				for (auto l : left) {
					for (auto r : right) {
						if (c == '+') {
							ans.push_back(l + r);
						} else if (c == '-') {
							ans.push_back(l - r);
						} else {
							ans.push_back(l * r);
						}
					}
				}
			}
		}

		if (ans.size() == 0)
			return { stoi(input) };
		return ans;
	}
};
