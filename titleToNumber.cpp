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
};

int main()
{

	Solution solution;
	cout << solution.titleToNumber("AC") << endl;
	return 0;
}
