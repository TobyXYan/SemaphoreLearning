#pragma once
#ifndef _CSEMATEST_H_
#define _CSEMATEST_H_

#include <Windows.h>
#include <thread>
class CSemaTest {
private: 
	HANDLE m_semaphore;
	std::thread taskObj[5];

public:
	CSemaTest();
	virtual ~CSemaTest();
	void StartOneTask(int id, int duration);
	void WaitAllDone();

private:
	void ThreadFunc(int id, int duration);

};
#endif