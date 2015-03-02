// save diagnostic state
#pragma GCC diagnostic push

// turn off the specific warning. Can also use "-Wall"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

#include "ActionSetActivity.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>
#include <alproxies/almemoryproxy.h>
#include <alproxies/alspeechrecognitionproxy.h>
#include <alerror/alerror.h>


using namespace BehaviorTree;
using namespace std;




ActionSetActivity::ActionSetActivity()
{
    speech_rec_proxy_ptr = new AL::ALSpeechRecognitionProxy(NAO_IP, 9559);
    memory_proxy_ptr = new AL::ALMemoryProxy(NAO_IP, 9559);
}

ActionSetActivity::~ActionSetActivity()
    {
    speech_rec_proxy_ptr->unsubscribe("LastWordRecognized");
    }
void ActionSetActivity::init()
{
    //memory_proxy_ptr->removeData("LastWordRecognized");

    activity_name = "STOP";
    std::cout << "\033[1;31m ActionSetActivity Initialized\033[0m " << std::endl;

    //speech_rec_proxy_ptr->isRunning();
    //initializing vocabulary
   // activity_vocabulary.push_back("FREEZE");
    activity_vocabulary.push_back("STAND UP");
    activity_vocabulary.push_back("SIT DOWN PLEASE");
    activity_vocabulary.push_back("GO TO SLEEP");
    activity_vocabulary.push_back("FETCH THE BALL");
    activity_vocabulary.push_back("SAY GOODBYE");



    speech_rec_proxy_ptr->setWordListAsVocabulary(activity_vocabulary);
    speech_rec_proxy_ptr->subscribe("LastWordRecognized");
}

void ActionSetActivity::halt(int i){
    speech_rec_proxy_ptr->unsubscribe("LastWordRecognized");

}


void ActionSetActivity::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    *status_ptr = BT_RUNNING;
   // activity_name = "MOVE";

    int count = 0;
    while(0){
        sleep(5);
        count ++;

        if (count < 10){
            activity_name = "STAND UP";
        } else if(count < 15){
            activity_name = "MOVE";
            }else if(count < 20){
                activity_name = "GO TO SLEEP";
                }else if(count < 25){
                    activity_name = "COME HERE";
                    }else{
                        count = 0;
                    }

    }

    while(1){
        //std::cout << " Activity Set: " << activity_name << std::endl;

    sleep(0.1);

        al_word_vector = memory_proxy_ptr->getData("LastWordRecognized");
        word_recognized =  memory_proxy_ptr->getData("LastWordRecognized");
        confidence_val = al_word_vector[1];


        if(confidence_val > 0.4){// al_word_vector[1] contains the confidence of the most recognized word which IS CONTAINED IN al_word_vector[0]
            std::cout << " Word Accepted: " << word_recognized[0] << std::endl;
            word_recognized_old =  word_recognized[0];
            if(activity_name.compare(word_recognized_old)){
                activity_name = word_recognized_old;
            }
        }else{
            std::cout << " Word not Accepted. Sending: " << activity_name << std::endl;
        }
    }
}


#pragma warning( pop )

