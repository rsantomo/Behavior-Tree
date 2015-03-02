#include "ActionTest.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>


using namespace BehaviorTree;
using namespace std;



void ActionTest::init()
{
    //std::cout << "\033[1;31m ActionTest Initialized\033[0m " << std::endl;
}

ActionTest::ActionTest()
{

}

void ActionTest::halt(int i){

}
void ActionTest::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr)
{*status_ptr = BT_SUCCESS;
    std::clock_t start;
    double duration = 20.0;
    int r;
    start = std::clock();

    while(1){
      sleep(1);


  *status_ptr = BT_SUCCESS;
     /* if(duration < 5.0){
          std::cout << "Action 1 Running! " << duration << std::endl;
           *status_ptr = BT_RUNNING;
      }else if (duration < 10.0){
          std::cout << "Action 1 Success! " << duration << std::endl;
          *status_ptr = BT_SUCCESS;
      }else if(duration < 15.0){
          std::cout << "Action 1 Failure! " << duration << std::endl;
          *status_ptr = BT_FAILURE;
      }else{
          std::cout << "Action 1 Success! " << duration << std::endl;
          *status_ptr = BT_SUCCESS;
      }*/
      //duration -= 0.5;
      /*
      r = std::rand() % 100;

    //pthread_cancel(threads[0]);
    if (r>50)
    {
        std::cout << "Action 1 Success!" << std::endl;
        *status_ptr = BT_SUCCESS;
    }
    else if(r>20)
    {
        std::cout << "Action 1 Running!" << std::endl;
         *status_ptr = BT_RUNNING;
    }else {
        std::cout << "Action 1 Failure!" << std::endl;
    *status_ptr = BT_FAILURE;
    }*/
    }

}


