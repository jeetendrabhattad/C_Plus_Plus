#include <iostream>

int GetMaxSum(int a[], int size)
{
	int maxSum = 0;
	int sum = 0;

	for( int i = 0 ; i < size ; i++ )
	{
		sum +=a[i];
		if(maxSum < sum)
				maxSum = sum;
		else if( sum < 0)
				sum =0;
	}
	return maxSum;
}

int main()
{
	int a[]= {1,2,3,-2,-4,6,-2,7,-3};
	std::cout<<"Max sum:"<<GetMaxSum(a, 9)<<std::endl;
}
