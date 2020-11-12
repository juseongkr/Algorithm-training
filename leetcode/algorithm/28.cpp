class Solution {
public:
	vector<int> fail;
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
			return 0;
		if (haystack.length() == 0)
			return -1;

		fail.resize(needle.length());
		for (int i=1, j=0; i<needle.length(); ++i) {
			while (j && needle[i] != needle[j])
				j = fail[j-1];

			if (needle[i] == needle[j])
				fail[i] = ++j;
		}

		for (int i=0, j=0; i<haystack.length(); ++i) {
			while (j && haystack[i] != needle[j])
				j = fail[j-1];

			if (haystack[i] == needle[j]) {
				if (j == needle.length()-1) {
					return i - needle.length()+1;
					j = fail[j];
				} else {
					j++;
				}
			}
		}
		return -1;
	}
};
