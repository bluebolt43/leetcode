#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int i, j, k;
        vector< vector<int> > result;
		int index[3]= {0, 0, 0};
		int sum = -1;
		int zero = -1;

		if(num.size()<2)
			return result;
		sort(num.begin(), num.end());
		for(i=0;i<num.size();i++){
			if(num[i]>=0){
				zero=i;
				break;
			}
		}
		if(zero==-1){
			return result;
		}	

		for(i=0;i<num.size()-2;i++){
			if(i==0 || num[index[0]]!=num[i]){//First without duplication.
				//Check second & third
				for(j=i+1, k=num.size()-1;j<k;){
					//Reduce duplicate
					bool update=false;
					sum = num[i]+num[j]+num[k];
					if(index[1]==0 || index[2]==0 || num[index[1]]!=num[j] || num[index[2]]!=num[k]){
						update=true;
					}
					//cout<<num[i]<<" "<< num[j]<<" "<<num[k]<<endl<<sum<<endl;
					index[1]=j;
					index[2]=k;

					if(sum==0 && update){
						result.push_back(vector<int>());
						result.back().push_back(num[i]);
						result.back().push_back(num[j]);
						result.back().push_back(num[k]);
						j++;
						k--;
					}else if(sum>0){
						k--;
					}else{
						j++;
					}
				}
			}
			index[0]=i;
		}
        return result;
    }
};



int main()
{
	Solution solution;
	vector<int> a;
	//a.push_back(-1); a.push_back(0); a.push_back(1); a.push_back(2); a.push_back(-1); a.push_back(-4);
	//a.push_back(-2); a.push_back(0); a.push_back(1); a.push_back(1); a.push_back(2);
	//a.push_back(0);a.push_back(0);a.push_back(0);a.push_back(0);

	a.push_back(-4); a.push_back(-2); a.push_back(-2); a.push_back(-2); a.push_back(0); a.push_back(1);
	a.push_back(2); a.push_back(2); a.push_back(2); a.push_back(3); a.push_back(3); a.push_back(4);
	a.push_back(4); a.push_back(6); a.push_back(6);
	vector<vector<int> > r = solution.threeSum(a);
	for(int i=0;i<r.size();i++)
		cout << r[i][0] <<" "<< r[i][1] <<" "<< r[i][2] << endl;
	return 0;
}
