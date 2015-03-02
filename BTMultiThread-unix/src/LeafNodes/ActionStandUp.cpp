#include "ActionStandUp.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <cstddef>
#include <ctime>

//#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/altexttospeechproxy.h>

using namespace BehaviorTree;
using namespace std;




ActionStandUp::ActionStandUp()
{
    //const std::string robot_ip = "192.168.0.196";
    //posture_proxy_ptr = new AL::ALRobotPostureProxy(NAO_IP, 9559);
    speech_proxy_ptr = new AL::ALTextToSpeechProxy(NAO_IP, 9559);
    behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(NAO_IP, 9559);

    //speech_rec_proxy_ptr = new AL::ALSpeechRecognitionProxy(NAO_IP, 9559);



}
void ActionStandUp::init()
{
    std::cout << "\033[1;31m ActionStandUp Initialized\033[0m " << std::endl;
}

void ActionStandUp::halt(int i){
    std::cout << "StandUp Halted " << std::endl;

    behavior_proxy_ptr->stopBehavior("stand_up");

}
void ActionStandUp::tick(BehaviorTree::BEHAVIOR_STATUS *status_ptr){
   *status_ptr = BT_RUNNING;


        speech_proxy_ptr->say("OK, I'm gonna stand up");
        behavior_proxy_ptr->runBehavior("stand_up");
        speech_proxy_ptr->say("What do you want me to do");

        *status_ptr = BT_SUCCESS;

        while(1){
            sleep(0.1);
        }

}


