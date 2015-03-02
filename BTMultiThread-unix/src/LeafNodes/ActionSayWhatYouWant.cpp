#include "ActionSayWhatYouWant.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>

#include <alproxies/albehaviormanagerproxy.h>
#include <alerror/alerror.h>

using namespace BehaviorTree;
using namespace std;




ActionSayWhatYouWant::ActionSayWhatYouWant()
{
    //const std::string robot_ip = "192.168.0.196";
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, 9559);
    speech_rec_proxy_ptr = new AL::ALSpeechRecognitionProxy(NAO_IP, 9559);



}
void ActionSayWhatYouWant::init()
{
    std::cout << "\033[1;31m ActionSayWhatYouWant Initialized\033[0m " << std::endl;
}

void ActionSayWhatYouWant::halt(int i){


}
void ActionSayWhatYouWant::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    *status_ptr = BT_RUNNING;
   // while(1){

        //speech_rec_proxy_ptr->unsubscribe("LastWordRecognized");
        //speech_proxy_ptr->say("Ready");
        speech_proxy_ptr->say("What do you want me to do");
        *status_ptr = BT_FAILURE;
        //speech_rec_proxy_ptr->subscribe("LastWordRecognized");


        while(1){
            sleep(0.1);
        }
  //  }

}


