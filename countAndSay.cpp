#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		int i,j,k;
		bool counting=false;
		char counting_char;

		string result;
		string tmp;

		if(n==0)
			return result;

		//initial string
		result.push_back('1');
		for(k=n-1; k>0; k--){
			string buf;
			i=0;
			while(result[i]!=0){
				if(counting==false){
					counting_char=result[i];
					j=0;
					counting=true;
				}
				j++;
				i++;
				if(result[i]!=counting_char){
					buf.append(to_string(j));
					buf.push_back(counting_char);
					counting=false;
				}
			}
			result.assign(buf);
		}
		return result;
	}
};

int main()
{
	Solution solution;

	for(int i=1;i<10;i++)
		cout << solution.countAndSay(i) << endl;
	return 0;
}
