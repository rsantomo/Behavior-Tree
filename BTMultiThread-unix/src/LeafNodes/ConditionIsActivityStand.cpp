#include "Globals.h"
#include "ConditionIsActivityStand.h"

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




ConditionIsActivityStand::ConditionIsActivityStand()
{

    memory_proxy_ptr = new AL::ALMemoryProxy(NAO_IP, 9559);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);

}
void ConditionIsActivityStand::init()
{
    std::cout << "\033[1;31m ConditionIsActivityStand Initialized\033[0m " << std::endl;
}

void ConditionIsActivityStand::halt(int i){

}
void ConditionIsActivityStand::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
   // std::cout << " ConditionIsActivityStand :" << std::endl;
    std::string activity_stand = "STAND UP";
    while(1){
       // sleep(1);//chage with some mutex stuff

        if(!activity_name.compare(activity_stand)){
            *status_ptr = BT_SUCCESS;
        }else{
            //std::cout << "All I need is :" << activity_name << std::endl;
            //std::cout << "But I Got :" << activity_stand << std::endl;
            behavior_proxy_ptr->stopBehavior("stand_up");

            *status_ptr = BT_FAILURE;
        }


    }

}


