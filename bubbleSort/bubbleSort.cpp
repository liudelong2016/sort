#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
	void bubbleSort(vector<int>&nums,int n){
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if (nums[j]<nums[i])
					swap(nums[i], nums[j]);
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
	vector<int> nums = { 1009, 101, 45, 23, 456, 78, 90, 432, 564, 88 };
	Solution s;
	s.bubbleSort(nums, 10);
	s.print(nums);

	system("pause");
	return 0;

}