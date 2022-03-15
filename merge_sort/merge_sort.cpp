#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
	void merge_sort(vector<int>&nums, int left, int right)

	{
		//һ��ע��ݹ��������
		if (left >= right) return;
		int middle = left + (right - left) / 2;
		merge_sort(nums, left, middle);
		merge_sort(nums, middle + 1, right);
		merge(nums, left, middle, right);
	}

	void merge(vector<int>&nums, int left, int middle, int right)
	{
		int k = 0;
		int *temp = new int[right - left+1];
		int i = left, j = middle + 1;
		while (i<=middle&&j<=right)
		{
			if (nums[i] <= nums[j])
			{
				temp[k] = nums[i];
				k++; i++;
			}

			else
			{
				temp[k] = nums[j];
				j++; k++;
			}
		}
		while (i <= middle)
			temp[k++] = nums[i++];
		while (j <= right)
			temp[k++] = nums[j++];
		for (i = left, k = 0; i <= right; i++, k++)
			nums[i] = temp[k];
		delete[]temp;

	}
	



	////void MergeSort(vector<int>& arr, int low, int high) {
	////	if (low >= high) { return; } // ��ֹ�ݹ�������������г���Ϊ1
	////	int mid = low + (high - low) / 2;  // ȡ�������м��Ԫ��
	////	MergeSort(arr, low, mid);  // �����ߵݹ�
	////	MergeSort(arr, mid + 1, high);  // ���Ұ�ߵݹ�
	////	Merge(arr, low, mid, high);  // �ϲ�
	////}

	void Merge(vector<int>& arr, int low, int mid, int high){
		//lowΪ��1�������ĵ�1��Ԫ�أ�iָ���1��Ԫ��, midΪ��1�����������1��Ԫ��
		int i = low, j = mid + 1, k = 0;  //mid+1Ϊ��2��������1��Ԫ�أ�jָ���1��Ԫ��
		int *temp = new int[high - low + 1]; //temp�����ݴ�ϲ�����������
		while (i <= mid&&j <= high){
			if (arr[i] <= arr[j]) //��С���ȴ���temp��
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (i <= mid)//���Ƚ���֮�󣬵�һ������������ʣ�࣬��ֱ�Ӹ��Ƶ�t������
			temp[k++] = arr[i++];
		while (j <= high)//ͬ��
			temp[k++] = arr[j++];
		for (i = low, k = 0; i <= high; i++, k++)//���ź���Ĵ��arr��low��high������
			arr[i] = temp[k];
		delete[]temp;//�ͷ��ڴ棬����ָ��������飬������delete []
	}




void print(vector<int>& nums) {
		for (auto i : nums) {
			cout << i << " ";
		}
		cout << endl;
	}


};


int main(){
	vector<int> nums = { 100999, 101, 45, 213, 456, 78, 90, 432, 564, 88,10101 };
	Solution s;
	s.merge_sort(nums, 0, 10);
	s.print(nums);

	system("pause");
	return 0;

}