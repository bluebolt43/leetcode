#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool canJump(int A[], int n) {
        vector<bool> dp(n,false);
        dp[0]=true;
        for (int i = 1; i < n; i++) {
			//cout << i << " "<< A[i-1] <<endl;
            for (int j = 0; j < A[i-1]; j++) {
                if (dp[i + j - 1]){
					//cout << " true "<< i + j <<endl;
                    dp[i + j] = true;
                    if(i + A[i-1] > n)
						dp[n-1] = true;
					else
						dp[i + A[i-1] - 1] = true;
                    break;
                }
            }
			//dp[i+A[i-1]] = true;
		}
        /*for (int i = 0; i < n; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;*/
        return dp[n-1];
    }
};

int main()
{
	int a[] = {2,3,1,1,4};
	int b[] = {3,2,1,0,4};
	int c[] = {2,0,0};
	Solution solution;
	cout << solution.canJump(a, sizeof(a)/sizeof(a[0])) << endl;
	cout << solution.canJump(b, sizeof(b)/sizeof(b[0])) << endl;
	cout << solution.canJump(c, sizeof(c)/sizeof(c[0])) << endl;
	return 0;
}
