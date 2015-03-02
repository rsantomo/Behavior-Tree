#include "ActionCome.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>
#include <alproxies/almotionproxy.h>
#include <alproxies/albehaviormanagerproxy.h>

using namespace BehaviorTree;
using namespace std;




ActionCome::ActionCome()
{
    //const std::string robot_ip = "192.168.0.196";
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, 9559);
    motion_proxy_ptr = new AL::ALMotionProxy(NAO_IP, 9559);



}
void ActionCome::init()
{
   // behavior_proxy_ptr->stopBehavior("come_here");

    std::cout << "\033[1;31m ActionCome Initialized\033[0m " << std::endl;
}

void ActionCome::halt(int i){
    std::cout << "Come here Halted" << std::endl;
motion_proxy_ptr->stopMove();
    //behavior_proxy_ptr->stopBehavior("come_here");
}
void ActionCome::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    *status_ptr = BT_SUCCESS;
    std::cout << " ActionCome :" << std::endl;


    // behavior_proxy_ptr->runBehavior("come_here");

    AL::ALValue stiffness_name("Body");
    AL::ALValue stiffness(1.0f);
    AL::ALValue stiffness_time(1.0f);
    motion_proxy_ptr->stiffnessInterpolation(stiffness_name,
                                             stiffness,
                                             stiffness_time);
    motion_proxy_ptr->moveInit();
    motion_proxy_ptr->post.moveTo(0.4, 0.0, 0.0);

     while(1){
         sleep(0.1);
     }

}


