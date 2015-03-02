#ifndef ACTION_STANDUP_H
#define ACTION_STANDUP_H
#include "Globals.h"

#include "BehaviorTree.h"
#include <cstddef>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/albehaviormanagerproxy.h>

#include <alproxies/alspeechrecognitionproxy.h>

extern int a;
    /// Test
    class ActionStandUp:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionStandUp();
        void halt(int);
        //static void *tick(void*);
    private:
        AL::ALRobotPostureProxy* posture_proxy_ptr;
        AL::ALTextToSpeechProxy* speech_proxy_ptr;
        AL::ALSpeechRecognitionProxy* speech_rec_proxy_ptr;
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;





	};
#endif
