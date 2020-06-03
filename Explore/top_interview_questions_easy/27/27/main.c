/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//[6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3]
//[1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1]
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    unsigned long long num = 0;
	int carry_cnt = 0;
    int newSize = 0;
    int * result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    
	//test
	printf("%d\n", &digits[3]);
	
	for (int i = 0; i < digitsSize; i++)
		num += digits[i] * pow(10, digitsSize - 1 - i);

	for (int i = 0; i < digitsSize; i++) 
		if (digits[i] == 9)
			carry_cnt++;
	
	if (carry_cnt == digitsSize) {
		//need to carry
		* returnSize = digitsSize + 1;
    	newSize = digitsSize + 1;
	}
	else {
		* returnSize = digitsSize;
    	newSize = digitsSize;
	}

	num++;
	for (int i = 0; i < newSize; i++) {
		result[i] = (int)(num / pow(10, newSize - 1 - i));
        num -= (unsigned long long)(result[i] * pow(10, newSize - 1 - i));
    }
	
	return result;
}

int main(int argc, const char * argv[])
{
	int digitsSize = 19;
	//int (* digits)[19]; // = {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3};
	int * digits = (int *)malloc(sizeof(int) * (digitsSize + 1));
	
	
	for (int i = 0; i < digitsSize; i++) {
		digits[i] = i % 10;
	}
	
	int* returnSize = &digitsSize;
//	* returnSize = digitsSize;
	for (int i = 0; i < digitsSize; i++)
		printf("%d ", &digits[i]);
	
	int * result = (int *)malloc(sizeof(int) * (digitsSize + 1));
	result = plusOne(* digits, digitsSize, returnSize);
	for (int i = 0; i < * returnSize; i++)
		printf("%d ", result[i]);
	return 0;
	
}
