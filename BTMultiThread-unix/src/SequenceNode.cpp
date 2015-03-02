#include "BehaviorTree.h"
#include "SequenceNode.h"
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <iostream>

using namespace BehaviorTree;
using namespace std;





SequenceNode::SequenceNode()
{
   //read *child_thread = new BThread[0];
    currentPosition = -1;
}

void SequenceNode::init(){

    BThread *child_thread = new BThread[children.size()];
    this->child_thread = child_thread;
    BEHAVIOR_STATUS *child_status = new BEHAVIOR_STATUS[children.size()];
    this->child_status = child_status;
    for (int i = 0; i < children.size(); i++ ){
        child_status[i] = BT_IDLE;
    }


    std::cout << "Initialization Sequence with " <<  children.size() << " Children" << std::endl;
    is_active = true;
    for (BehaviorTreeListIter iter = children.begin(); iter!= children.end(); iter++){
        (*iter)->init();//initialize children (i don't create threads yet)
    }

}

void SequenceNode::resume()
{

}


void SequenceNode::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr)
{
std::cout << "Sequence Started" << is_active <<std::endl;
    is_active = true;




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

        child_index = 0;
        while(child_index<children.size() && is_active){// it ticks the child from the most left one

            sleep(0.1);
            *status_ptr = child_status[child_index];

            if(!child_thread[child_index].isSet()){// when initialized, the child has not been set, so it avoids to start thread of children that will never be executed
                child_thread[child_index].Set(&child_status[child_index],(iter2+child_index));
                child_thread[child_index].start();

            }
            if(child_thread[child_index].isSuspended()){//if(child_thread[child_index].isSuspended()){// if it has already started (not suspended) it doesn't start it again
                sleep(0.1);
                child_thread[child_index].resume();

            }

            if(child_index==0 && *status_ptr == BT_RUNNING){
                *status_ptr == BT_IDLE;
            }

             do{
                *status_ptr = child_status[child_index];
            } while(*status_ptr == BT_IDLE);// waits until the child retuns either running, success or failure

            if((*status_ptr != BT_SUCCESS ) && child_index < children.size()-1){
                if(!child_thread[child_index+1].isSuspended()){//if(!child_thread[child_index+1].isSuspended()){// IF ITS LEFT BROTHER IS RUNNING
                    halt(child_index+1);// this make the stopping behavior faster

                }
                child_index = 0;//restarts the  loop
                break;
            }else{
                ++child_index;
            }
        }

    }



}


void SequenceNode::halt(int child_index){


    if(child_index == 0){//if i have to stop all the children
        is_active = false;
    }

    for (BehaviorTreeListIter iter = children.begin()+child_index; iter!= children.end(); ++iter){
       (*iter)->halt(0);//suspends all the children, starting from 0
    }


   // sleep(4);//CHANGE THIS WITH SOME MUTEX STUF TO avoid that the thread object destructing before the thread it encapsulated has exited.

    for(int brother_index = child_index;brother_index<children.size();brother_index++){ //stops the brothers on the right running (are set)
               if(!child_thread[brother_index].isSuspended()){// cancel the threas
                   child_thread[brother_index].suspend();

                   //child_thread[brother_index].cancel();
                           }
    }


}

