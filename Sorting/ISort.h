/////////////////////////////////////////////////////////////////////
// ISort.h                                                         //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#include<vector>
struct ISort {
	ISort() {}
	virtual ~ISort() {}
	virtual void sort(std::vector<int>& vector) = 0;
};