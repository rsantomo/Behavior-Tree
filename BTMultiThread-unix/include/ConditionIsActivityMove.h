#ifndef CONDITION_IS_MOVE_H
#define CONDITION_IS_MOVE_H
#include "Globals.h"

#include "BehaviorTree.h"
#include <cstddef>
#include <alproxies/almemoryproxy.h>
#include <alproxies/albehaviormanagerproxy.h>

extern int a;
    /// Test
    class ConditionIsActivityMove:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ConditionIsActivityMove();
        void halt(int);
        void resume();
        //static void *tick(void*);
    private:
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        bool halted;




	};
#endif
