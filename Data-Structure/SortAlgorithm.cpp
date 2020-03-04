#include"SortAlgorithm.h"


using namespace std;


//»ù´¡°æÃ°ÅÝÅÅÐò
void bubbleSort_1(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[j + 1] < arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\n";
	}
	cout << endl;
}

//ÓÅ»¯°æÃ°ÅÝÅÅÐò
void bubbleSort_2(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		int swap_num = 0;
		for (int j = 0; j < len; j++) {
			if (arr[j + 1] < arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap_num++;
			}
		}
		if (swap_num == 0) break;
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\n";
	}
	cout << endl;
}

//Ö±½Ó²åÈëÅÅÐò
void insertSort(int arr[], int len) {
	int guard = 0;
	int temp;
	for (int i = 1; i < len; i++) {
		temp = arr[i];
		if (arr[i - 1]>temp) {
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] > temp) {
					arr[j + 1] = arr[j];
					arr[j] = temp;
				}
				else {
					arr[j + 1] = temp;
					break;
				}
			}
		}

	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\n";
	}
	cout << endl;
}

//Ï£¶ûÅÅÐò
void shellSort(int arr[], int len) {
	for (int gap = len >> 1; gap > 0; gap >>= 1) {
		for (int i = gap; i < len; i++) {
			int temp = arr[i];
			int j = i;
			while (i - gap >= 0 && temp < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\n";
	}
	cout << endl;
}

//¹é²¢ÅÅÐò
void merge(int arr[], int L, int mid, int R) {
	int *temp = new int[R - L + 1];
	int p1 = L, p2 = mid + 1, i = 0;
	while (p1 <= mid&&p2 <= R) {
		temp[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
	}
	while (p1 <= mid) {
		temp[i] = arr[p1];
		i++;
		p1++;
	}
	while (p2 <= R) {
		temp[i] = arr[p2];
		i++;
		p2++;
	}
	for (int i = 0; i<R - L + 1; i++) {
		arr[L + i] = temp[i];
	}
}
void sort(int arr[], int L, int R) {
	if (L < R) {
		int mid = (L + R) / 2;
		sort(arr, L, mid);
		sort(arr, mid + 1, R);
		merge(arr, L, mid, R);
	}
}
void mergeSort(int arr[], int len) {
	sort(arr, 0, (len - 1));
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\n";
	}
}

//¿ìËÙÅÅÐò
int division(int arr[], int left, int right) {
	int guard = arr[left];
	int low = left, high = right;
	int mid;
	while (left < right) {
		while (arr[right] >= guard && left<right) {
			right--;
		}
		arr[left] = arr[right];
		while (arr[left] <= guard && left<right) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = guard;
	return left;
}
void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int base = division(arr, left, right);
		quickSort(arr, left, base - 1);
		quickSort(arr, base + 1, right);
	}
}

//¿ìËÙÅÅÐò·ÇµÝ¹é°æ
void quickSortNoRec(int arr[], int left, int right) {
	stack<int> s;
	int low = left, high = right;
	int mid;
	s.push(left);
	s.push(right);
	while (!s.empty()) {
		high = s.top();
		s.pop();
		low = s.top();
		s.pop();
		if (low < high) {
			mid = division(arr, low, high);
			s.push(low);
			s.push(mid - 1);
			s.push(mid + 1);
			s.push(high);
		}
	}

}
//¼òµ¥Ñ¡ÔñÅÅÐò
void selectSort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		int k = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[k]) {
				k = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

//¶ÑÅÅÐò
void initHeap(int arr[], int len, int index) {
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max_index = index;
	if (arr[lchild] > arr[max_index] && lchild<len) max_index = lchild;
	if (arr[rchild] > arr[max_index] && rchild<len) max_index = rchild;
	if (max_index != index) {
		int temp = arr[index];
		arr[index] = arr[max_index];
		arr[max_index] = temp;
		initHeap(arr, len, max_index);
	}
}
void heapSort(int arr[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		initHeap(arr, len, i);
	}
	for (int i = len - 1; i >= 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		initHeap(arr, i, 0);
	}

}

