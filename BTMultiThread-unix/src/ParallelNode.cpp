#include "BehaviorTree.h"
#include "ParallelNode.h"

#include <iostream>
using namespace BehaviorTree;
using namespace std;

ParallelNode::ParallelNode(FAILURE_POLICY failurePolicy, SUCCESS_POLICY successPolicy)
{
    failPolicy = failurePolicy;
    succeedPolicy = successPolicy;
    childrenStatus = NULL;
}
void ParallelNode::init()
{
    is_active = false;

    BThread *child_thread = new BThread[children.size()];
    this->child_thread = child_thread;
    std::cout << "Initialization Selector with " <<  children.size() << " Children" << std::endl;
    BEHAVIOR_STATUS *child_status = new BEHAVIOR_STATUS[children.size()];
    this->child_status = child_status;

    for (BehaviorTreeListIter iter = children.begin(); iter!= children.end(); iter++)
        (*iter)->init();

    if (childrenStatus != NULL)
        delete childrenStatus;
    childrenStatus = new ChildrenStatusMap();
    for (unsigned int i = 0 ; i<children.size(); i++)
        childrenStatus->insert( make_pair(children.at(i),BT_RUNNING));
}


void ParallelNode::resume()
{

}

void ParallelNode::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr)
{

    is_active = true;


    for (int i = 0; i < children.size(); i++ ){
        child_status[i] = BT_IDLE;
    }


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
           // sleep(0.1);


       // std::cout << "return status of seq " << child_status[0] <<std::endl;

            if(!child_thread[child_index].isSet()){// when initialized, the child has not been set, so it avoids to start thread of children that will never be executed
                child_thread[child_index].Set(&child_status[child_index],(iter2+child_index));
            }
            if(child_thread[child_index].isSuspended()){// if it has already started (not suspended) it doesn't start it again
                child_thread[child_index].start();
            }

             do{
                *status_ptr = child_status[child_index];
            } while(*status_ptr == BT_IDLE);// waits until the child retuns either running, success or failure

                 child_index++;// for now I dont check if i have to stop them

        }

    }

}

void ParallelNode::halt(int child_index){

    if(child_index == 0){//if i have to stop all the children
        is_active = false;
    }

    for (BehaviorTreeListIter iter = children.begin()+child_index; iter!= children.end(); iter++){
       (*iter)->halt(0);//suspends all the children of iter, starting from 0
    }
    sleep(4);//CHANGE THIS WITH SOME MUTEX STUF TO avoid that the thread object destructing before the thread it encapsulated has exited.
    for(int brother_index = child_index;brother_index<children.size();brother_index++){ //stops the brothers on the right running (are set)
               if(!child_thread[brother_index].isSuspended()){// cancel the threas
                            //  child_thread[brother_index].cancel();
                           }
    }

    std::cout << "Parallel Halted" << std::endl;

}
