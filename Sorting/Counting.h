/////////////////////////////////////////////////////////////////////
// Counting.h                                                      //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include"ISort.h"
#include<vector>
class Counting :public ISort {
public:
	void sort(std::vector<int>& data)
	{
	    int i;
		int s = data.size();
		int largest = data[0];
		std::vector<int> temp(data.size());
		for (i = 1; i < s; i++)
			if (largest < data[i])
				largest = data[i];//Find the largest the value
		std::vector<int> count(largest + 1);
		for (i = 0; i <= largest; i++)
			count[i] = 0;
		for (i = 0; i < s; i++)
			count[data[i]]++;//Count the frequence of value 
		for (i = 1; i <= largest; i++)
			count[i] = count[i - 1] + count[i];
		for (i = s - 1; i >= 0; i--)
		{
			temp[count[data[i]] - 1] = data[i];
			count[data[i]]--;
		}
		data = temp;
	}
};