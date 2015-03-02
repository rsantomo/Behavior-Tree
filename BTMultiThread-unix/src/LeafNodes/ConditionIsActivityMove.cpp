#include "Globals.h"
#include "ConditionIsActivityMove.h"

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




ConditionIsActivityMove::ConditionIsActivityMove()
{


}
void ConditionIsActivityMove::init()
{

    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);

    std::cout << "\033[1;31m ConditionIsActivityMove Initialized\033[0m " << std::endl;
}

void ConditionIsActivityMove::halt(int i){

}

void ConditionIsActivityMove::resume(){
halted = false;

}

void ConditionIsActivityMove::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    //*status_ptr = BT_FAILURE;
bool done = false;
    while(1){
       // sleep(1);//chage with some mutex stuff
      std::string activity_stand = "SAY GOODBYE";

        if(!activity_name.compare(activity_stand)){//activity_name.find(activity_stand)!=std::string::npos
            behavior_proxy_ptr->runBehavior("goodbye");

            *status_ptr = BT_SUCCESS;
        }else if(!done){
           // std::cout << "ISMOVE???" << std::endl;
            behavior_proxy_ptr->stopBehavior("goodbye");
            done = true;
            *status_ptr = BT_FAILURE;
        }


    }

}


