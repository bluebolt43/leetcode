#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
public:
    int lengthOfLongestSubstring(string s) {
		int counter = 0, longest_counter = 0;
		int i,j, pt;
		for(i=0, pt=0;i<s.length();i++){
			for(j=pt;j<i;j++){
				if(s[j] == s[i]){
					if(longest_counter < counter)
						longest_counter = counter;
					counter=i-j-1;
					pt=j+1;
					break;
				}
			}
			counter++;
		}
		if(longest_counter < counter)
			longest_counter = counter;
		return longest_counter;
    }
};

 
int main()
{
	string input = "qopubjguxhxdipfzwswybgfylqvjzhar";
	Solution solution;
	cout << solution.lengthOfLongestSubstring(input) << endl;
	return 0;
}
