#include<stdio.h>

int a[7]= {9,12,5,12,20,30,8};
int flag=3;
//flag作为数组的中间值的数组下标(low+high)/2;
//若是排序一趟之后i==j&&i==flag则找到中位数

int quickSortMidSearch(int array[],int low,int high) {
	if (low < high) {
		int i = low;
		int j = high;
		int temp = array[low];
		while (i < j) {
			while(i < j && array[j] >= temp) {
				j--;
			}
			if(i < j) {
				array[i++] = array[j];
			}
			while(i < j && array[i] < temp) {
				i++;
			}
			if(i < j) {
				array[j--] = array[i];
			}
		}
		array[i] = temp;
		if(i==flag)
			printf("%d",array[i]);;
		if(i>flag)
			quickSortMidSearch(array, low, i - 1);
		if(i<flag)
			quickSortMidSearch(array, i + 1, high);
	}
}

int main() {
	quickSortMidSearch(a,0,6);
}
