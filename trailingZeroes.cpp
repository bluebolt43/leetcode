#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
		int i, result;
		for(result=0; n>=5;){
			n = n/5;
			result += n;
		}
        return result;
    }
};

int main()
{

	Solution solution;
	cout << solution.trailingZeroes(25) << endl;
	return 0;
}
