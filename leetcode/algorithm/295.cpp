class MedianFinder {
public:
	priority_queue<int> large;
	priority_queue<int, vector<int>, greater<int>> small;

	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		large.push(num);
		int tp = large.top();
		large.pop();
		small.push(tp);

		if (large.size() < small.size()) {
			tp = small.top();
			small.pop();
			large.push(tp);
		}
	}

	double findMedian() {
		if (large.size() > small.size()) {
			return large.top();
		}
		return (large.top() + small.top()) / 2.0;
	}
};
