#ifndef BTHREAD_H
#define BTHREAD_H
#include <pthread.h>


///Executes behaviors in order
/** Executes its children in the order they were added.
If the currently executing child returns BT_FAILURE, BT_ERROR, or BT_RUNNING, this returns the same status.
If the currently executing child returns BT_SUCCESS, this begins executing the next child, if it exists. It continues in this fashion until one of the children returns BT_FAILURE, BT_ERROR, or BT_RUNNING. If all children have successfully executed, it will return BT_SUCCESS.
*/
class BThread
{
public:



    /// construct a BThread
    BThread();
    void Set(BehaviorTree::BEHAVIOR_STATUS* ,BehaviorTree::BehaviorTreeListIter);
    bool isSet();
    bool isSuspended();
    void start();
    void cancel();
    void resume();
    void suspend();
    void kill();
    void *threadRun();
    typedef  void* (BThread::*thread_run_ptr)(void);
    typedef  void* (*bthread_ptr)(void*);

    pthread_t myPthread;
    bool suspended;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    int play;
    thread_run_ptr   t;
    bthread_ptr   p;
    bool is_set;
    int *tick;
    BehaviorTree::BehaviorTreeListIter bt_node_ptr;
    BehaviorTree::BEHAVIOR_STATUS *status_ptr;

};

#endif
