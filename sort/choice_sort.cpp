#include<iostream>
using namespace std;
#include<vector>

class Solution{
public:
	void select_sort(vector<int>&v,int n){
		int minIndex;
		for(int i = 0; i < n; i++)
		{
			minIndex = i;
			for (int j = i + 1; j < n; j++){
				if (v[j] < v[minIndex])
					minIndex = j;
			}
			swap(v[i], v[minIndex]);
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
	vector<int> nums = { 1, 10, 45, 23, 456, 78, 90, 432, 564, 88 };
	Solution s;
	s.select_sort(nums,10);
	s.print(nums);

	system("pause");
	return 0;
	
}