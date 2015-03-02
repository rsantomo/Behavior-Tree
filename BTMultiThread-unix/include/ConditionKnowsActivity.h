#ifndef CONDITION_KNOWS_ACTIVITY_H
#define CONDITION_KNOWS_ACTIVITY_H
#include "Globals.h"
#include "BehaviorTree.h"

#include <cstddef>

extern int a;
    /// Test
    class ConditionKnowsActivity:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ConditionKnowsActivity();
        void halt(int);
        //static void *tick(void*);


	};
#endif
