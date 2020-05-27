#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
int n, k, carry;

int main()
{
	cin >> n >> k;
	vec.push_back(k);
	while (1) {
		int next = vec.back() * n + carry;
		vec.push_back(next % 10);
		carry = next / 10;
		if (vec.back() == k && carry == 0)
			break;
	}

	if (vec[vec.size()-2] == 0) {
		cout << "0\n";
	} else {
		for (int i=vec.size()-2; i>=0; i--)
			cout << vec[i];
	}

	return 0;
}
