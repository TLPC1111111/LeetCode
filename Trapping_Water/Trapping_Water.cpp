class Solution {
public:
	int trap(vector<int>& h) {
		int  ans;
		int n = h.size();
		vector<int> l(n, 0), r(n, 0);
		l[0] = r[n - 1] = 0;
		for (int i = 1;i < n;i++) {
			l[i] = max(h[i - 1], l[i - 1]);
		}
		for (int i = n - 2;i >= 0;i--) {
			r[i] = max(h[i + 1], r[i + 1]);
		}
		for (int i = 0;i < n;i++) {
			ans += max(0, min(l[i] - h[i], r[i] - h[i]));
		}
		return ans;
	}
};