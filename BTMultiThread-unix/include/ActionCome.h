#ifndef ACTION_COME_H
#define ACTION_COME_H
#include "Globals.h"
#include "BehaviorTree.h"

#include <cstddef>
#include <alproxies/almotionproxy.h>

#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/altexttospeechproxy.h>

extern int a;
    /// Test
    class ActionCome:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionCome();
        void halt(int);
        //static void *tick(void*);
    private:
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        AL::ALTextToSpeechProxy* speech_proxy_ptr;
        AL::ALMotionProxy* motion_proxy_ptr;




	};
#endif
