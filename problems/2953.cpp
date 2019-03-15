#include <iostream>
using namespace std;

int chef[5];

int main()
{
	int val, idx, max_val = 0;
	
	for (int i=0; i<5; ++i) {
		for (int j=0; j<4; ++j) {
			cin >> val;
			chef[i] += val;
		}
	}

	for (int i=0; i<5; ++i) {
		if (max_val < chef[i]) {
			max_val = chef[i];
			idx = i;
		}
	}

	cout << idx + 1 << " " << max_val << '\n';

	return 0;
}
