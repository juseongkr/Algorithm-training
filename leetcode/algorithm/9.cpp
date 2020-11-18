class Solution {
public:
	bool isPalindrome(int x) {
		string num = to_string(x);
		int n = num.length();

		for (int i=0; i<n; ++i)
			if (num[i] != num[n-1-i])
				return false;

		return true;
	}
};
