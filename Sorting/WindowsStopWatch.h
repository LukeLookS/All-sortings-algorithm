/////////////////////////////////////////////////////////////////////
// WindowsStopWatch.h                                              //
//                                                                 //
// Mengjie Shi, CSE674                                             //
// SUID:  457056896                                                //
/////////////////////////////////////////////////////////////////////
#pragma once
#ifndef WINDOWS_STOPWATCH_H
#define WINDOWS_STOPWATCH_H

//
// Based on code from Dr. Fawcett:
// http ://www.lcs.syr.edu/faculty/fawcett/handouts/CSE687/code/HiResTimerNativeCpp/HiResTimer.cpp
// http ://www.lcs.syr.edu/faculty/fawcett/handouts/CSE687/code/HiResTimerNativeCpp/HiResTimer//


#ifdef linux
#elif defined __APPLE_CC__
#else
#include <Windows.h>

class WindowsStopwatch {
public:
	WindowsStopwatch();
	void start();
	void stop();
	long getTime();
protected:
	__int64 a, b, f;
};

#endif
#endif