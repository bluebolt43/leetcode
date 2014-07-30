#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string tmp;
		vector <string> myvector;
		stringstream ss(s);
		while( ss >> tmp)
			myvector.push_back(tmp);
		s="";
		while (!myvector.empty()){
			s += myvector.back();
			myvector.pop_back();
			if(!myvector.empty())
				s += " ";
		}
    }
};

 
int main()
{
	string input = "This is a test\n";
	Solution solution;
	solution.reverseWords(input);
	cout << input;
	return 0;
}
