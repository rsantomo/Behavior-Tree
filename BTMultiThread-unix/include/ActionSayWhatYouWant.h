#ifndef ACTION_WHAT_H
#define ACTION_WHAT_H
#include "Globals.h"
#include "BehaviorTree.h"

#include <cstddef>
#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/alspeechrecognitionproxy.h>


extern int a;
    /// Test
    class ActionSayWhatYouWant:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionSayWhatYouWant();
        void halt(int);
        //static void *tick(void*);
    private:
        AL::ALBehaviorManagerProxy* behavior_proxy_ptr;
        AL::ALTextToSpeechProxy* speech_proxy_ptr;
        AL::ALSpeechRecognitionProxy* speech_rec_proxy_ptr;




	};
#endif
