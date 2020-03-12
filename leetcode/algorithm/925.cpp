class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int l = 0, r = 0;
		while (l < name.length() && r < typed.length()) {
			if (name[l] == typed[r])
				l++;
			r++;
		}

		return l == name.length();
	}
};
