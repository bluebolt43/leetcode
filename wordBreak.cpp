#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        vector<bool> dp(len + 1,false);
        dp[len] = true;

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                string str = s.substr(i,j - i + 1);
                if (dict.find(str) != dict.end() && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
#if 0
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		int i,j;
		unordered_set<string>::const_iterator got;
		char* buf = new char(s.length()+1);
		
		vector <char*> cutable_table;
		char *current_pt;
		bool success_last_time = true;

		for(j=0;i<s.length()+1;j++){
			buf[j]=0;
		}

		cutable_table.push_back(&buf[i]);
		for(i=0; i< s.length(); i++){
			//copy one char to buf
			buf[i] = s[i];
			//first time
			if(success_last_time == true)
				current_pt = &buf[i];			

			cout << buf << endl;

			cout << current_pt << endl;

			got = dict.find(current_pt);
			if(got != dict.end()){//find string
				cout << current_pt << " found in myset\n";
				success_last_time = true;
				//update table pts
				cutable_table.push_back(&buf[i]);
			}else{//not find
				cout << current_pt << " not found in myset\n";
				success_last_time = false;
				if(i==s.length()-1){//Untill end but not success
					while(cutable_table.size()>0){
						current_pt = cutable_table.back();
						got = dict.find(current_pt);
						if(got == dict.end()){
							cout << current_pt << " not found in myset\n";
							if(cutable_table.size()==0)
								return false;
							cutable_table.pop_back();
						}else{
							cout << current_pt <<" found in myset\n";
							break;
						}
					}
				}
			}
		}
        return true;
    }
};
#endif
int main()
{
	//unordered_set<string> myset = { "cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb" };
	//string s = "bccdbacdbdacddabbaaaadababadad";
	//unordered_set<string> myset = {"aaa", "aaaa"};
	//string s = "aaaaaaa";
	unordered_set<string> myset = {"ab", "bc", "abc"};
	string s = "abcd";

	Solution solution;
	cout << solution.wordBreak(s, myset) << endl;
	return 0;
}
