class Solution {
public:
	bool isHappy(int n) {
		set<int> st;
		st.insert(n);

		while (1) {
			int num = 0;
			while (n) {
				num += (n%10)*(n%10);
				n /= 10;
			}
			if (num == 1)
				return true;
			if (st.count(num))
				return false;
			else
				st.insert(num);
			n = num;
		}
	}
};
