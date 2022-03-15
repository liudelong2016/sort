#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
	void insertionSort(vector<int>&nums, int n){
		int temp;
		for (int i = 1; i < n; i++){
			int j = i - 1;
			temp = nums[i];
			if (nums[i] < nums[i - 1])
			{
				while (j >= 0 && temp < nums[j])
				{
					nums[j + 1] = nums[j];
					j--;
				}
				nums[j + 1] = temp;
			}
		}

	}


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
	s.insertionSort(nums, 10);
	s.print(nums);

	system("pause");
	return 0;

}