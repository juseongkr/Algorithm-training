class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;

		double ret = myPow(x, n/2);
		if (n % 2)
			return ret * ret * (n < 0 ? 1/x : x);
		return ret * ret;
	}
};
