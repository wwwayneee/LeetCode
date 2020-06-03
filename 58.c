char* reverseLeftWords(char* s, int n){
    char * result = s;
    int size = strlen(s);
    //char * tmp = (char *)malloc(sizeof(char) * size);
    for (int i = 0; i < size - n; i++)
        result[i] = s[i + n];
    
    for (int i = size - n, j = 0; i < size; i++, j++)
        result[i] = s[j];
    
    return result;
}