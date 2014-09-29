#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxSubArray(int A[], int n) {
#if 0
        //Space O(n) Time O(n)
        int *min, sum, result;
        int tmp[n];
        int i;

        result = sum = tmp[0] = A[0];
        min = tmp;
        for(i=1; i<n; i++){
            tmp[i] = tmp[i-1] + A[i]; //calculate total sum from head.

            if(*min < 0)
                sum = tmp[i] - *min; //calculate distance between current pointer and minimum pointer.
            else
                sum = tmp[i]; //if min > 0 the sum is current pointer value.

            if(result < sum)
                result = sum; //update result

            if(*min > tmp[i])
                min = tmp+i; //update minimum point
        }
        return result;
#else
        //Space O(1) Time O(n)
        int min, sum, result;
        int tmp;
        int i;

        result = sum = min = tmp = A[0];
        for(i=1; i<n; i++){
            tmp += A[i]; //calculate total sum from head.

            if(min < 0)
                sum = tmp - min; //calculate distance between current point and minimum point.
            else
                sum = tmp; //if min sum > 0 the sum is current point value.
            
            if(result < sum)
                result = sum; //update result

            if(min > tmp)
                min = tmp; //update minimum point
        }
        return result;
#endif
    }
};
int main()
{
    int A[] = {-10,1,-3,4,-1,2,1,-5,4};
    int B[] = {-1,1,1,1,1};
    int C[]={1,2};
    int D[]={-2, 1};
    int E[]={-2,-1};
    Solution solution;
    cout << solution.maxSubArray(A, sizeof(A)/sizeof(*A)) << endl;
    cout << solution.maxSubArray(B, sizeof(B)/sizeof(*B)) << endl;
    cout << solution.maxSubArray(C, sizeof(C)/sizeof(*C)) << endl;
    cout << solution.maxSubArray(D, sizeof(D)/sizeof(*D)) << endl;
    cout << solution.maxSubArray(E, sizeof(E)/sizeof(*E)) << endl;
    return 0;
}
