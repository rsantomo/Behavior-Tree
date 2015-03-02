#ifndef ACTION_SLEEP_H
#define ACTION_SLEEP_H
#include "Globals.h"
#include "BehaviorTree.h"

#include <cstddef>
#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/altexttospeechproxy.h>

extern int a;
    /// Test
    class ActionSleep:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionSleep();
        ~ActionSleep();
        void halt(int);
        //static void *tick(void*);
    private:
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        AL::ALTextToSpeechProxy* speech_proxy_ptr;



	};
#endif
