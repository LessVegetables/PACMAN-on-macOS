#pragma once
#include <iostream>
#ifdef _WIN32
    #include <conio.h>
    #include <Windows.h>
    #include <Winuser.h>
#else
// UNIX-like code (macOS and Linux)
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


using namespace std;


struct point{

    int i, j;

};

point operator+(point a, point b){
    point tmp;
    tmp.i=a.i+b.i;
    tmp.j=a.j+b.j;
    return tmp;
}

point operator-(point a, point b){
    point tmp;
    tmp.i=a.i-b.i;
    tmp.j=a.j-b.j;
    return tmp;
}

point operator*(point a, int k){
    point tmp;
    tmp.i=a.i*k;
    tmp.j=a.j*k;
    return tmp;
}


point operator/(point a, int k){
    point tmp;
    tmp.i=a.i/k;
    tmp.j=a.j/k;
    return tmp;
}

bool operator==(point a, point b){
    return (a.i==b.i && a.j==b.j);
}

bool operator!=(point a, point b){
    return (a.i!=b.i || a.j!=b.j);
}