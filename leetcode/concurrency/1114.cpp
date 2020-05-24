class Foo {
private:
	mutex mutex_first, mutex_second;

public:
	Foo() {
		mutex_first.lock();
		mutex_second.lock();
	}

	void first(function<void()> printFirst) {
		printFirst();
		mutex_first.unlock();
	}

	void second(function<void()> printSecond) {
		mutex_first.lock();
		printSecond();
		mutex_second.unlock();
	}

	void third(function<void()> printThird) {
		mutex_second.lock();
		printThird();
	}
};
