#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) 
{
    return strcmp(a, b);

}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b,a);

}
int count(const char *s)
{
    int n=0;
    int count[128]={0};
    if (s==NULL)
    {
        return -1;
    }
    while(*s != '\0')
    {
        if (!count[*s])
        {
            count[*s]++;
            n++;
        }
        s++;
    }
    return n;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int x=count(a)-count(b);
    return (x? x: lexicographic_sort(a, b));
    
}

int sort_by_length(const char* a, const char* b) 
{
    int len = strlen(a) - strlen(b);
    return (len ? len : lexicographic_sort(a, b));

}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        int j = i;
        char* p = arr[i];
        while(j > 0){
            if((*cmp_func)(arr[j-1],p) > 0 )
                arr[j] = arr[j-1];
            else
                break;
            j--;
        }
        arr[j] = p;
    }

}


