#include "BThread.h"

namespace BehaviorTree
{
///Executes behaviors in order
/** Executes its children in the order they were added.
If the currently executing child returns BT_FAILURE, BT_ERROR, or BT_RUNNING, this returns the same status.
If the currently executing child returns BT_SUCCESS, this begins executing the next child, if it exists. It continues in this fashion until one of the children returns BT_FAILURE, BT_ERROR, or BT_RUNNING. If all children have successfully executed, it will return BT_SUCCESS.
*/
class SequenceNode:public BehaviorTreeControlFlowNode
{
public:
    /// construct a SequenceNode
    SequenceNode();
   // BEHAVIOR_STATUS execute();
    //void execute2(BehaviorTree::BEHAVIOR_STATUS*, int*);
    void init();
    void tick(BehaviorTree::BEHAVIOR_STATUS*);
    void halt(int child_index);
    void resume();
    //void *PrintHello(void);
    /// Where the SequenceNode currently is executing. -1 indicates the SequenceNode is not executing any child.
    ///
    private:
	int currentPosition;
    BThread *child_thread;
    bool is_active;
    BEHAVIOR_STATUS *child_status;
    BehaviorTreeListIter iter2;


};


}
