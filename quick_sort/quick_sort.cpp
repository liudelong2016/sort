#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
void quickSort(vector<int>&nums, int left,int right)

	{
	    if (left >= right)
		   return;
		int temp=nums[left];
		int i = left;
		int j = right;
		
		while (i < j)
		{
			while (i<j&&nums[j]>=temp)
				j--;
			while (i < j&&nums[i] <=temp)
				i++;
			if(i<j)
				swap(nums[i], nums[j]);

		}
		/*nums[left] = nums[i];
		nums[i] = temp;*/
		swap(nums[left], nums[i]);
		quickSort(nums, left, i - 1);
		quickSort(nums, i + 1, right);

		
	}
	
	//�������򣨴�С����
	/* 
	void quickSort(int left, int right, vector<int>& arr)
	{
		if (left >= right)
			return;
		int i, j, base, temp;
		i = left, j = right;
		base = arr[left];  //ȡ����ߵ���Ϊ��׼��
		while (i < j)
		{
			while (arr[j] >= base && i < j)
				j--;
			while (arr[i] <= base && i < j)
				i++;
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		//��׼����λ
		arr[left] = arr[i];
		arr[i] = base;
		quickSort(left, i - 1, arr);//�ݹ����
		quickSort(i + 1, right, arr);//�ݹ��ұ�
	}

	*/


	void print(vector<int>& nums) {
		for (auto i : nums) {
			cout << i << " ";
		}
		cout << endl;
	}


};


int main(){
	vector<int> nums = { 1009, 101, 45, 213, 456, 78, 90, 432, 564, 888 };
	Solution s;
	s.quickSort(nums,0,9);
	s.print(nums);

	system("pause");
	return 0;

}