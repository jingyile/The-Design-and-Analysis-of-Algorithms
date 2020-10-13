#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

typedef int KeyType;

typedef struct {
    KeyType key;
}SElemType;

typedef struct {
    SElemType *elem;
    int length;
}SSTable;

int Search_Bin(SSTable ST, KeyType key);

int main () {
    SSTable T;

    scanf("%d", &T.length);
    T.elem = (SElemType *) malloc ((T.length + 1) * sizeof(SElemType));

    for(int i = 1; i <= T.length; ++ i)
        scanf("%d", &T.elem[i].key);

    KeyType key;
    scanf("%d", &key);

    int pos = Search_Bin(T, key);
    if(pos == NOT_FOUND) puts("NOT FOUND");
    else printf("%d\n", pos);
    return 0;
}
/* 你的代码将被嵌在这里 */
int  Search_Bin(SSTable T, KeyType k)
{
    int start=0,end=T.length-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(T.elem[mid].key==k)
        {
            return mid;
        }
        else if(T.elem[mid].key>k)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}

