#include "ActionTest2.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>

using namespace BehaviorTree;
using namespace std;



ActionTest2::ActionTest2(int action_number)
{
this->action_number = action_number;
}

void ActionTest2::init()
{
    //std::cout << "\033[1;32m ActionTest\033[0m " << action_number << " \033[1;32m Initialized\033[0m "<< std::endl;
}


void ActionTest2::halt(int i){

}
void ActionTest2::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr)
{

    int r;

    while(1){
      sleep(2);
    r = std::rand() % 100;

    //pthread_cancel(threads[0]);
    if (r>50)
    {
        std::cout << "Action " << action_number << " Success!" << std::endl;
        *status_ptr = BT_SUCCESS;
    }
    else if(r>20)
    {
        std::cout << "Action " << action_number << " Running!" << std::endl;
         *status_ptr = BT_RUNNING;
    }else {
        std::cout << "Action " << action_number << " Failure!" << std::endl;

    *status_ptr = BT_FAILURE;
    }
    }
}
