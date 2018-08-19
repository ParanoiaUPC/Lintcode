
class Solution {
public:
	/**
	 * @param n an integer
	 * @return a list of pair<sum, probability>
	 */
	vector<pair<int, double> > dicesSum(int n) {
		// Write your code here
		vector<pair<int, double> > res;
		if (n == 0) {
			return res;
		}
		if (n == 1) {
			for (int i = 1; i <= 6; i++) {
				res.push_back(make_pair(i, (double)1 / 6));
			}
			return res;
		}
		vector<double> pre(6 * n + 1);
		vector<double> cur(6 * n + 1);
		vector<double> *cur_ref = &cur;
		vector<double> *pre_ref = &pre;
		for (int i = 1; i <= 6; i++) {
			pre[i] = 1.0 / 6;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= 6 * i; j++) {
				//cout<<endl<<"J:"<<j;
				(*cur_ref)[j] = 0;
				for (int k = 1; k <= 6; k++) {
					if ((j - k) >= (i - 1) && (j - k) <= 6 * (i - 1)) { // Important here
						//cout<<"  J-K:"<<pre_ref->at(j - k);
						double newt = cur_ref->at(j) + pre_ref->at(j - k);
						(*cur_ref)[j] = newt;
					}
				}
				(*cur_ref)[j] = cur_ref->at(j) / 6;
			}
			vector<double> *tmp = cur_ref;
			cur_ref = pre_ref;
			pre_ref = tmp;
		}
		for (int i = n; i <= 6 * n; i++) {
			res.push_back(make_pair(i, pre_ref->at(i)));
		}
		return res;
	}
};
