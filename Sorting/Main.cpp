/////////////////////////////////////////////////////////////////////
// Main.cpp                                                        //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#include"ISort.h"
#include"Bubble.h"
#include"Comb.h"
#include"Counting.h"
#include"Insertion.h"
#include"Selection.h"
#include"HeapSort.h"
#include"Shell.h"
#include"Merge.h"
#include"Quick.h"
#include"Intro.h"
#include"Radix.h"
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<vector>
#include<sstream>

int ConvertToInt(string str)
{
	int num;
	std::stringstream ss;
	ss << str;
	ss >> num;
	return num;
}

void split(const string &s, char delim, vector<string> &elems) {
	string str;
	for (size_t i = 0; i <s.size(); i++)
	{
		if (s.at(i) != delim)
		{
			str.append(s, i, 1);
			if (i == s.size() - 1)
				elems.push_back(str);
		}
		else if (str != "")
		{
			elems.push_back(str);
			str = "";
		}
	}
}

vector<int> VectorGene(string filename, int size) {
	std::ifstream file(filename); // get the file 
	std::string str;
	vector<int> elemInt;
	vector<string>elemString;
	int num;
	while (std::getline(file, str))
	split(str, '-', elemString);
	if (size >= elemString.size()){
		for (auto str : elemString)
		elemInt.push_back(ConvertToInt(str));
	}
	else{
		for (unsigned int i = 0; i < size; i++)
		elemInt.push_back(ConvertToInt(elemString[i]));
	}
	return elemInt;
}


// print the vector in some format
void PrintVector(vector<int> data, string SortType, string SortStatus) {
	cout << endl << "----------------------------------------------------\n";
	cout << SortStatus << " " << SortType;
	cout << endl << "----------------------------------------------------\n";
	int i = 0;
	for (auto val : data)
	{
		cout << val << setw(4);
		i++;
		if (i > 4) {
			cout << "\n";
			i = 0;
		}
	}
}

void SortAnalysis(ISort *S, std::vector<int> Best, std::vector<int> Worst, std::vector<int> Average, string SortType) {
	cout << endl << SortType;
	cout << endl << "----------------------------------------------------\n";
	WindowsStopwatch w;
	WindowsStopwatch w1;
	WindowsStopwatch w2;
	
	cout << "Best(ascending) sorting case cause ";
	w.start();
	S->sort(Best);// obtain the best case time
	w.stop();
	cout << w.getTime() << "ms" << endl;

	cout << "Worst(descending) sorting case cause ";
	w1.start();
	S->sort(Worst); // obtain the worst case time
	w1.stop();
	cout << w1.getTime() << "ms" << endl;

	cout << "Average(random) sorting case cause ";
	w2.start();
	S->sort(Average); // obtain the average case time
	w2.stop();
	cout << w2.getTime() << "ms"<< endl << endl;

	
}


void main() {
	// declare the instance of each sort algorithm
	QuickSort qt;
	vector<int> SortTestq = VectorGene("SortTest.txt", 10);
	qt.sort(SortTestq);
	PrintVector(SortTestq, "BubbleSort", "Before");

	int goo = 1;
	int &gs = goo;
	int *c = new int[3]{1,2,3};
	int &sg = *c;
	int qq = sizeof(c) / sizeof(*c);

	ISort* BubbleS = new Bubble();
	ISort* CombS = new Comb();
	ISort* CountingS = new Counting();
	ISort* HeapS = new Heap();
	ISort* InsertS = new Insertion();
	ISort* IntroS = new Intro();
	ISort* MergeS = new Merge();
	ISort* QuickS = new Quick();  
	ISort* RadixS = new Radix();
	ISort* SelectionS = new Selection();
	ISort* ShellS = new Shell();
	
	// sorting function test demo which used for test whether the sort function is right
	vector<int> SortTestA;
	vector<int> SortTestB = VectorGene("SortTest.txt", 10);
	PrintVector(SortTestB, "BubbleSort","Before");
	SortTestA = SortTestB;
	BubbleS->sort(SortTestA);
	PrintVector(SortTestA, "BubbleSort", "After");

	PrintVector(SortTestB, "MergeSort", "Before");
	SortTestA = SortTestB;
	MergeS->sort(SortTestA);
	PrintVector(SortTestA, "MergeSort", "After");


	PrintVector(SortTestB, "CombSort", "Before");
	SortTestA = SortTestB;
	CombS->sort(SortTestA);
	PrintVector(SortTestA, "CombSort", "After");

	PrintVector(SortTestB, "CountingSort", "Before");
	SortTestA = SortTestB;
	CountingS->sort(SortTestA);
	PrintVector(SortTestA, "CountingSort", "After");

	PrintVector(SortTestB, "HeapSort", "Before");
	SortTestA = SortTestB;
	HeapS->sort(SortTestA);
	PrintVector(SortTestA, "HeapSort", "After");

	PrintVector(SortTestB, "InsertionSort", "Before");
	SortTestA = SortTestB;
	InsertS->sort(SortTestA);
	PrintVector(SortTestA, "InsertionSort", "After");

	PrintVector(SortTestB, "IntroSort", "Before");
	SortTestA = SortTestB;
	IntroS->sort(SortTestA);
	PrintVector(SortTestA, "IntroSort", "After");

	PrintVector(SortTestB, "MergeSort", "Before");
	SortTestA = SortTestB;
	MergeS->sort(SortTestA);
	PrintVector(SortTestA, "MergeSort", "After");

	PrintVector(SortTestB, "QuickSort", "Before");
	SortTestA = SortTestB;
	QuickS->sort(SortTestA);
	PrintVector(SortTestA, "QuickSort", "After");

	PrintVector(SortTestB, "RadixSort", "Before");
	SortTestA = SortTestB;
	RadixS->sort(SortTestA);
	PrintVector(SortTestA, "RadixSort", "After");

	PrintVector(SortTestB, "SelectionSort", "Before");
	SortTestA = SortTestB;
	SelectionS->sort(SortTestA);
	PrintVector(SortTestA, "SelectionSort", "After");

	PrintVector(SortTestB, "ShellSort", "Before");
	SortTestA = SortTestB;
	ShellS->sort(SortTestA);
	PrintVector(SortTestA, "ShellSort", "After");

	//sort algorithm best worst average test
	for (int i = 1000; i < 128001; i = 2 * i) {
		cout << endl << "Sorting value number is " << i;
		cout << endl << "====================================================\n";
		vector<int> best = VectorGene("ascending.txt", i),
					worst = VectorGene("decsending.txt", i),
					average = VectorGene("random.txt", i);
		SortAnalysis(BubbleS, best, worst, average, "BubbleSort");
		SortAnalysis(CombS, best, worst, average, "CombSort");
		SortAnalysis(CountingS, best, worst, average, "CountingSort");
		SortAnalysis(HeapS, best, worst, average, "HeapSort");
		SortAnalysis(InsertS, best, worst, average, "InsertSort");
		SortAnalysis(IntroS, best, worst, average, "IntroSort");
		SortAnalysis(MergeS, best, worst, average, "MergeSort");
		SortAnalysis(QuickS, best, worst, average, "QuickSort");
		SortAnalysis(RadixS, best, worst, average, "RadixSort");
		SortAnalysis(SelectionS, best, worst, average, "SelectionSort");
		SortAnalysis(ShellS, best, worst, average, "ShellSort");
	}
	system("pause");
}