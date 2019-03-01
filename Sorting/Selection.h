/////////////////////////////////////////////////////////////////////
// Selection.h                                                     //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include"ISort.h"
#include<vector>
#include"WindowsStopWatch.h"
#include<iostream>
class Selection : public ISort {
public:
	void sort(std::vector<int>& data) {
		for (unsigned int i = 0, j, least; i < data.size()-1; i++) {
			for (j = i + 1, least = i; j < data.size();j++) {
				if (data[j] < data[least])
					least = j;
			}
			std::swap(data[least], data[i]);
		}
	}
};