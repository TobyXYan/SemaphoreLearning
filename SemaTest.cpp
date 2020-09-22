#include "SemaTest.h"
#include <iostream>


CSemaTest::CSemaTest()
{
	m_semaphore = CreateSemaphore(NULL,1,3,TEXT("SemaphoreLearning"));
	ReleaseSemaphore(m_semaphore, 1, NULL);
	ReleaseSemaphore(m_semaphore, 1, NULL);
}

void DoTest(int duration) {};

void CSemaTest::StartOneTask(int id, int duration)
{
	//std::thread taskObj(DoTest, duration);
	taskObj[id-1] = std::thread(&CSemaTest::ThreadFunc, this, id, duration);//Equivalent to call this->ThreadFuc(duration);
}

void CSemaTest::ThreadFunc(int id, int duration)
{
	//std::cout << "Thread " << id << " is waiting to entering club" << std::endl;
	WaitForSingleObject(m_semaphore,INFINITE);

	std::cout << "Wait thread " << id << " for "<< duration << std::endl;
	Sleep(duration);

	std::cout << "Thread " << id << " is leaving the club" << std::endl;
	ReleaseSemaphore(m_semaphore,1, NULL);
}

CSemaTest::~CSemaTest()
{
	CloseHandle(m_semaphore);
}

void CSemaTest::WaitAllDone()
{
	StartOneTask(1, 5000);
	StartOneTask(2, 5000);
	StartOneTask(3, 5000);
	StartOneTask(4, 5000);
	StartOneTask(5, 5000);
	taskObj[0].join();
	taskObj[1].join();
	taskObj[2].join();
	taskObj[3].join();
	taskObj[4].join();
}