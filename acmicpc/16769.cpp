#include <iostream>
using namespace std;

int main()
{
	int milk[3], bucket[3];

	for (int i=0; i<3; ++i)
		cin >> bucket[i] >> milk[i];

	for (int i=0; i<100; ++i) {
		int from = i % 3;
		int to = (from + 1) % 3;
		int sum = milk[from] + milk[to];

		if (bucket[to] > sum) {
			milk[from] = 0;
			milk[to] = sum;
		} else {
			milk[from] = sum - bucket[to];
			milk[to] = bucket[to];
		}
	}

	for (int i=0; i<3; ++i)
		cout << milk[i] << '\n';

	return 0;
}
