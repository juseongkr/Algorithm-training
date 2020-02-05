#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int n, k;
vector<int> vec;
deque<int> d;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i) {
		if (i % 2)
			d.push_front(vec[i]);
		else
			d.push_back(vec[i]);
	}

	for (int i=0; i<n; ++i) {
		cout << d.front() << " ";
		d.pop_front();
	}

	return 0;
}
