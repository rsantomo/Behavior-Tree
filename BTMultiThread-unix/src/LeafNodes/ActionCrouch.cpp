#include "ActionCrouch.h"
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




ActionCrouch::ActionCrouch()
{
    //const std::string robot_ip = "192.168.0.196";
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, 9559);


}



ActionCrouch::ActionCrouch(int port)
{
    //const std::string robot_ip = "192.168.0.196";
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, port);
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, port);


}

void ActionCrouch::init()
{
    std::cout << "\033[1;31m ActionCrouch Initialized\033[0m " << std::endl;
}

void ActionCrouch::resume()
{

}

void ActionCrouch::halt(int i){

    behavior_proxy_ptr->stopBehavior("crouch");


}
void ActionCrouch::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    *status_ptr = BT_RUNNING;
   // while(1){
    //    sleep(1);
        //std::cout << "Ouch, my toe" << std::endl;
        behavior_proxy_ptr->runBehavior("crouch");
           // *status_ptr = BT_SUCCESS;

   // }
        while(1){
            sleep(0.1);
        }

}


