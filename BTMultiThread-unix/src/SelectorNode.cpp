#include "BehaviorTree.h"
#include "SelectorNode.h"
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
using namespace BehaviorTree;
using namespace std;




SelectorNode::SelectorNode()
{


	currentPosition = -1;
}

void SelectorNode::init()
{

    BThread *child_thread = new BThread[children.size()];
    this->child_thread = child_thread;
    std::cout << "Initialization Selector with " <<  children.size() << " Children" << std::endl;
    is_active = false;
    BEHAVIOR_STATUS *child_status = new BEHAVIOR_STATUS[children.size()];
    this->child_status = child_status;

    for (int i = 0; i < children.size(); i++ ){
        child_status[i] = BT_IDLE;
    }

	currentPosition = -1;
    for (BehaviorTreeListIter iter = children.begin(); iter!= children.end(); iter++){
        (*iter)->init();
    }
}

void SelectorNode::resume()
{

}
void SelectorNode::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr)
{

    is_active = true;
  //  BThread *child_thread = new BThread[children.size()];// I need to create this shit again bcause it does not work on ubuntu (ON MAC IT DOES)
   // this->child_thread = child_thread;


    if (currentPosition == -1) //starting out
    {
        //init();
        currentPosition = 0;
    }

    if (children.size() == 0){
        *status_ptr = BT_SUCCESS;
    }


    BehaviorTreeListIter iter2 = children.begin();

        int child_index;
    while(1){// ticks all its children
        sleep(1);

        child_index = 0;
        while(child_index<children.size() && is_active){// it ticks the child from the most left one
            sleep(0.1);

        //std::cout << "is active?" << is_active <<std::endl;

            if(!child_thread[child_index].isSet()){// when initialized, the child has not been set, so it avoids to start thread of children that will never be executed
                child_thread[child_index].Set(&child_status[child_index],(iter2+child_index));
                child_thread[child_index].start();

            }
            if(child_thread[child_index].isSuspended()){// if it has already started (not suspended) it doesn't start it again
                sleep(0.1);
                child_thread[child_index].resume();


            }
            if(child_index==0 && *status_ptr == BT_RUNNING){
                *status_ptr == BT_IDLE;
            }

             do{
                *status_ptr = child_status[child_index];

            } while(*status_ptr == BT_IDLE);// waits until the child retuns either running, success or failure

            if((*status_ptr != BT_FAILURE ) && child_index < children.size()-1){
                if(!child_thread[child_index+1].isSuspended()){// IF ITS LEFT BROTHER IS RUNNING
                    halt(child_index+1);// this make the stopping behavior faster
               }//else{std::cout << "NO NEED OF HALTING BROTHER"<<std::endl;}
                child_index = 0;//restarts the  loop
                break;
            }else{
                ++child_index;
            }
        }
    }



}


void SelectorNode::halt(int child_index){

    if(child_index == 0){//if i have to stop all the children
        is_active = false;
    }

    for (BehaviorTreeListIter iter = children.begin()+child_index; iter!= children.end(); ++iter){
       (*iter)->halt(0);//suspends all the children of iter, starting from 0
    }
  //  sleep(4);//CHANGE THIS WITH SOME MUTEX STUF TO avoid that the thread object destructing before the thread it encapsulated has exited.
    for(int brother_index = child_index;brother_index<children.size();brother_index++){ //stops the brothers on the right running (are set)
               if(!child_thread[brother_index].isSuspended()){// suspend the threas
                   child_thread[brother_index].suspend();
                           }
    }




}

