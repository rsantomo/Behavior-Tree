#ifndef ACTION_SET_H
#define ACTION_SET_H
#include "Globals.h"

#include "BehaviorTree.h"
#include <cstddef>
#include <alproxies/alspeechrecognitionproxy.h>
#include <alproxies/almemoryproxy.h>


/// Test
    class ActionSetActivity:public BehaviorTree::BehaviorTreeNode
	{
	public:
        BehaviorTree::BEHAVIOR_STATUS execute();
        void tick(BehaviorTree::BEHAVIOR_STATUS*);
        void init();
        ActionSetActivity();
        ~ActionSetActivity();
        void halt(int);
    private:
        std::vector<std::string> activity_vocabulary;
        std::vector<std::string> word_recognized;
        std::string word_recognized_old;
        float confidence_val;
        AL::ALValue al_word_vector;
        AL::ALSpeechRecognitionProxy* speech_rec_proxy_ptr;
        AL::ALMemoryProxy* memory_proxy_ptr;



	};
#endif
