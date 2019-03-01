/////////////////////////////////////////////////////////////////////
// HeapSort.h                                                      //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include<vector>
#include"ISort.h"
class Heap :public ISort {
	void sort(std::vector<int>& data)
	{
		for (int i = data.size() / 2 - 1; i >= 0; --i)// create the heap
			moveDown(data, i, data.size()-1);
		for (int i = data.size() - 1; i >= 1; --i)
		{
			std::swap(data[0], data[i]);//move the largest item to data[i]
			moveDown(data, 0,  i-1); // restore the heap property
		}
	}

	void moveDown(std::vector<int>& data, int first, int last)
	{
		int largest = 2 * first + 1;
		while (largest <= last)
		{
			if (largest < last && data[largest] < data[largest + 1])
				largest++;
			if (data[first] < data[largest])
			{
				std::swap(data[first], data[largest]);
				first = largest;
				largest = 2 * first + 1;
			}
			else
				largest = last + 1;
		}		
	}
};