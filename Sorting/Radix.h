/////////////////////////////////////////////////////////////////////
// Radix.h                                                         //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include"ISort.h"
#include<vector>
#include<queue>

class Radix :public ISort {
	void sort(std::vector<int>& data)
	{
		register int i, k, factor;
		register unsigned int j;
		const int radix = 10;
		const int digits = 7; 
		std::queue<int> queues[radix];
		for (i = 0, factor = 1; i < digits; factor *= radix, i++)
		{
			for (j = 0; j < data.size(); j++)
				queues[(data[j] / factor) % radix].push(data[j]);
			for (j = k = 0; j < radix; j++)
				while (!queues[j].empty())
				{
					data[k++] = queues[j].front();
					queues[j].pop();
				}
		}
	}
};
