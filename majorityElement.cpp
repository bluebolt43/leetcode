#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &num) {
        //1. Use sort
        //2. O(n) solution
        int i, size;
        int count;
        int result;
        for(i=0, count=0, size = num.size(); i<size; i++){
			if(count==0){
				result = num[i];
				count++;
			}else if(num[i]==result){
				count++;
				if((count<<1) > size)
					return result;
			}else{
				count--;
				if(count==0){
					result = num[i];
					count++;
				}
			}
			//cout << num[i] <<" "<< result <<" "<< count<<endl;
		}
		return result;
    }
};

int main()
{
	vector<int> num;
	num.push_back(8);num.push_back(8);num.push_back(7);num.push_back(7);num.push_back(7);
	Solution solution;
	cout << solution.majorityElement(num) << endl;
	return 0;
}
