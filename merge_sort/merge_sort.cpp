#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
	void merge_sort(vector<int>&nums, int left, int right)

	{
		//一定注意递归结束条件
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
	////	if (low >= high) { return; } // 终止递归的条件，子序列长度为1
	////	int mid = low + (high - low) / 2;  // 取得序列中间的元素
	////	MergeSort(arr, low, mid);  // 对左半边递归
	////	MergeSort(arr, mid + 1, high);  // 对右半边递归
	////	Merge(arr, low, mid, high);  // 合并
	////}

	void Merge(vector<int>& arr, int low, int mid, int high){
		//low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
		int i = low, j = mid + 1, k = 0;  //mid+1为第2有序区第1个元素，j指向第1个元素
		int *temp = new int[high - low + 1]; //temp数组暂存合并的有序序列
		while (i <= mid&&j <= high){
			if (arr[i] <= arr[j]) //较小的先存入temp中
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
			temp[k++] = arr[i++];
		while (j <= high)//同上
			temp[k++] = arr[j++];
		for (i = low, k = 0; i <= high; i++, k++)//将排好序的存回arr中low到high这区间
			arr[i] = temp[k];
		delete[]temp;//释放内存，由于指向的是数组，必须用delete []
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