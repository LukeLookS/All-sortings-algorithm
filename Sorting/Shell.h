/////////////////////////////////////////////////////////////////////
// Shell.h                                                         //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include<vector>
#include"ISort.h"
class Shell :public ISort {
	void sort(std::vector<int>& data) {
		unsigned int gap = data.size() / 2;

		while (1 <= gap) {
			for (unsigned int i = gap; i < data.size(); i++) {
				int j = 0;
				int temp = data[i];
				for (j = i - gap; j >= 0 && temp < data[j]; j = j - gap) {
					data[j + gap] = data[j];
				}
				data[j + gap] = temp;
			}
			gap = gap / 2;
		}

	}
};