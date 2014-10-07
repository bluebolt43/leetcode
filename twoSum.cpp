#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i,j;
        vector<int> result;
        unordered_set <int> number_hash;
        int max=0, min=0;
        for(i=0;i<numbers.size();i++){
            if (number_hash.find(numbers[i]) == number_hash.end()){
                number_hash.insert(numbers[i]);
                if(numbers[i]>max)
					max=numbers[i];
                if(numbers[i]<min)
					min=numbers[i];
            }
        }
        int index1,index2;
        for(i=max;i>=min;i--){
			cout << i <<endl;
            if (number_hash.find(i) != number_hash.end()){
				cout <<"find "<< i <<endl;
                if (number_hash.find(target-i) != number_hash.end()){
					cout <<"find "<< target - i <<endl;
                    for(index1=0;index1<numbers.size();index1++){
                        if(numbers[index1]==i){
                            for(index2=index1+1;index2<numbers.size();index2++){
                                if(numbers[index2]==target-i){
									cout <<"find "<< index1 <<" "<< index2 <<endl;
                                    result.push_back(index1+1);
                                    result.push_back(index2+1);
                                    return result;
                                }
                            }
                        }
                    }
                }
            }
        }
        result.push_back(0);
        return result;
    }
};



int main()
{
	Solution solution;
	vector<int> a;
	//a.push_back(0);	a.push_back(2);	a.push_back(4);
	//vector<int> r = solution.twoSum(a, 6);
	a.push_back(-3);	a.push_back(4);	a.push_back(3);	a.push_back(90);
	vector<int> r = solution.twoSum(a, 0);
	for(int i=0;i<r.size();i++)
		cout << r[i] << endl;
	return 0;
}
