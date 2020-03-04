
#include"SearchAlgorithm.h"

using namespace std;

//�۰����

int Search(int arr[], int target, int low, int high)//�ݹ�ʵ��
{
	if (low > high) {
		return -1;
	}
	int mid = (low + high) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	if (arr[mid] > target) {
		return Search(arr, target, low, mid - 1);
	}
	if (arr[mid] < target) {
		return Search(arr, target, mid + 1, high);
	}
}
int binarySearch1(int arr[], int target, int low, int high) {
	return Search(arr, target, low, high);
}


int binarySearch2(int a[], int n, int target)//ѭ��ʵ��
{
	int low = 0, high = n, middle;
	while (low < high)
	{
		middle = (low + high) / 2;
		if (target == a[middle])
			return middle;
		else if (target > a[middle])
			low = middle + 1;
		else if (target < a[middle])
			high = middle;
	}
	return -1;
};
