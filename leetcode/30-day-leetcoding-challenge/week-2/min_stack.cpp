class MinStack {
public:
	stack<pair<int, int>> st;
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (st.empty()) {
			st.push({x, x});
		} else {
			int mi = st.top().second;
			st.push({x, min(mi, x)});
		}
	}

	void pop() {
		if (!st.empty())
			st.pop();
	}

	int top() {
		return st.top().first;
	}

	int getMin() {
		return st.top().second;
	}
};
