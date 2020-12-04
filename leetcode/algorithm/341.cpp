/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
	vector<int> ans;
	int idx;

	void solve(vector<NestedInteger> &vec) {
		for (auto num : vec) {
			if (num.isInteger()) {
				ans.push_back(num.getInteger());
			} else {
				solve(num.getList());
			}
		}
	}

	NestedIterator(vector<NestedInteger> &nestedList): idx(0) {
		solve(nestedList);
	}

	int next() {
		return ans[idx++];
	}

	bool hasNext() {
		return idx < ans.size();
	}
};
