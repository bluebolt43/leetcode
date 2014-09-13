#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i;
		int result=0;
		int tmp;

		for(i=1;i<prices.size();i++){
			tmp=prices[i]-prices[i-1];
			if(tmp>0)
				result+=tmp;
		}
		return result;
    }
};

int main()
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(5);
	prices.push_back(3);
	prices.push_back(10);
	prices.push_back(11);
	prices.push_back(10);
	Solution solution;
	cout << solution.maxProfit(prices) <<endl;
	return 0;
}
