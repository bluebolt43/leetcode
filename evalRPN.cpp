#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
	int back = 0;
	int result = 0;
	int index = 0;
	vector<string> tmp;
	while (index < tokens.size()){
		if(tokens.at(index) == "+"){
			ostringstream ss;
			istringstream(tmp.back()) >> back;
			tmp.pop_back();
			istringstream(tmp.back()) >> result;
			tmp.pop_back();
			result += back;
			ss << result;
			tmp.push_back(ss.str());
		}else if(tokens.at(index) == "-"){
			ostringstream ss;
			istringstream(tmp.back()) >> back;
			tmp.pop_back();
			istringstream(tmp.back()) >> result;
			tmp.pop_back();
			result -= back;
			ss << result;
			tmp.push_back(ss.str());
		}else if(tokens.at(index) == "*"){
			ostringstream ss;
			istringstream(tmp.back()) >> back;
			tmp.pop_back();
			istringstream(tmp.back()) >> result;
			tmp.pop_back();
			result *= back;
			ss << result;
			tmp.push_back(ss.str());
		}else if(tokens.at(index) == "/"){
			ostringstream ss;
			istringstream(tmp.back()) >> back;
			tmp.pop_back();
			istringstream(tmp.back()) >> result;
			tmp.pop_back();
			result /= back;
			ss << result;
			tmp.push_back(ss.str());
		}else{
			tmp.push_back(tokens.at(index));
		}
		index++;
	}
	istringstream(tmp.back())>>result;
	tmp.pop_back();
	return result;
    }
};

 
int main()
{
	vector<string> tokens1;
	tokens1.push_back("2");
	tokens1.push_back("1");
	tokens1.push_back("+");
	tokens1.push_back("3");
	tokens1.push_back("*");//9

	vector<string> tokens2;
	tokens2.push_back("4");
	tokens2.push_back("13");
	tokens2.push_back("5");
	tokens2.push_back("/");
	tokens2.push_back("+");//6

	Solution solution;
	cout << solution.evalRPN(tokens1) << endl;
	cout << solution.evalRPN(tokens2) << endl;
	return 0;
}
