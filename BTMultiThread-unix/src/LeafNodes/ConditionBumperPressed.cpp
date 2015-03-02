#include "Globals.h"
#include "ConditionBumperPressed.h"

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>

#include <alproxies/almemoryproxy.h>
#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/almotionproxy.h>


using namespace BehaviorTree;
using namespace std;



ConditionBumperPressed::ConditionBumperPressed()
{

    memory_proxy_ptr = new AL::ALMemoryProxy(NAO_IP, 9559);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, 9559);
    motion_proxy_ptr = new AL::ALMotionProxy(NAO_IP, 9559);



}



ConditionBumperPressed::ConditionBumperPressed(int port)
{

    memory_proxy_ptr = new AL::ALMemoryProxy(NAO_IP, port);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, port);
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, port);
    motion_proxy_ptr = new AL::ALMotionProxy(NAO_IP, port);



}
void ConditionBumperPressed::init()
{
    std::cout << "\033[1;31m ConditionBumperPressed Initialized\033[0m " << std::endl;
}

void ConditionBumperPressed::halt(int i){

}

void ConditionBumperPressed::resume()
{

}
void ConditionBumperPressed::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    std::string old_activity;
    bool done;
    while(1){
        *status_ptr = BT_FAILURE;

        sleep(0.1);
        //std::cout << "Current Posture " << posture_proxy_ptr->getPostureFamily() <<std::endl;
        l_bumper = memory_proxy_ptr->getData("RightBumperPressed");
        r_bumper = memory_proxy_ptr->getData("LeftBumperPressed");// they are swapped in the AL proxy =_=
        if((l_bumper > 0.5f || r_bumper > 0.5f)){//|| r_bumper > 0.5f
            std::cout << "Bumper(s) Pressed "<< l_bumper << std::endl;
            motion_proxy_ptr->stopMove();

            speech_proxy_ptr->say("Ouch my foot");
            old_activity = activity_name;
            activity_name = "BUMP";
                *status_ptr = BT_SUCCESS;
            done = true;
            sleep(3);
        }else{
           // std::cout << "Bumper(s) not Pressed"<< l_bumper << std::endl;
            *status_ptr = BT_FAILURE;

            if(done){
               // activity_name = old_activity;
                done = false;
            }
            //behavior_proxy_ptr->stopBehavior("back_off");

        }
    }

}


