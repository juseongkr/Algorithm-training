#include <iostream>
using namespace std;

int main()
{	
	string color[10] = {"black", "brown", "red", "orange", "yellow", 
			    "green", "blue", "violet", "grey", "white" };

	string c1, c2, c3;
	long long sum = 0;

	cin >> c1 >> c2 >> c3;

	for (int i=0; i<10; ++i) {
		if (c1 == color[i])
			sum += i * 10;
		if (c2 == color[i])
			sum += i;
	}

	for (int i=0; i<10; ++i)
		if (c3 == color[i])
			for (int j=0; j<i; ++j)
				sum *= 10;

	cout << sum << '\n';

	return 0;
}
