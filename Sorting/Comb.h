/////////////////////////////////////////////////////////////////////
// Comb.h                                                          //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include"ISort.h"
#include<vector>
class Comb :public ISort {
public:
	void sort(std::vector<int>& data)
	{
		int step = data.size(), j, k;
		while ((step = int(step / 1.3)) > 1)
			for (j = data.size() - 1; j >= step; j--)
			{
				k = j - step;
				if (data[j] < data[k]) // swap the data
					std::swap(data[j], data[k]);
			}

		bool again = true;
		unsigned int q;
		for (unsigned int i = 0; i < data.size() - 1 && again; i++)
		{
			for (q = data.size() - 1, again = false; q > i; --q)
			{
				if (data[q] < data[q - 1])
				{
					std::swap(data[q], data[q - 1]);
					again = true;
				}
			}
		}
	}
};