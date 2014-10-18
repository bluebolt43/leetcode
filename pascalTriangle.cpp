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

    vector<int> getRow(int rowIndex) {
		int i;
		long long tmp;
		vector<int> result;
		if(rowIndex<0)
			return result;

		result.push_back(1);
		if(rowIndex==0)
			return result;
		result.push_back(rowIndex);

		//cm:n+1=cm:n (m-n)/(n+1)  when m-n-1 >0
		for(i=1;i<result[1];i++){
			tmp = result[i];
			tmp = tmp*(result[1]-i)/(i+1);
			//cout <<result[i] <<"* " << (result[1]-i)<< "/" <<(i+1) << "="<< tmp <<endl;
			result.push_back((int)tmp);
		}

		return result;
    }
};

int main()
{
	Solution solution;
	vector<vector<int> > tmp;
    int i,j;
	tmp = solution.generate(10);
	for(i=0;i<tmp.size();i++){
		for(j=0;j<tmp[i].size();j++)
			cout << tmp[i][j] << " ";
		cout <<endl;
	}
	
	vector<int> buf;
	buf= solution.getRow(30);
	for(i=0;i<buf.size();i++){
		cout << buf[i] << " ";
	}
	cout <<endl;

	return 0;
}
