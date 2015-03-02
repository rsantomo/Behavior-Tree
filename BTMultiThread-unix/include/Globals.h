#ifndef global_H
#define global_H
#include <iostream>
#include <alerror/alerror.h>
#include <pthread.h>


extern const std::string NAO_IP;
extern std::string activity_name;
extern bool activity_name_locked;
extern pthread_mutex_t aPass_lock;
#endif
