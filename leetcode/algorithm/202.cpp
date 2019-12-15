class Solution {
public:
	bool isHappy(int n) {
		int sum = 0, cur = n;
		while (sum != 1) {
			sum = 0;
			while (cur) {
				sum += pow(cur % 10, 2);
				cur /= 10;
			}
			if (sum == 4)
				return false;
			cur = sum;
		}
		return true;
	}
};
