class Solution {
public:
	int calculate(string s) {
		if (s.length() == 0)
			return 0;

		stack<int> st;
		st.push(1);
		int ans = 0, sign = 1;

		for (int i=0; i<s.length(); ++i) {
			char c = s[i];
			int num = 0;

			if (c == ' ')
				continue;

			if ('0' <= c && c <= '9') {
				int j = i;
				while (j < s.length() && '0' <= s[j] && s[j] <= '9')
					j++;
				j--;
				num = stoi(s.substr(i, j-i+1));
			i = j;
			} else if (c == '(') {
				st.push(sign * st.top());
				sign = 1;
			} else if (c == ')') {
				st.pop();
			} else if (c == '+') {
				sign = 1;
			} else if (c == '-') {
				sign = -1;
			}

			ans += sign * num * st.top();
		}

		return ans;
	}
};
