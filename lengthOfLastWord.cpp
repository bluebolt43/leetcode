#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {

        int res;
        int count;
        const char* pt;

        for(pt=s, count=0, res=0; *pt!=0; pt++){
			if(*pt!=' '){
				count++;
				res=count;
			}
			else
				count=0;
		}
		return res;
    }
};
int main()
{
	const char* s = "bccdbacdbdacddabbaaaadab abadad  ";

	Solution solution;
	cout << solution.lengthOfLastWord(s) << endl;
	return 0;
}
