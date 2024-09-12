#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MyPrint(int A[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
	printf("\n");
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
	BinaryInsertSort(arr1, 10);
	MyPrint(arr1, 10);

	endtime = clock();
	printf("Running Time��%dms\n", endtime - begintime);
	return 0;
}