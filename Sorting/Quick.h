/////////////////////////////////////////////////////////////////////
// Quick.h                                                         //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include<vector>
#include"ISort.h"
class Quick :public ISort {
	void sort(std::vector<int>& data)
	{
		int n = data.size();
		if (n < 2)
			return;
		int max = 0;
		for (int i = 1; i < n; i++)
			if (data[max] < data[i])
				max = i;
		std::swap(data[n - 1], data[max]);
		sort(data, 0, n - 2);
	}

	void sort(std::vector<int>& data, int first, int last)
	{
		int lower = first + 1, upper = last;
		std::swap(data[first], data[(first + last) / 2]);
		int bound = data[first];
		while (lower <= upper)
		{
			while (data[lower] < bound)
				lower++;
			while (bound < data[upper])
				upper--;
			if (lower < upper)
				std::swap(data[lower++], data[upper--]);
			else
				lower++;
		}
		std::swap(data[upper], data[first]);
		if (first < upper - 1)
			sort(data, first, upper - 1);
		if (upper + 1 < last)
			sort(data, upper + 1, last);
	}
};

class QuickSort{
public:
	void sort1(std::vector<int>& data)
	{
		int n = data.size();
		if (n < 2)
			return;
		int max = 0;
		for (int i = 1; i < n; i++)
			if (data[max] < data[i])
				max = i;
		std::swap(data[n - 1], data[max]);
		sort(data, 0, n - 2);
	}

	void sort1(std::vector<int> & nums, int low, int high) {
		std::swap(nums[low], nums[(high + low) / 2]);
		int pivot = nums[low];
		int temp1 = low;
		int temp2 = high;
		low = low + 1;
		while (low <= high) {
			while (nums[high] > pivot)
				high--;
			while (nums[low] < pivot)
				low++;
			if (low < high)
				std::swap(nums[low], nums[high]);
			else {
				low++;
			}
		}
		std::swap(nums[temp1], nums[high]);
		if (temp1<high - 1)
			sort(nums, temp1, high - 1);
		if (high + 1<temp2)
			sort(nums, high + 1, temp2);
	}

	void sort(std::vector<int> &nums) {
		if (nums.size() < 2) return;
		int low = 0;
		int high = nums.size() - 1;
		int max = 0;
		for (int i = 0; i <= high; i++) {
			if (nums[max] < nums[i])
				max = i;
		}
		std::swap(nums[max], nums[high]);
		sort(nums, low, high - 1);
	}
	void sort(std::vector<int> &nums, int low, int high) {
		std::swap(nums[low], nums[(low + high) / 2]);
		int pivot = nums[low];
		int lo = low + 1;
		int hi = high;
		while (lo <= hi) {
			while (nums[lo] < pivot)
				lo++;
			while (nums[hi] > pivot)
				hi--;
			if (lo < hi)
				std::swap(nums[lo], nums[hi]);
			else {
				lo++;
			}
		}
		std::swap(nums[low], nums[hi]);
		if (low < hi - 1)
			sort(nums, low, hi - 1);
		if (high > hi + 1)
			sort(nums, hi + 1, high);
	}
};