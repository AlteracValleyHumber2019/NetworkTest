////Using SDL, SDL Threads, SDL_image, standard IO, and, strings
//#include <SDL.h>
//#include <SDL_thread.h>
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <queue>
//#include <thread>
//
////Make a static queue
//static std::queue<int> theQueue;
//
//int threadFunction(void* data)
//{
//	using namespace std::literals::chrono_literals;
//	while (1)
//	{
//		if(SDL_LockMutex(testMutex) == -1)
//			return;
//		if(theQueue.size() > 0) 
//		{
//			printf("Things inside the queue = %d\n", theQueue.front());
//			theQueue.pop();
//			std::this_thread::sleep_for(0.1s);
//			//SDL_SemWait(SDL_CreateSemaphore(10));
//		}
//		SDL_UnlockMutex(testMutex);
//	}
//	return 0;
//}
//
//static bool quit = false;
//
//static SDL_mutex* testMutex;
//
//static SDL_mutex* inputMutex;
//static SDL_mutex* networkMutex;
//static SDL_mutex* physicsMutex;
//
//int main(int argc, char* argv[])
//{
//
//	int data = 1;
//	SDL_Thread* threadID = SDL_CreateThread(threadFunction, "Lazy Thread", (void*)data);
//
//	testMutex = SDL_CreateMutex();
//
//	while (1)
//	{
//		std::cin.get();
//		//Lock the queue to this thread
//		if (SDL_LockMutex(testMutex) == 0)
//		{
//			theQueue.emplace(1);
//			theQueue.emplace(2);
//			theQueue.emplace(3);
//
//			//Unlock it here
//			SDL_UnlockMutex(testMutex);
//		}
//		
//	}
//	SDL_WaitThread(threadID, NULL);
//	return 0;
//}
//
///*
//
//The general rule is if you don't know:
//
//What cache coherency is.
//What cache alignment is.
//How operating systems handle threads and processes.
//How to use a profiler.
//
//You should not be trying to use multithreaded optimization. 
//Play with fire and you will get burned. 
//However doing something not for the sake of performance like asynchronous file loading 
//isn't a bad idea for intermediate game developers.
//
//*/