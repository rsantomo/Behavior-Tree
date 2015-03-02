#ifndef CONDITION_IS_SLEEP_H
#define CONDITION_IS_SLEEP_H
#include "Globals.h"

#include "BehaviorTree.h"
#include <cstddef>
#include <alproxies/almemoryproxy.h>
#include <alproxies/albehaviormanagerproxy.h>

extern int a;
    /// Test
    class ConditionIsActivitySleep:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ConditionIsActivitySleep();
        void halt(int);
        //static void *tick(void*);
    private:
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        AL::ALMemoryProxy* memory_proxy_ptr;


	};
#endif
