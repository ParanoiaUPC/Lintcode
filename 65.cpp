class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        if(lenA > lenB) return findMedianSortedArrays(B, A);
        if(lenB <= 0) return -1;
        int left = 0, right = lenA;
        while(left <= right) {
        	int mid1 = (left + right) / 2;
        	int mid2 = (lenA + lenB + 1) / 2 - mid1;
        	if(mid1 < lenA && A[mid1] < B[mid2 - 1]) {
        		left = mid1 + 1;
        	} else if(mid1 > 0 && A[mid1 - 1] > B[mid2]) {
        		right = mid1 - 1;
        	} else {
        		int left_max, right_min;
        		if(mid1 == 0) left_max = B[mid2 - 1];
        		else if(mid2 == 0) left_max = A[mid1 - 1];
        		else left_max = max(A[mid1 - 1], B[mid2 - 1]);
        		if((lenA + lenB) % 2== 1) return left_max;

        		if(mid1 == lenA) right_min = B[mid2];
        		else if(mid2 == lenB) right_min = A[mid1];
        		else right_min = min(A[mid1], B[mid2]);
        		return 0.5 * (left_max + right_min);
        	}
        }
    }
};