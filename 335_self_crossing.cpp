#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
		if(x.size()>=4){
			 /* ┌───┐
				│   │
				└───┼──>
			 */
			for(int i=x.size()-1;i>2;i--){
				if( (x[i]>=x[i-2]) && (x[i-1]<=x[i-3])){
					//cout <<x[i]<<" "<<x[i-2]<<"="<<(x[i]>=x[i-2])<<" "<<x[i-1]<<" "<<x[i-3]<<"="<<(x[i-1]<=x[i-3])<<endl;
					return true;
				}
			}
			 /* ┌───┐
				│   │
				│	^
				└───1
			 */
			for(int i=x.size()-1;i>3;i--){
				//cout<< x[i]<<x[i-2]<<x[i-4]<<endl;
				//cout<< x[i-1]<<x[i-3]<<endl;
				if((x[i]+x[i-4]>=x[i-2]) && (x[i-1]==x[i-3]))
					return true;
			}
			 /* ┌───┐	
				│   │	
				│	<──┐
				└──────1
			 */
			for(int i=x.size()-1;i>4;i--){
				//cout<< x[i]<<x[i-2]<<x[i-4]<<endl;
				//cout<< x[i-1]<<x[i-3]<<x[i-5]<<endl;
				if((x[i]+x[i-4]>=x[i-2] && x[i-2]>=x[i-4] && x[i-2]>=x[i]) && (x[i-1]+x[i-5]>=x[i-3] && x[i-3]>=x[i-5] && x[i-3]>=x[i-1]))
					return true;
			}
		}
		return false;
    }
};

int main()
{
	vector< vector<int> > x;
	x.push_back({2, 1, 1, 2});
	x.push_back({1, 2, 3, 4});
	x.push_back({1, 1, 1, 1});
	x.push_back({1, 1, 2, 2, 2, 1});
	x.push_back({2, 2, 3, 3, 2, 2});
	x.push_back({1, 1, 2, 2, 1, 1});
	x.push_back({3, 3, 3, 2, 1, 1});
	x.push_back({1,1,2,2,3,1,1});
	x.push_back({1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1});

	Solution solution;
	cout << solution.isSelfCrossing(x[4]) << endl;
	cout << solution.isSelfCrossing(x[5]) << endl;
	cout << solution.isSelfCrossing(x[6]) << endl;
	cout << solution.isSelfCrossing(x[7]) << endl;
	return 0;
}
