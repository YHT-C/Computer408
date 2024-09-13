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

//ֱ�Ӳ�������
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

//���ڱ����۰��������
void BinaryInsertSort(int A[], int n) {
	int i, j, low, high, mid;
	for (i = 2; i <= n-1; i++) {
		A[0] = A[i];
		low = 1; 
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (A[mid] > A[0]) {
				high = mid - 1;//�۰������
			}else {
				low = mid + 1;//�۰��Ұ����
			}
		}
		for (j = i - 1; j >= high + 1; j--) {
			A[j + 1] = A[j];
		}
		A[high + 1] = A[0];
		MyPrint(A, n);
	}
}

//ϣ������
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
		printf("����=%d\n", d);
		MyPrint(A, n);
	}
}

//ð������
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

//��������
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

//��ѡ������
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
			//����Ԫ��
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
		MyPrint(A, n);
	}
}

/*//���ڳ�ʼ�ѵĶ�����
void BuildMinHeap(int A[], int len) {

}
void HeapSort(int A[], int len) {
	BuildMinHeap(A, len);//������ʼС����
	MyPrint(A, len);
	for (int i = len; i > 1; i--) {
		swap(A[i], A[1]);
		HeadAdjust(A, 1, i - 1);//�ѵ���
		MyPrint(A, len);
	}

}*/

void Merge(int A[], int low, int mid, int high) {
	//��·�鲢����
	int i, j, k;
	//��������B
	int *B = (int *)malloc(8 * sizeof(int));
	//��A������Ԫ�ظ��Ƶ�B��
	for (k = low; k <= high; k++) {
		B[k] = A[k];
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (B[i] <= B[j]) {//Ԫ�����ʱ������ʹ�ýű��С��Ԫ��
			A[k] = B[i++];//��Сֵ���Ƶ�A��
		}
		else {
			A[k] = B[j++];
		}
	}
	while (i <= mid) A[k++] = B[i++];
	while (j <= high) A[k++] = B[j++];
}
//�鲢���򣺰��������߶���Ѿ���������кϲ���һ��
void MergeSort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);//����벿�ֽ��й鲢����
		MergeSort(A, mid + 1, high);//���Ұ벿�ֹ鲢����
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
	printf("Running Time��%dms\n", endtime - begintime);
	return 0;
}