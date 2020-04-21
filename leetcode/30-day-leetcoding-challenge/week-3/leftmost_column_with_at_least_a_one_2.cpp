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
		int n = sz[1];
		int m = sz[0];

		int i = n-1, j = 0, idx = -1;
		while (1) {
			int val = binaryMatrix.get(j, i);
			if (val) {
				idx = i--;
				if (i < 0)
					return idx;
			} else {
				j++;
				if (j == m)
					return idx;
			}
		}
	}
}
