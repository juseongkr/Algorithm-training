class FooBar {
private:
	int n;
	mutex first, second;

public:
	FooBar(int n) {
		this->n = n;
		first.lock();
		second.lock();
	}

	void foo(function<void()> printFoo) {
		first.unlock();
		for (int i = 0; i < n; i++) {
			first.lock();
			printFoo();
			second.unlock();
		}
	}

	void bar(function<void()> printBar) {
		for (int i = 0; i < n; i++) {
			second.lock();
			printBar();
			first.unlock();
		}
	}
};
