class Solution {
public:
	stack<int> nums;

	void evaluate(char op, int num) {
		if (op == '+') {
			nums.push(num);
		} else if (op == '-') {
			nums.push(-num);
		} else if (op == '*') {
			int last = nums.top();
			nums.pop();
			nums.push(last * num);
		} else {
			int last = nums.top();
			nums.pop();
			nums.push(last / num);
		}
	}

	int calculate(string s) {
		int num = 0;
		char op = '+';
		bool sign = true;

		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				evaluate(op, num);
				op = s[i];
				num = 0;
			} else if ('0' <= s[i] && s[i] <= '9') {
				num = 10 * num + (s[i]-'0');
			}
		}
		evaluate(op, num);

		int ans = 0;
		while (!nums.empty()) {
			ans += nums.top();
			nums.pop();
		}

		return ans;
	}
};
