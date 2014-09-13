#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
		int tmp =x;

		if(tmp<0)
			tmp*=-1;

        while(tmp>0){
			result = result*10 + tmp%10;
			tmp/=10;
		}

		if(x<0)
			return -1*result;
		return result;
    }
};

int main()
{
	Solution solution;
	cout << solution.reverse(-193) <<endl;
	return 0;
}
