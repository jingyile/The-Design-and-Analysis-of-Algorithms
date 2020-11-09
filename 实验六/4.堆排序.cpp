#include<iostream>
#include<algorithm>
#define maxn 1001   //heap's size

using namespace std;

struct Heap {
	int size;	// number of elements in array
	int *array;
	Heap() {	//init
		size = 0;
		array = new int[maxn];
	}
	Heap(int n) {	//init
		size = 0;
		array = new int[n];
	}
	~Heap() {	//free memory
		delete array;
	}
	bool empty() {
		if(size != 0) return false;
		return true;
	}
	void insert(int value) {
		array[++size] = value;
		int index = size;
		while(index > 1) {
			if(array[index] > array[index/2]) swap(array[index],array[index/2]);
			index /= 2;
		}
	}
	void del() 
	{
		if(empty()) return;
		swap(array[1],array[size--]);
		int index = 1;
		while(2*index <= size) 
		{
			int next = 2*index;
			if(next < size && array[next+1] > array[next]) next++;
			if(array[index] < array[next]) 
			{
				swap(array[index],array[next]);
				index = next;
			} else break;
		}
	}
	int max() {
		if(empty()) return -1;
		return array[1];
	}
};
void buildHeap(int array[],int size) {
	int i,tmp,index;
	for(i = size/2; i >= 1; i--) {
		tmp = array[i];
		index = 2*i;
		while(index <= size) {
			if(index < size && array[index+1] > array[index]) index++;
			if(array[index] < tmp) break;
			array[index/2]  = array[index];
			index *= 2;
		}
		array[index/2] = tmp;
	}
}
int main() {
	int n,i,j,k;
	cout << "input heap's size:";
	cin >> n;
	Heap H = Heap(n);
	int* array = new int[n];
	for(i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		array[i] = tmp;
		H.insert(tmp);
	}
	buildHeap(array,n);
	for(i = 1; i <= n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	while(!H.empty()) {
		cout << H.max() << endl;
		H.del();
	}
	return 0;
};

