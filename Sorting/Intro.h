/////////////////////////////////////////////////////////////////////
// IntroSort.h                                                     //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <vector>
#include "ISort.h"
#include "HeapSort.h"

using namespace std;
class Intro :public ISort
{
public:
	void sort(vector<int> &data)
	{
		int length = data.size();
		introSort(data, 0, length - 1, floor(2 * log((float)length)));
	}
	void introSort(vector<int> &data, int start, int end, int maxdepth)
	{
		if (maxdepth == 0)
		{
			HeapSort->sort(data);
		}
		else {
			int bound = data[(start + end) / 2];
			int i = start, j = end;

			while (i <= j)
			{
				while (data[i]<bound)
					i++;
				while (data[j]>bound)
					j--;
				if (i <= j) {
					swap(data[i], data[j]);
					i++;
					j--;
				}
			}

			if (start < j)
				introSort(data, start, j, maxdepth - 1);
			if (i < end)
				introSort(data, i, end, maxdepth - 1);
		}
	}
private:
	ISort* HeapSort = new Heap();

};