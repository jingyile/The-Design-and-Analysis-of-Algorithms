#include <stdio.h>
#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
       printf("1111\n"); 
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
         printf("2222\n");
        length *= 2;
    }
} 

int main()
{
    int N, i;
    ElementType A[MAXN];
    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);
    return 0;
}

/* Your function will be put here */
void merge_pass( ElementType list[], ElementType sorted[], int N, int length ){  //将List到sorted
    for (int i=0; i<N; i=i+2*length) {
        int ptr1,ptr2,ptr3;
        ptr1=i;
        ptr2=i+length;
        ptr3=ptr1;
        while (ptr1<i+length&&ptr2<i+length+length&&ptr1<N&&ptr2<N) {  //情况1 
            if(list[ptr1]<list[ptr2]){     
                sorted[ptr3]=list[ptr1];
                ptr3++;
                ptr1++;
            }
            else{
                sorted[ptr3]=list[ptr2];
                ptr3++;
                ptr2++;
            }
        }
        if(ptr1==i+length){     //2
            while (ptr2<i+length+length) {
                sorted[ptr3]=list[ptr2];
                ptr3++;
                ptr2++;
            }
        }
        if(ptr2==i+length+length){   //3
            while (ptr1<i+length) {
                sorted[ptr3]=list[ptr1];
                ptr3++;
                ptr1++;
            }
        }
        if(ptr2>=N){             //11
            while (ptr1<i+length) {
                sorted[ptr3]=list[ptr1];
                ptr3++;
                ptr1++;
            }
        } 
    }
}

 
