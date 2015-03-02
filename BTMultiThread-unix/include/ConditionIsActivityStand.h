#ifndef CONDITION_IS_STANDUP_H
#define CONDITION_IS_STANDUP_H
#include "Globals.h"

#include "BehaviorTree.h"
#include <cstddef>
#include <alproxies/almemoryproxy.h>
#include <alproxies/albehaviormanagerproxy.h>

extern int a;
    /// Test
    class ConditionIsActivityStand:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ConditionIsActivityStand();
        void halt(int);
        //static void *tick(void*);
    private:
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        AL::ALMemoryProxy* memory_proxy_ptr;


	};
#endif
