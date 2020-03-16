
#include"SearchAlgorithm.h"
#include"SortAlgorithm.h"

using namespace std;


int main() {
	int arr[] = { 99, 18, 35, 54, 58, 43, 21, 89, 84, 78 };
	int len = sizeof(arr) / sizeof(int);
	int target = arr[0];
	heapSort(arr, len);
	cout << "排序结果:";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}

	int result = binarySearch1(arr, target,0,len-1);
	cout << "搜索原数列第一个元素位置的结果："<<result << endl;
	system("pause");
	return 0;
}