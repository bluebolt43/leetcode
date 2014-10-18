#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
		int i, j;
		bool carrier = false;
		int sum = 0;

		string res;

		for(i = a.size()-1, j = b.size()-1; i>=0 | j>=0; i--, j--){
			sum=0;
			if(i>=0)
				sum = (a[i] - '0');
			if(j>=0)
				sum += (b[j] - '0');
			sum += carrier;
			carrier = sum>>1;			
			sum = sum&1;

			res = (char)('0'+sum) + res;
		}

		if(carrier)
			res=(char)('0'+carrier) + res;

		return res;
#if 0
		//Dec add
		int i, j;
		int overflow = 0;
		int sum = 0;
		string res;
		for(i = a.size()-1, j = b.size()-1; i>=0 | j>=0; i--, j--){
			sum=0;
			if(i>=0)
				sum = (a[i] - '0');
			if(j>=0)
				sum += (b[j] - '0');
			sum += carrier;
			carrier = sum/10;			
			sum = sum%10;

			res = (char)('0'+sum) + res;
			//cout <<a[i]<<"+"<<b[j]<<"="<< carrier<<sum <<" "<< res<<endl;
		}

		if(carrier)
			res=(char)('0'+carrier) + res;

		return res;
#endif
    }
};

int main()
{
	Solution solution;
	string a="111111";
	string b="1";

	cout << solution.addBinary(a,b) <<endl;

	return 0;
}
