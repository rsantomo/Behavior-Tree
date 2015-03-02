#ifndef ACTION_TEST2_H
#define ACTION_TEST2_H

#include <cstddef>
#include "BehaviorTree.h"


    /// Test
    class ActionTest2:public BehaviorTree::BehaviorTreeNode
	{
    public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        int action_number;

        //void execute2(BehaviorTree::BEHAVIOR_STATUS*, int*);
        void init();
        ActionTest2(int);
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void halt(int);
        const BehaviorTree::BehaviorTreeList* getChildren() const
		{
			return NULL;
		}
	};

#endif
