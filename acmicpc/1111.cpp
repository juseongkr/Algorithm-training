#include <iostream>
#include <vector>
using namespace std;
#define MAX 51

int n, k;
vector<int> num;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		num.push_back(k);
	}

	if (n == 1) {
		cout << "A\n";
		return 0;
	}

	if (n == 2) {
		if (num[0] == num[1])
			cout << num[0] << '\n';
		else
			cout << "A\n";
		return 0;
	}

	if (num[0] == num[1]) {
		for (int i=0; i<n-1; ++i) {
			if (num[i] != num[i+1]) {
				cout << "B\n";
				return 0;
			}
		}
		cout << num[0] << '\n';
		return 0;
	} else {
		int x = num[2] - num[1];
		int y = num[1] - num[0];
		int a = x / y;
		int b = num[1] - num[0] * a;
		for (int i=0; i<n-1; ++i) {
			if (a * num[i] + b != num[i+1]) {
				cout << "B\n";
				return 0;
			}
		}
		cout << a * num[n-1] + b << '\n';
	}

	return 0;
}
