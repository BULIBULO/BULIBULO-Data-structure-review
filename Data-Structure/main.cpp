
#include"SearchAlgorithm.h"
#include"SortAlgorithm.h"

using namespace std;


int main() {
	int arr[] = { 99, 18, 35, 54, 58, 43, 21, 89, 84, 78 };
	int len = sizeof(arr) / sizeof(int);
	int target = arr[0];
	heapSort(arr, len);
	cout << "������:";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}

	int result = binarySearch1(arr, target,0,len-1);
	cout << "����ԭ���е�һ��Ԫ��λ�õĽ����"<<result << endl;
	system("pause");
	return 0;
}