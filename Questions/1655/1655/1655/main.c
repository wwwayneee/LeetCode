//
//  main.c
//  1655
//
//  Created by 张宇轩 on 2020/6/3.
//  Copyright © 2020 张宇轩. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char* reverseLeftWords(char* s, int n);

int main(int argc, const char * argv[]) {
	char * s = "abcdefg";
	int n = 2;
//	printf("%c\n", *(s + 3));
	char * result = reverseLeftWords(s, n);
	puts(result);

	return 0;
}

char* reverseLeftWords(char* s, int n){
    char * result = s;
    int size = (int)strlen(s);
    //char * tmp = (char *)malloc(sizeof(char) * size);
    for (int i = 0; i < size - n; i++)
        result[i] = *(s + i + n);
    
    for (int i = size - n, j = 0; i < size; i++, j++)
        result[i] = s[j];
    
    return result;
}
