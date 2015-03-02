#include "Globals.h"
#include "ConditionIsActivitySleep.h"

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




ConditionIsActivitySleep::ConditionIsActivitySleep()
{

    memory_proxy_ptr = new AL::ALMemoryProxy(NAO_IP, 9559);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);

}
void ConditionIsActivitySleep::init()
{
    std::cout << "\033[1;31m ConditionIsActivitySleep Initialized\033[0m " << std::endl;
}

void ConditionIsActivitySleep::halt(int i){


}
void ConditionIsActivitySleep::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    //*status_ptr = BT_FAILURE;
    std::string activity_stand = "GO TO SLEEP";
    bool found;
    while(1){
     // sleep(1);//chage with some mutex stuff

    found = activity_name.find(activity_stand)!=std::string::npos;
        if(!activity_name.compare(activity_stand)){
            *status_ptr = BT_SUCCESS;
        }else{
         //   std::cout << "All I need is :" << activity_name << std::endl;
        //    std::cout << "But I Got :" << activity_stand << std::endl;
            behavior_proxy_ptr->stopBehavior("sleep");

            *status_ptr = BT_FAILURE;
        }


    }

}


