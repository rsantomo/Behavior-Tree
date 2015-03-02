#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include "BehaviorTree.h"
#include "Globals.h"
#include "SequenceNode.h"
#include "SelectorNode.h"
#include "ParallelNode.h"
#include "ActionTest.h"
#include "ActionTest2.h"


#include "ActionStandUp.h"
#include "ConditionBumperPressed.h"
#include "ActionCrouch.h"
#include "ActionMoveTo.h"
#include "ActionSayWhatYouWant.h"
#include "ActionSetActivity.h"
#include "ActionCome.h"
#include "ActionSleep.h"

#include "ConditionIsActivityMove.h"
#include "ConditionIsActivityStand.h"
#include "ConditionIsActivityCrouch.h"
#include "ConditionIsActivitySleep.h"
#include "ConditionIsActivityCome.h"

#include "ConditionKnowsActivity.h"
#include <alproxies/alspeechrecognitionproxy.h>

//#include <gtkmm.h>



using namespace std;
using namespace BehaviorTree;

#define NUM_THREADS     5




struct thread_data{
   int  thread_id;
   char *message;
};


int main (int argc, char* argv[])
{

 /*   Gtk::Main kit(argc,argv);
    Gtk::Window window;

    window.set_default_size(640,480);
    window.set_title("Prova");
    window.set_position(Gtk::WIN_POS_CENTER);
    Gtk::Main::run(window);
*/

    //const std::string NAO_IP = "192.168.0.196";

  //  AL::ALSpeechRecognitionProxy* speech_rec_proxy_ptr = new AL::ALSpeechRecognitionProxy(NAO_IP, 9559);
 //   AL::ALTextToSpeechProxy* speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, 9559);

 //speech_rec_proxy_ptr->unsubscribe("LastWordRecognized");


   BEHAVIOR_STATUS seq_node_1_status;
   BehaviorTree::SequenceNode* seq_node_1 = new BehaviorTree::SequenceNode();
   BehaviorTree::SequenceNode* seq_node_1bis = new BehaviorTree::SequenceNode();
   BehaviorTree::SequenceNode* seq_node_2 = new BehaviorTree::SequenceNode();
   BehaviorTree::SequenceNode* seq_node_3 = new BehaviorTree::SequenceNode();
   BehaviorTree::SequenceNode* seq_node_4 = new BehaviorTree::SequenceNode();
   BehaviorTree::SequenceNode* seq_node_5 = new BehaviorTree::SequenceNode();
   BehaviorTree::SequenceNode* seq_node_6 = new BehaviorTree::SequenceNode();



   BehaviorTree::SelectorNode* sel_node_1 = new BehaviorTree::SelectorNode();
   BehaviorTree::SelectorNode* sel_node_2 = new BehaviorTree::SelectorNode();

   BehaviorTree::ParallelNode* par_node_1 = new BehaviorTree::ParallelNode(FAIL_ON_ALL,SUCCEED_ON_ALL);
   BehaviorTree::ParallelNode* par_node_2 = new BehaviorTree::ParallelNode(FAIL_ON_ALL,SUCCEED_ON_ALL);

/*
   ActionTest* Action_1 = new ActionTest();
   ActionTest2* Action_2 = new ActionTest2(2);
   ActionTest2* Action_3 = new ActionTest2(3);
   ActionStandUp* StandUp = new ActionStandUp();
   ActionCrouch* Crouch = new ActionCrouch();
   ActionMoveTo* MoveTo = new ActionMoveTo();
   ActionSayWhatYouWant* SayWhat = new ActionSayWhatYouWant();
   ActionSetActivity* SetActivity = new ActionSetActivity();
   ActionCome* Come = new ActionCome();
   ActionSleep* Sleep = new ActionSleep();



   ConditionKnowsActivity* Knows = new ConditionKnowsActivity();
   ConditionIsActivityStand* IsStand = new ConditionIsActivityStand();
   ConditionIsActivityCrouch* IsCrouch = new ConditionIsActivityCrouch();
   ConditionIsActivitySleep* IsSleep = new ConditionIsActivitySleep();
   ConditionIsActivityMove* IsMove = new ConditionIsActivityMove();
   ConditionIsActivityCome* IsCome = new ConditionIsActivityCome();


   ConditionBumperPressed* BumperPressed = new ConditionBumperPressed();

*/

   ConditionBumperPressed* BumperPressed = new ConditionBumperPressed();
   ActionMoveTo* MoveTo = new ActionMoveTo();
   ActionCrouch* Crouch = new ActionCrouch();


   ConditionBumperPressed* BumperPressed2 = new ConditionBumperPressed(9560);
   ActionMoveTo* MoveTo2 = new ActionMoveTo(9560);
   ActionCrouch* Crouch2 = new ActionCrouch(9560);



   BEHAVIOR_STATUS status_ptr = BT_IDLE;
  // ActionStandUp* StandUp = new ActionStandUp();

   sel_node_1->addChild(BumperPressed);
   sel_node_1->addChild(MoveTo);
   seq_node_1->addChild(sel_node_1);
   seq_node_1->addChild(Crouch);

   seq_node_1->init();



   sel_node_2->addChild(BumperPressed2);
   sel_node_2->addChild(MoveTo2);
   seq_node_2->addChild(sel_node_2);
   seq_node_2->addChild(Crouch2);

   seq_node_2->init();

  // seq_node_1->tick(&status_ptr);

   seq_node_2->tick(&status_ptr);





   cout << " Done  " << endl;

/*
   seq_node_1->addChild(BumperPressed);
   seq_node_1->addChild(MoveTo);
   sel_node_1->addChild(seq_node_1);
   sel_node_1->addChild(Crouch);



   cout << " Initializing the tree  " << endl;

   sel_node_1->init();

   cout << " Starting  " << endl;
   sel_node_1->tick(&status_ptr);

   cout << " Seq return status : " << seq_node_1_status << endl;
*/

/*


   sel_node_1->addChild(Knows);
   sel_node_1->addChild(SayWhat);

   seq_node_1->addChild(IsStand);
   seq_node_1->addChild(StandUp);

   seq_node_2->addChild(IsCrouch);
   seq_node_2->addChild(Crouch);

   seq_node_3->addChild(IsSleep);
   seq_node_3->addChild(Sleep);

   seq_node_4->addChild(IsCome);
   seq_node_4->addChild(Come);

   seq_node_5->addChild(BumperPressed);
   seq_node_5->addChild(MoveTo);

   par_node_1->addChild(seq_node_5);
   par_node_1->addChild(seq_node_1);
   par_node_1->addChild(seq_node_2);
   par_node_1->addChild(seq_node_3);
   par_node_1->addChild(seq_node_4);
   par_node_1->addChild(seq_node_4);
   par_node_1->addChild(IsMove);

   seq_node_6->addChild(sel_node_1);
   seq_node_6->addChild(par_node_1);

   sel_node_2->addChild(seq_node_5);
   sel_node_2->addChild(par_node_1);

   par_node_2->addChild(par_node_1);
   par_node_2->addChild(SetActivity);

   cout << " Initializing the tree  " << endl;
   sleep(2);
   speech_proxy_ptr->say("What do you want me to do");

   par_node_2->init();
   cout << " Starting  " << endl;
   par_node_2->tick(&status_ptr);


   cout << " Seq return status : " << seq_node_1_status << endl;



*/
}
