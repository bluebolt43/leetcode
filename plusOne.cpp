#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res, tmp;

		bool overflow = true;

		for(int i=digits.size()-1;i>=0;i--){
			if(overflow == false){
				tmp.push_back(digits[i]);
			}else{
				if(digits[i]==9){
					overflow = true;
					tmp.push_back(0);
				}else{
					overflow = false;
					tmp.push_back(digits[i]+1);
				}
			}
			//cout << overflow <<" "<< tmp[i]<<endl;
		}
		
		if(overflow == true){
			res.push_back(1);
		}

		while(tmp.size()>0){
			res.push_back(tmp.back());
			tmp.pop_back();
		}
        return res;
    }
};

int main()
{
	Solution solution;
	vector<int> a;
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);

	vector<int> r = solution.plusOne(a);
	cout << r.size() << endl;
	for(int i=0;i<r.size();i++)
		cout << r[i];
	cout << endl;

	return 0;
}
