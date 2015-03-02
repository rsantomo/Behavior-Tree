#ifndef BEHAVIOR_TREE_H
#define BEHAVIOR_TREE_H

#include <vector>
#include <map>
namespace BehaviorTree
{

    /// Enumerates the states every node can be in after execution during a particular time step
    /**
    - BT_SUCCESS indicates the node has completed running during this time step.
    - BT_FAILURE indicates the node has determined it will not be able to complete its task.
    - BT_RUNNING indicates that the node has successfully moved forward during this time step, but the task is not yet complete.
    */
    enum BEHAVIOR_STATUS {BT_IDLE,BT_SUCCESS,BT_FAILURE,BT_RUNNING};
    #define BT_THRESHOLD  1;

    class BehaviorTreeNode;
    /// A standard vector of Behavior Tree nodes. Provided for convenience.
    typedef std::vector<BehaviorTreeNode*> BehaviorTreeList;
    /// A standard iterator of a BehaviorTreeList. Provided for convenience.
    typedef BehaviorTreeList::iterator BehaviorTreeListIter;

    /// Enumerates the options for when a parallel node is considered to have failed.
    /**
    - FAIL_ON_ONE indicates that the node will return failure as soon as one of its children fails.
    - FAIL_ON_ALL indicates that all of the node's children must fail before it returns failure.

    If FAIL_ON_ONE and SUCEED_ON_ONE are both active and are both trigerred in the same time step, failure will take precedence.
    */
    enum FAILURE_POLICY {FAIL_ON_ONE,FAIL_ON_ALL};
    /// Enumerates the options for when a parallel node is considered to have succeeded.
    /**
    - SUCCEED_ON_ONE indicates that the node will return success as soon as one of its children succeeds.
    - SUCCEED_ON_ALL indicates that all of the node's children must succeed before it returns success.
    */
    enum SUCCESS_POLICY {SUCCEED_ON_ONE,SUCCEED_ON_ALL};


    ///Abstract base clase for Behavior Tree Nodes
    class BehaviorTreeNode
    {
    public:
        /// This method is invoked by the node's parent when the node should be run.
        //virtual BEHAVIOR_STATUS execute() = 0;
        /// This method will be invoked before the node is executed for the first time.
        virtual void init() = 0;
        virtual void tick(BEHAVIOR_STATUS*) = 0;
        virtual void halt(int) = 0;
        virtual void resume() = 0;
        //static void *tick(void*);
        //virtual void execute2(BEHAVIOR_STATUS*, int*) = 0;

    };

    /// Abstract base class for Behavior Tree nodes with children
    class BehaviorTreeControlFlowNode:public BehaviorTreeNode
    {

    public:
        //virtual BEHAVIOR_STATUS execute() = 0;
        //virtual void execute2(BEHAVIOR_STATUS*);
        virtual void init() = 0;
        /// Add a child to this node. Takes ownership of the child.
        virtual BehaviorTreeControlFlowNode* addChild(BehaviorTreeNode* newChild)
        {
            children.push_back(newChild);
            return this;
        };

    protected:
        BehaviorTreeList children;
        ~BehaviorTreeControlFlowNode()
        {
            BehaviorTreeListIter iter;
            for (iter = children.begin(); iter!= children.end(); iter++)
            {
                delete *iter;
            }
        }


    };




    ///Always returns the BT_RUNNING status
    class AlwaysRunning: public BehaviorTreeNode
    {
        BEHAVIOR_STATUS execute()
        {
            return BT_RUNNING;
        }
        void init(){};
    };

    ///Always returns the BT_SUCCESS status
    class AlwaysSuccess: public BehaviorTreeNode
    {
        BEHAVIOR_STATUS execute()
        {
            return BT_SUCCESS;
        }
        void init(void* agent){};
    };

    ///Always returns the BT_FAILURE status
    class AlwaysFailure: public BehaviorTreeNode
    {
        BEHAVIOR_STATUS execute()
        {
            return BT_FAILURE;
        }
        void init(void* agent){};
    };
}
#endif
