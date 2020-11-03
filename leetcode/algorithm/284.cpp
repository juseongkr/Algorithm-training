/*
* Below is the interface for Iterator, which is already defined for you.
* **DO NOT** modify the interface for Iterator.
*
*  class Iterator {
*		struct Data;
* 		Data* data;
*		Iterator(const vector<int>& nums);
* 		Iterator(const Iterator& iter);
*
* 		// Returns the next element in the iteration.
*		int next();
*
*		// Returns true if the iteration has more elements.
*		bool hasNext() const;
*	};
*/

class PeekingIterator : public Iterator {
private:
	int value;
	bool peeked;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), value(0), peeked(false) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (this->peeked)
			return this->value;

		this->peeked = Iterator::hasNext();
		this->value = Iterator::next();

		return this->value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if (this->peeked) {
			this->peeked = false;
			return this->value;
		}

		return Iterator::next();
	}

	bool hasNext() const {
		return this->peeked ? true : Iterator::hasNext();
	}
};
