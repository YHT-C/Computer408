#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void MyPrint(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
	printf("\n");
}
void swap(int* x, int* y) {
	int temp = x;
	x = y;
	y = temp;
}

//直接插入排序
void InsertSort(int A[], int n) {
	int i;
	for (i = 1; i < n; i++) {
		if (A[i] < A[i - 1]) {
			int temp = A[i], j;
			for (j = i - 1; j >= 0 && A[j] > temp; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = temp;
		}
		MyPrint(A, n);
		printf("\n");
	}
}

//带哨兵版折半插入排序
void BinaryInsertSort(int A[], int n) {
	int i, j, low, high, mid;
	for (i = 2; i <= n-1; i++) {
		A[0] = A[i];
		low = 1; 
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (A[mid] > A[0]) {
				high = mid - 1;//折半左半区
			}else {
				low = mid + 1;//折半右半边区
			}
		}
		for (j = i - 1; j >= high + 1; j--) {
			A[j + 1] = A[j];
		}
		A[high + 1] = A[0];
		MyPrint(A, n);
	}
}

//希尔排序
void ShellSort(int A[], int n) {
	int d, i, j;
	for (d = n / 2; d >= 1; d = d / 2) {
		for (i = d + 1; i <= n; i++) {
			if (A[i] < A[i - d]) {
				A[0] = A[i];
				for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
					A[j + d] = A[j];
				}
				A[j + d] = A[0];
			}
		}
		printf("增量=%d\n", d);
		MyPrint(A, n);
	}
}

//冒泡排序
void BubbleSort(int A[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		bool flag=true;
		for (j = 0; j < n - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				flag = false;
			}
		}
		if (flag) break;
		MyPrint(A, n-1);
	}
}

//快速排序
int quick_one_pass(int A[], int low, int high) {
	int i = low, j = high;
	int pivotkey = A[i];
	while (i < j) {
		while (pivotkey<A[j] && j>i) {
			j--;
		}
		if (j > i) {
			A[i] = A[j];
			i++;
		}
		while (A[i]<pivotkey&&j>i) {
			i++;
		}
		if (j > i) {
			A[j] = A[i];
			j--;
		}
	}
	A[i] = pivotkey;
	return i;
}
void QuickSort(int A[], int n, int low, int high) {
	int k;
	if (low < high) {
		k = quick_one_pass(A, low, high);
		MyPrint(A, n);
		QuickSort(A, n, low, k - 1);
		QuickSort(A, n, k + 1, high);

	}
}

//简单选择排序
void SimpleSelectSort(int A[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		if (min != i) {
			//交换元素
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
		MyPrint(A, n);
	}
}

/*//基于初始堆的堆排序
void BuildMinHeap(int A[], int len) {

}
void HeapSort(int A[], int len) {
	BuildMinHeap(A, len);//建立初始小根堆
	MyPrint(A, len);
	for (int i = len; i > 1; i--) {
		swap(A[i], A[1]);
		HeadAdjust(A, 1, i - 1);//堆调整
		MyPrint(A, len);
	}

}*/

void Merge(int A[], int low, int mid, int high) {
	//二路归并排序
	int i, j, k;
	//辅助数组B
	int *B = (int *)malloc(8 * sizeof(int));
	//将A中所有元素复制到B中
	for (k = low; k <= high; k++) {
		B[k] = A[k];
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (B[i] <= B[j]) {//元素相等时，优先使用脚标较小的元素
			A[k] = B[i++];//较小值复制到A中
		}
		else {
			A[k] = B[j++];
		}
	}
	while (i <= mid) A[k++] = B[i++];
	while (j <= high) A[k++] = B[j++];
}
//归并排序：把两个或者多个已经有序的序列合并成一个
void MergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);//对左半部分进行归并排序
		MergeSort(A, mid + 1, high);//对右半部分归并排序
		Merge(A, low, mid, high);
	}
}

int main() {
	int begintime,endtime;
	begintime = clock();

	int arr[9] = { 22,38,22,45,23,67,31,15,41 };
	int arr1[10] = { -999,22,38,22,45,23,67,31,15,41 };
	//MergeSort(arr, 0, 8);
	//InsertSort(arr, 9);
	//BinaryInsertSort(arr1, 10);
	//MyPrint(arr1, 10);
	//ShellSort(arr, 8);
	//BubbleSort(arr, 9);
	//QuickSort(arr, 9, 0, 8);
	SimpleSelectSort(arr, 9);

	endtime = clock();
	printf("Running Time：%dms\n", endtime - begintime);
	return 0;
}