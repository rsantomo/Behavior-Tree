#include "Globals.h"
#include "ConditionIsActivityCome.h"

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




ConditionIsActivityCome::ConditionIsActivityCome()
{

    memory_proxy_ptr = new AL::ALMemoryProxy(NAO_IP, 9559);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);

}
void ConditionIsActivityCome::init()
{
    std::cout << "\033[1;31m ConditionIsActivityCome Initialized\033[0m " << std::endl;
}

void ConditionIsActivityCome::halt(int i){

}
void ConditionIsActivityCome::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    //*status_ptr = BT_FAILURE;
    std::string activity_stand = "FETCH THE BALL";
    while(1){
       // sleep(1);//chage with some mutex stuff


        if(!activity_name.compare(activity_stand)){
            *status_ptr = BT_SUCCESS;
        }else{
         //   std::cout << "All I need is :" << activity_stand << std::endl;
         //   std::cout << "But I Got :" << activity_name << std::endl;
            behavior_proxy_ptr->stopBehavior("come_here");

            *status_ptr = BT_FAILURE;
        }


    }

}


