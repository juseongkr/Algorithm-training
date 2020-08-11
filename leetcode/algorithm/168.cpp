class Solution {
public:
	string convertToTitle(int n) {
		string s;

		while (n) {
			n--;
			s += 'A' + (n % 26);
			n /= 26;
		}
		reverse(s.begin(), s.end());

		return s;
	}
};
