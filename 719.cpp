class Solution {
public:
    /**
     * @param str: the given string
     * @return: the maximum value
     */
    int calcMaxValue(string &str) {
        // write your code here
        int res = 0;
        int len = str.length();
        if(len == 0) return res;
        if(len == 1) return str[0] - '0';
        res = str[0] - '0';
        for(int i = 1; i < len; i++) {
        	int tmp = str[i] - '0';
        	if((res + tmp) > (res * tmp)) {
        		res = res + tmp;
        	} else {
        		res = res * tmp;
        	}
        }
        return res;
    }
};