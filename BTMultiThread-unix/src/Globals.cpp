#include "Globals.h"

#include <iostream>

const std::string NAO_IP = "127.0.0.1";
std::string activity_name = "STOP";
bool activity_name_locked = false;
pthread_mutex_t aPass_lock;
