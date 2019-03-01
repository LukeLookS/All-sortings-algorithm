#pragma once
/////////////////////////////////////////////////////////////////////
// Bubble.h                                                        //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////

#include"ISort.h"
#include<vector>
#include<iostream>
#include"WindowsStopWatch.h"

class Bubble : public ISort {
public:
	void sort(std::vector<int>& data)
	{
		bool again = true;
		unsigned int j;
		for (unsigned int i = 0; i < data.size() - 1 && again; i++)
		{
			for (j = data.size() - 1, again=false; j > i; --j)
			{
				if (data[j] < data[j - 1]) // swap the element
				{
                    std::swap(data[j], data[j - 1]);
					again = true;
				}
					
			}
		}
	}
};