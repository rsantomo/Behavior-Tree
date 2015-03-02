#include "Globals.h"
#include "ConditionKnowsActivity.h"

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>

#include <alproxies/almemoryproxy.h>
#include <alerror/alerror.h>

using namespace BehaviorTree;
using namespace std;




ConditionKnowsActivity::ConditionKnowsActivity()
{


}
void ConditionKnowsActivity::init()
{
    std::cout << "\033[1;31m ConditionKnowsActivity Initialized\033[0m " << std::endl;
}

void ConditionKnowsActivity::halt(int i){

}
void ConditionKnowsActivity::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
    //*status_ptr = BT_FAILURE;
   // *status_ptr = BT_SUCCESS;

    std::cout << "ConditionKnowsActivity started" << std::endl;

    while(1){
        //std::cout << "Activity name:"<< activity_name << std::endl;

        sleep(0.1);//chage with some mutex stuff
        if(activity_name != "STOP" && activity_name != ""){//|| r_bumper > 0.5f
           *status_ptr = BT_SUCCESS;

        }else{
           *status_ptr = BT_FAILURE;
            //*status_ptr = BT_SUCCESS;
        }

    }

}


