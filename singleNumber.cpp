#include <iostream>

using namespace std;

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result=0;
        int i=0;
        for(i=0;i<n;i++)
            result ^= A[i];
        return result;
    }
};

int main()
{
	int A[]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,-1,-1};
	Solution solution;
	int result = solution.singleNumber(A,ARRAY_SIZE(A));
	cout << result;
	return 0;
}
