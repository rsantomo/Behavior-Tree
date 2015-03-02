#include "BehaviorTree.h"
#include "BThread.h"
#include <cstdlib>
#include <unistd.h>
#include <iostream>




   BThread::BThread() {

       pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
       pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

       this->lock = lock2;
       this->cond = cond2;
       play = 0;
       t = &BThread::threadRun;
       p = *(bthread_ptr*)&t;
       is_set = false;
       int *tick;
       suspended = true;
   }


   void BThread::start() {

       suspended = false;
       pthread_create(&myPthread, 0, p, this );

   }

   void BThread::suspend() {
       suspended = true;
   }

   void BThread::kill() {
       pthread_exit(NULL);
   }


    void BThread::Set(BehaviorTree::BEHAVIOR_STATUS* status_ptr,BehaviorTree::BehaviorTreeListIter bt_node_ptr) {
    this->bt_node_ptr = bt_node_ptr;
    this->status_ptr = status_ptr;
    is_set = true;

   }
    void BThread::cancel() {

        // tell the thread to suspend
       /* pthread_mutex_lock(&lock);
        play = 0;
        pthread_mutex_unlock(&lock);*/
        suspended = true;

        while(!suspended){
            sleep(0.1);
        }

        is_set = false;
       // pthread_detach(myPthread);// release memory allocayed for the thread
        int k = 1;
        do{
            k = pthread_cancel(myPthread);
        } while(k!=0);

      //  pthread_join(myPthread, 0);// release memory allocayed for the thread


        //pthread_cleanup_push();
        //pthread_cleanup_pop();
        //kill();


    }

    bool BThread::isSet(){
        return is_set;
    }

    bool BThread::isSuspended(){
        return suspended;
    }

    void BThread::resume() {
         suspended = false;
         (*bt_node_ptr)->resume();
       /* pthread_mutex_lock(&lock);
        play = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);*/
    }

void *BThread::threadRun() {
    suspended = false;

    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
//    std::cout << "Thread Started" << std::endl;
    //this->resume();
       (*bt_node_ptr)->tick(status_ptr);
//TODO add here that we stop the execution if we get failure or success


}
