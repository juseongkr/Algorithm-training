#include <iostream>
using namespace std;

int n, k;
char c;
long long dict[91][7];

bool check(int B, int E, int S, int I, int G, int O, int M)
{
	return ((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 7 == 0;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> c >> k;
		dict[c][(k % 7 + 7) % 7]++;
	}

	long long ans = 0;
	for (int B=0; B<7; ++B)
		for (int E=0; E<7; ++E)
			for (int S=0; S<7; ++S)
				for (int I=0; I<7; ++I)
					for (int G=0; G<7; ++G)
						for (int O=0; O<7; ++O)
							for (int M=0; M<7; ++M)
								if (check(B, E, S, I, G, O, M))
									ans += dict['B'][B] * dict['E'][E] * dict['S'][S] * dict['I'][I] * dict['G'][G] * dict['O'][O] * dict['M'][M];

	cout << ans << '\n';

	return 0;
}
