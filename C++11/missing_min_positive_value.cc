/*
Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N) (not counting the storage required for input arguments).

*/

#include <bits/stdc++.h>

using namespace std;
int solution(vector<int> &A) {
    size_t result = 1;
    
    sort(A.begin(), A.end());
    
    auto it = remove_if(A.begin(), A.end(), [](int x){ return x <= 0;});
    A.erase(it, A.end());
    if(A.size() > 0)
    {
        if(A[0] == 1)
        {    
            size_t i;
            for( i = 0 ; i < A.size() ;i++)
            {
                if(A[i] < 0)
                    continue;
                if(A[i]+1 == A[i+1] or A[i] == A[i+1] )
                    continue;
                break;
            }
            result = A[i] + 1;
        }
    }
        
    return result;
}
