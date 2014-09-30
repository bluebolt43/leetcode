#include <iostream>
using namespace std;

/*
0 0
1 1(1,0)=1
2 11(2,0)=1 2(1,1)=1 2
3 111(3,0)=1 21(2,1)=2  3
4 1111(4,0)=1 211(3,1)=3 22(2,2)=1  5=3+2
5 11111(5,0)=1 2111(4,1)=4 221(3,2)=3 8=3+5
6 111111(6,0)=1 21111(5,1)=5 2211(4,2)=6 222(3,3)=1 13=8+5
7 1111111(7,0)=1 21111(6,1)=6 22111(5,2)=10 2221(4,3)=4 21=13+8
*/
class Solution {
public:
#if 0
    int climbStairs(int n) {
	int tmp[n+1];
	int i;
	tmp[0]=0;
	tmp[1]=1;
	tmp[2]=2;
	for(i=3;i<n+1;i++)
		tmp[i]=tmp[i-1]+tmp[i-2];
	return tmp[n];
    }
#else
    int climbStairs(int n) {
	int i, result=2, prev=1, tmp;
	if(n<=2) return n;
	for(i=3;i<=n;i++){
		tmp=result;
		result+=prev;
		prev=tmp;
	}
	return result;
    }
#endif
};

int main()
{
	int i=0;
	Solution solution;
	for(i=1;i<10;i++)
		cout << solution.climbStairs(i) <<endl;
	cout << solution.climbStairs(44) <<endl;
	return 0;
}

