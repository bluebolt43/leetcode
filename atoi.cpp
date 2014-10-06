#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
		int i;
		int result=0;
		int flag=1;
		bool starting_flag=false;
        for(i=0;*(str+i)!='\0';i++){
			if(*(str+i)=='-'){
				if(starting_flag==false){
					starting_flag=true;
					flag=-1;					
				}else{
					break;//double sign
				}
			}else if(*(str+i)=='+'){
				if(starting_flag==false){
					starting_flag=true;
				}else{
					break;//double sign
				}
			}else if(*(str+i)==' '){
				if(starting_flag==true){
					break;
				}
			}else if(*(str+i)<='9' && *(str+i)>='0'){
				starting_flag=true;

				//overflow check
				if(result > INT_MAX/10){
					if(flag==1)
						return INT_MAX;
					else
						return INT_MIN;
				}else if(result == INT_MAX/10){
					if(*(str+i)- '0' > INT_MAX%10 && flag==1){
						return INT_MAX;
					}else if(*(str+i)- '0' > -1*(INT_MIN%10) && flag==-1){
						return INT_MIN;
					}
				}					
				result = result*10 + *(str+i) - '0';
			}else
				break;
		}
		return flag * result;
    }
};

int main()
{
	int i=0;
	Solution solution;
	cout << solution.atoi("    - 10") <<endl;
	cout << solution.atoi("21474a836471") <<endl;
	cout << solution.atoi(" -11919730356x") <<endl;
	cout << INT_MIN%10 <<endl;
	return 0;
}

