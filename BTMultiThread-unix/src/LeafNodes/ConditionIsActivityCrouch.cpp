#include "Globals.h"
#include "ConditionIsActivityCrouch.h"

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>

#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/almemoryproxy.h>
#include <alerror/alerror.h>

using namespace BehaviorTree;
using namespace std;




ConditionIsActivityCrouch::ConditionIsActivityCrouch()
{

    memory_proxy_ptr = new AL::ALMemoryProxy(NAO_IP, 9559);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);

}
void ConditionIsActivityCrouch::init()
{
    std::cout << "\033[1;31m ConditionIsActivityCrouch Initialized\033[0m " << std::endl;
}

void ConditionIsActivityCrouch::halt(int i){

}
void ConditionIsActivityCrouch::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    //*status_ptr = BT_FAILURE;
    std::string activity_stand = "SIT DOWN PLEASE";
    while(1){
      //  sleep(1);//chage with some mutex stuff

        if(activity_name.find(activity_stand)!=std::string::npos){
            *status_ptr = BT_SUCCESS;
        }else{
         //   std::cout << "All I need is :" << activity_name << std::endl;
        //    std::cout << "But I Got :" << activity_stand << std::endl;
            behavior_proxy_ptr->stopBehavior("crouch");

            *status_ptr = BT_FAILURE;
        }


    }

}


