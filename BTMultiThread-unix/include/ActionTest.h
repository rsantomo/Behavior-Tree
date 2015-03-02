#ifndef ACTION_TEST_H
#define ACTION_TEST_H
#include "BehaviorTree.h"
#include <cstddef>
extern int a;
    /// Test
    class ActionTest:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionTest();
        void halt(int);
        //static void *tick(void*);
        const BehaviorTree::BehaviorTreeList* getChildren() const
		{
			return NULL;
		}
	};
#endif
