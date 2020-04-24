class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int cnt = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			cnt++;
		}
		return (m << cnt);
	}
};
