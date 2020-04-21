/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		auto sz = binaryMatrix.dimensions();
		int n = sz[0];
		int m = sz[1];

		int ans = n;
		for (int i=0; i<n; ++i) {
			int l = 0, r = m;
			while (l < r) {
				int mid = (l+r)/2;
				int val = binaryMatrix.get(i, mid);
				if (val)
					r = mid;
				else
					l = mid+1;
			}
			ans = min(ans, l);
		}
		return ans == m ? -1 : ans;
	}
};
