#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i, j;
        int sum;
        int size=gas.size();

		for(i=0, j=0, sum=0;i<j+size;i++){
			if(i<size){
				sum= sum + gas[i]- cost[i];
			}else{
				sum = sum + gas[i-size] - cost[i-size];
			}
			if(sum<0){
				if(i>=size)
					break;
				j=i+1;
				sum=0;
			}
		}
		if(sum>=0)
			return j;
		else
			return -1;
    }
};

int main()
{
	int i=0;
	vector<int>gas;
	vector<int>cost;
#if 0
	for(i=0;i<10000;i++){
		if(i<=10000-3897)
			gas.push_back(3897+i);
		else
			gas.push_back(3897+i-10000);			
	}
	//cout << gas.back() <<endl;
	for(i=0;i<10000;i++){
		if(i<=10000-3311)
			cost.push_back(3311+i);
		else
			cost.push_back(3311+i-10000);
	}
#endif
	//cout << cost.back() <<endl;
#if 0
	gas.push_back(4);	
	cost.push_back(5);
#endif
#if 0
	gas.push_back(5);	
	cost.push_back(4);
#endif
#if 0
	gas.push_back(1);
	cost.push_back(2);
	gas.push_back(2);
	cost.push_back(1);
#endif
#if 1
	gas.push_back(2);
	cost.push_back(3);
	gas.push_back(4);
	cost.push_back(4);
#endif
	Solution solution;
	cout << solution.canCompleteCircuit(gas,cost) <<endl;
	return 0;
}

