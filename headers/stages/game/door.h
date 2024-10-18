#pragma once
#include <iostream>
#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
    #include <Winuser.h>
#else
// UNIX-like code (macOS and Linux)
    #include <ncurses.h>
    #include <unistd.h>
#endif
#include <time.h>
#include <thread>
#include <string>
#include <queue>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <random>
#include <fstream>

#include "../../point.h"
#include "../../variables.h"

using namespace std;







void dopen(){
    for(int j=11;j<=16;j++) arr[12][j]=0;
}

void dclose(){
    for(int j=11;j<=16;j++) arr[12][j]=1;
}

void door_time(){
    while(gameContinue){

        dopen();
        #ifdef _WIN32
            Sleep(dop);
        #else
            usleep(dop*1000);
        #endif
        if(curtime<cycle*3) curtime+=dop;
        
        dclose();
        #ifdef _WIN32
            Sleep(dcl);
        #else
            usleep(dcl*1000);
        #endif
        if(curtime<cycle*3) curtime+=dcl;



    }
}