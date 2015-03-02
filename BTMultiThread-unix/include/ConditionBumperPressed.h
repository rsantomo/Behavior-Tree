#ifndef CONDITION_BUMPER_PRESSED_H
#define CONDITION_BUMPER_PRESSED_H
#include "Globals.h"

#include "BehaviorTree.h"
#include <cstddef>
#include <alproxies/almemoryproxy.h>
#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/almotionproxy.h>


extern int a;
    /// Test
    class ConditionBumperPressed:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ConditionBumperPressed();
        ConditionBumperPressed(int);
        void halt(int);
        void resume();

        //static void *tick(void*);
    private:
        float l_bumper;
        float r_bumper;
        AL::ALMemoryProxy* memory_proxy_ptr;
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        AL::ALTextToSpeechProxy* speech_proxy_ptr;
        AL::ALMotionProxy* motion_proxy_ptr;




	};
#endif
