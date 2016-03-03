#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0)
            return false;
        else
            return true;
    }
};

int main()
{

	Solution solution;
	cout << solution.canWinNim(4) << endl;
	cout << solution.canWinNim(5) << endl;
	return 0;
}
