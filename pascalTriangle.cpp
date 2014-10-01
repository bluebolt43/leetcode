#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
1
11
121
1331
14641
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		int i,j;
		if(numRows==0)
			return result;

		result.push_back(vector<int>());
		result[0].push_back(1);

		for(i=1;i<numRows;i++){
			result.push_back(vector<int>());
			
			result[i].push_back(result[i-1][0]);
			for(j=1;j<i;j++){
				result[i].push_back(result[i-1][j-1]+result[i-1][j]);
			}
			result[i].push_back(result[i-1][i-1]);
		}
		return result;
    }
};

int main()
{
	Solution solution;
	vector<vector<int> > tmp;
    int i,j;
	tmp = solution.generate(6);
	for(i=0;i<tmp.size();i++){
		for(j=0;j<tmp[i].size();j++)
			cout << tmp[i][j] << " ";
		cout <<endl;
	}
	return 0;
}
