#include "ActionMoveTo.h"
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




ActionMoveTo::ActionMoveTo()
{
   // const std::string robot_ip = "192.168.0.196";
    motion_proxy_ptr = new AL::ALMotionProxy(NAO_IP, 9559);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);




}



ActionMoveTo::ActionMoveTo(int port)
{
   // const std::string robot_ip = "192.168.0.196";
    motion_proxy_ptr = new AL::ALMotionProxy(NAO_IP, port);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, port);




}

void ActionMoveTo::init()
{
    std::cout << "\033[1;31m ActionMoveTo Initialized\033[0m " << std::endl;
}

void ActionMoveTo::resume()
{
    halted = false;
    std::cout << "\033[1;31m ActionMoveTo Resumed[0m " << std::endl;
}


void ActionMoveTo::halt(int i){
    halted = true;
    std::cout << "MoveTo Halted " << std::endl;
   // behavior_proxy_ptr->stopBehavior("back_off");


   // exit(0);
}
void ActionMoveTo::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    std::cout << "MoveTo Started " << std::endl;
    *status_ptr = BT_RUNNING;

 /*   behavior_proxy_ptr->runBehavior("back_off");
    *status_ptr = BT_SUCCESS;



    while(1){
        sleep(0.1);
    }*/

    AL::ALValue stiffness_name("Body");
    AL::ALValue stiffness(1.0f);
    AL::ALValue stiffness_time(1.0f);
    motion_proxy_ptr->stiffnessInterpolation(stiffness_name,
                                             stiffness,
                                             stiffness_time);
    motion_proxy_ptr->moveInit();

    while(1){
    while(!halted){
         sleep(1);
         std::cout << "MoveTo Running " << std::endl;
         motion_proxy_ptr->post.moveTo(0.1, 0.0, 0.0);

    }}
    *status_ptr = BT_SUCCESS;

}


