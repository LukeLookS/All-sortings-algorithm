/////////////////////////////////////////////////////////////////////
// Merge.h                                                         //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include<vector>
#include"ISort.h"
#include"WindowsStopWatch.h"
#include<iostream>

class Merge : public ISort {
public:
	static int count;
	void sort1(std::vector<int> &data)
	{
		std::vector<int> tmp(data.size());
		mergeSort(data, tmp, 0, data.size() - 1);
	}
	void mergeSort(std::vector<int> &data,
		std::vector<int> &tmp, int first, int last)
	{
		if (first < last)
		{
			int mid = (last + first) / 2;
			mergeSort(data, tmp, first, mid);
			mergeSort(data, tmp, mid + 1, last);
			merge(data, tmp, first, mid + 1, last);
		}
	}
	void merge(std::vector<int> &data,
	std::vector<int> &tmp, int first, int mid, int last)
	{
		int leftEnd = mid - 1;
		int tmpPos = first;
		int numElements = last - first + 1;
		while (first <= leftEnd && mid <= last)
		{
			if (data[first] < data[mid])
				tmp[tmpPos++] = data[first++];
			else
				tmp[tmpPos++] = data[mid++];
		}
		while (first <= leftEnd)
			tmp[tmpPos++] = data[first++];

		while (mid <= last)
			tmp[tmpPos++] = data[mid++];

		for (int i = 0; i < numElements; ++i, --last)
			data[last] = tmp[last];
	}

	void sort(std::vector<int> &nums){
		if (nums.size() < 2) return;
		std::vector<int> result(nums.size());
		divide(nums,result, 0, nums.size() - 1);
		//nums = result;
	}
	void divide(std::vector<int> &nums, std::vector<int> &result,int start, int end) {
		if (start < end) {
			int mid = (start + end) / 2;
			divide(nums, result, start, mid);
			divide(nums, result, mid + 1, end);
			conquar(nums, result, start, mid+1, end);
		}
		
	}
	void conquar(std::vector<int> &nums, std::vector<int> &result, int start, int mid,int end) {
		int last = mid-1;
		int numElements = end - start + 1;
		int begin = start;
		while (start <= last||mid<=end) {
			if (start <= last &&(mid>end|| nums[start] <= nums[mid])) {
				result[begin++]=nums[start];
				start++;
			}
			if (mid <= end && (start > last || nums[mid] < nums[start])) {
				result[begin++] = nums[mid];
				mid++;
			}
		}
		for (int i = 0; i < numElements; ++i, --end)
			nums[end] = result[end];
	}
};

int Merge::count = 0;