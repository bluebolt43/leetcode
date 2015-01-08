#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
		//A1 Z26
		int i, result, len;
		len = s.length();
		for(i=0, result=0; i<len; i++){
			result *= 26;
			result += ((int)s[i]-64);//Ascii A is 65
		}
		return result;
    }
    string convertToTitle(int n) {
        string result;
        while(n>0){
			n=n-1;//as a converter base on 26
			//cout << n<< result << endl;
			result = (char)(n%26+65) + result;
			n/=26;
		}
		return result;
    }
};

int main()
{

	Solution solution;
	cout << solution.titleToNumber("AC") << endl;
	cout << solution.convertToTitle(52) << endl;
	cout << solution.convertToTitle(1) << endl;
	cout << solution.convertToTitle(26) << endl;
	cout << solution.convertToTitle(27) << endl;
	return 0;
}
