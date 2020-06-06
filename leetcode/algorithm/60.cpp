class Solution {
public:
	string getPermutation(int n, int k) {
		string s;
		for (int i=1; i<=n; ++i)
			s += i+'0';

		do {
			k--;
		} while (k && next_permutation(s.begin(), s.end()));

		return s;
	}
};
