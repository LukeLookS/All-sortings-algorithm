/////////////////////////////////////////////////////////////////////
// Insertion.h                                                     //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include"ISort.h"
class Insertion:public ISort {
public:
	void sort(std::vector<int>& data) {
		for (unsigned int i = 1, j; i < data.size(); i++) {
			int tmp = data[i];
			for (j = i; j > 0 && tmp < data[j - 1]; j--)
				data[j] = data[j - 1];
			data[j] = tmp;
		}
	}
};