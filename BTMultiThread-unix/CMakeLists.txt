project(BTMultiThread)
SET(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread ")




set(CMAKE_PREFIX_PATH ~/naoqi/naoqi-sdk-1.14.5-linux64)
set(LD_LIBRARY_PATH:~/naoqi/naoqi-sdk-1.14.5-linux64/lib)
#add_definitions ("-Wall")

cmake_minimum_required(VERSION 2.8)





INCLUDE_DIRECTORIES(./include)
INCLUDE_DIRECTORIES(~/naoqi/naoqi-sdk-1.14.5-linux64/lib)
INCLUDE_DIRECTORIES(GTKMM_INCLUDE_DIRS)
set(qibuild_DIR ./include/qibuild/build/qibuild/cmake/qibuild)

set(ALPROXIES_DIR /home/michele/naoqi/naoqi-sdk-1.14.5-linux64/share/cmake/alproxies)

set(ALERROR_DIR /home/michele/naoqi/naoqi-sdk-1.14.5-linux64/share/cmake/alerror)
set(ALCOMMON_DIR /home/michele/naoqi/naoqi-sdk-1.14.5-linux64/share/cmake/alcommon)

find_package(qibuild)
find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-2.4)

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )
set(LIB_LIST
./include/BehaviorTree.h
./include/ParallelNode.h
./include/SelectorNode.h
./include/SequenceNode.h
./include/ActionTest.h
./include/ActionTest2.h
./include/BThread.h
./include/ConditionIsActivityCrouch.h
./include/ConditionIsActivitySleep.h
./include/ConditionIsActivityCome.h
./include/ConditionBumperPressed.h
./include/ConditionKnowsActivity.h
./include/ConditionIsActivityStand.h
./include/ConditionIsActivityMove.h
./include/ActionSetActivity.h
./include/ActionSetActivity.h
./include/ActionSetActivity.h
./include/ActionCrouch.h
./include/ActionStandUp.h
./include/ActionCome.h
./include/ActionSleep.h
./include/ActionMoveTo.h
./include/ActionSayWhatYouWant.h
./include/Globals.h
/home/michele/webots/transfer/e-puck/libepuck/include/webots/robot.h
${GTKMM_INCLUDE_DIRS}
)

#set(LIB_LIST ./include/*.h)


aux_source_directory(./src/ SRC_LIST)
aux_source_directory(./src/LeafNodes ACT_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST} ${LIB_LIST})
add_library(mylib ./src/main.cpp ${LIB_LIST})


add_library(gtkm ./src/main.cpp ${GTKMM_INCLUDE_DIRS})


qi_create_bin(BTMultiThread ${SRC_LIST} ${ACT_LIST})

qi_use_lib(BTMultiThread ALCOMMON ALPROXIES)
