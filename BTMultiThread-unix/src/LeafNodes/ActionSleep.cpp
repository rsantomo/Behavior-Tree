#include "ActionSleep.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>

#include <alproxies/albehaviormanagerproxy.h>

using namespace BehaviorTree;
using namespace std;




ActionSleep::ActionSleep()
{
    //const std::string robot_ip = "192.168.0.196";
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, 9559);



}


ActionSleep::~ActionSleep(){
    delete speech_proxy_ptr;
   // delete behavior_proxy_ptr;
    }



void ActionSleep::init()
{
    std::cout << "\033[1;31m ActionSleep Initialized\033[0m " << std::endl;
}

void ActionSleep::halt(int i){
    std::cout << "ActionSleep Halted" << std::endl;
behavior_proxy_ptr->stopBehavior("sleep");


}
void ActionSleep::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
   std::cout << "ActionSleep Started" << std::endl;
   *status_ptr = BT_RUNNING;

   speech_proxy_ptr->say("OK, I'm gonna go to sleep");

    behavior_proxy_ptr->runBehavior("sleep");

           // *status_ptr = BT_SUCCESS;

    while(1){
        sleep(0.1);
    }
}


