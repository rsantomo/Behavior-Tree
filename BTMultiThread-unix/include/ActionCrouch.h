#ifndef ACTION_CROUCH_H
#define ACTION_CROUCH_H
#include "Globals.h"
#include "BehaviorTree.h"

#include <cstddef>
#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/altexttospeechproxy.h>

extern int a;
    /// Test
    class ActionCrouch:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionCrouch();
        ActionCrouch(int);
        void halt(int);
        void resume();

        //static void *tick(void*);
    private:
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        AL::ALTextToSpeechProxy* speech_proxy_ptr;



	};
#endif
