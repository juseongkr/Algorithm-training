class MyStack {
public:
	queue<int> x, y;

	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int val) {
		while (!x.empty()) {
			y.push(x.front());
			x.pop();
		}

		x.push(val);
		while (!y.empty()) {
			x.push(y.front());
			y.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int ret = x.front();
		x.pop();
		return ret;
	}

	/** Get the top element. */
	int top() {
		return x.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return x.empty() && y.empty();
	}
};
