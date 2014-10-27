#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
		int state = 0;
		int i=0;
		bool is_sign=false;
		bool is_sci=false;

		while(*s == ' ')    //trim preceding spaces
			s++;
		string str(s);
		while(str.back() == ' ')    //trim ending spaces
			str.pop_back();

        for(i=0;str[i]!='\0';i++){
			switch(state){
			case 0://?[+-]
			case 5://E?[+-]
				if((str[i]=='+') || (str[i]=='-'))
					state+=1;
				else if(isdigit(str[i]))//[1-9]
					state+=2;//0=>2
				else if(str[i]=='.')//.[1-9]
					state+=3;//0=>3
				else
					return false;
				break;
			case 1://[.1-9]
			case 6:
				if(isdigit(str[i]))
					state+=1;//1=>2
				else if(str[i]=='.')
					state+=2;//1=>3
				else
					return false;
				break;
			case 2://[1-9]
			case 7:
				if(isdigit(str[i]))
					continue;
				else if(str[i]=='.')//[1-9].[1-9]
					state+=2;//
				else if((str[i]=='E') || (str[i]=='e'))
					state+=3;
				else
					return false;
				break;
			case 3://.[1-9]
				if(isdigit(str[i]))
					state+=1;//3=>4
				/*else if((str[i]=='E') || (str[i]=='e'))
					state+=2;//3=>5*/
				else
					return false;
				break;
			case 4://[1-9].[1-9]
				if(isdigit(str[i]))
					continue;
				else if((str[i]=='E') || (str[i]=='e'))
					state+=1;//4=>5
				else
					return false;
				break;			
			default:
				return false;
			}
		}
		if(state==4 || state==2 || state==7)
			return true;
		else
			return false;
    }
};


int main()
{
	Solution solution;
	cout << solution.isNumber("-10.") <<endl;
	cout << solution.isNumber(".e1.0") <<endl;
	cout << solution.isNumber("214.74e836.471") <<endl;
	cout << solution.isNumber("-e1") <<endl;
	return 0;
}

