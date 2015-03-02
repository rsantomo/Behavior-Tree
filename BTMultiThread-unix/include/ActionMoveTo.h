#ifndef ACTION_MOVETO_H
#define ACTION_MOVETO_H
#include "Globals.h"

#include "BehaviorTree.h"
#include <cstddef>
#include <alproxies/almotionproxy.h>
#include <alproxies/albehaviormanagerproxy.h>

extern int a;
    /// Test
    class ActionMoveTo:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionMoveTo(int);
        ActionMoveTo();
        void halt(int);
        void resume();

        //static void *tick(void*);
    private:
        AL::ALMotionProxy* motion_proxy_ptr;
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        bool halted;





	};
#endif
