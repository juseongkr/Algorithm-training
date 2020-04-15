class Solution {
public:
	string stringShift(string s, vector<vector<int>>& shift) {
		int sz = 0;
		for (int i=0; i<shift.size(); ++i)
			sz += shift[i][0] ? shift[i][1] : -shift[i][1];

		if (sz > 0) {
			sz %= s.length();
			return s.substr(s.length()-sz) + s.substr(0, s.length()-sz);
		}
		sz = -sz;
		sz %= s.length();
		return s.substr(sz) + s.substr(0, sz);
	}
};
