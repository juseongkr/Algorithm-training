class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		long long x = abs(C-A) * abs(D-B);
		long long y = abs(G-E) * abs(H-F);

		if (B >= H || C <= E || A >= G || F >= D)
			return x + y;
		return x + y - (min(C, G) - max(A, E)) * (min(H, D) - max(B, F));
	}
};
