class Solution {
public:
	bool checkValidString(string s) {
		stack<int> st, st2;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '(') {
				st.push(i);
			} else if (s[i] == ')') {
				if (st.empty() && st2.empty())
					return false;
				if (!st.empty())
					st.pop();
				else if (!st2.empty())
					st2.pop();
			} else {
				st2.push(i);
			}
		}

		while (!st.empty() && !st2.empty() && st.top() < st2.top()) {
			st.pop();
			st2.pop();
		}

		return st.empty();
	}
};
