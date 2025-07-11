#ifndef PRUTHREAD_H
#define PRUTHREAD_H

#include "LPC17xx.h"
#include "timer.h"

// Standard Template Library (STL) includes
#include <iostream>
#include <vector>

using namespace std;

class Module;

class pruThread
{

	private:

		pruTimer* 		    TimerPtr;
	
		LPC_TIM_TypeDef* 	timer;
		IRQn_Type 			irq;
		uint32_t 			frequency;

		vector<Module*> vThread;		// vector containing pointers to Thread modules
		vector<Module*>::iterator iter;

	public:

		pruThread(LPC_TIM_TypeDef* timer, IRQn_Type irq, uint32_t frequency);

		void registerModule(Module *module);
        void unregisterModule(Module *module);
		void startThread(void);
        void stopThread(void);
		void run(void);
};

#endif

