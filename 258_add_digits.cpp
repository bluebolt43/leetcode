#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
		int result = num%9;
        if( result==0 && num!=0)
			return 9;
		return result;
    }
};

int main()
{

	Solution solution;
	cout << solution.addDigits(9) << endl;
	cout << solution.addDigits(38) << endl;
	return 0;
}
