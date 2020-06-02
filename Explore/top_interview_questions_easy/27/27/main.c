int* plusOne(int* digits, int digitsSize, int* returnSize){
	int num = 0;
	int carry_cnt = 0;
	for (int i = 0; i < digitsSize; i++)
		num += digits[i] * pow(10, digitsSize - 1 - i);

	for (int i = 0; i < digitsSize; i++) 
		if (digits[i] == 9)
			carry_cnt++;
	
	if (carry_cnt == digitsSize) {
		//need to carry
		* returnSize = digitsSize + 1;
    	int * result = (int *)malloc(sizeof(int) * (digitsSize + 1));
	}
	else {
		* returnSize = digitsSize;
    	int * result = (int *)malloc(sizeof(int) * digitsSize);
	}

	num++;
	for (int i = 0; i < digitsSize; i++) {
		result[i] = (int)(num / pow(10, digitsSize - 1 - i));
        num -= result[i] * pow(10, digitsSize - 1 - i);
    }
	
	return result;
}