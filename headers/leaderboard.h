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

#include "variables.h"

using namespace std;

string space_suf_del(string s){
    int k=s.size();
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==' '){
            k=i;
        }
        else{
            break;
        }
    }
    s=s.substr(0, k);
    return s;
}

void leader_board(string p_name){
    #ifdef _WIN32
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE) );
    #else
        tcflush(STDIN_FILENO, TCIFLUSH);
    #endif
    ifstream fin;
    
    fin.open("leaderboard.txt");
    
    
    
    vector< pair< long long, string >  > results;
    string s;
    while(getline(fin, s)){
        string name;
        long long score;
        string rev=s;
        reverse(rev.begin(), rev.end());
        #ifdef _WIN32
            auto tm=rev.find(' ');
            if(tm==std::string::npos) continue;
            int ind_sp=s.size()-tm-1;
        #else
            auto a=rev.find(' ');
            if(a==std::string::npos) continue;
            int ind_sp=s.size()-a-1;
        #endif
        name=s.substr(0, ind_sp);
        cout<<ind_sp<<" "<<name<<endl;
        try{
            try{
                score=stoll(s.substr(ind_sp+1, s.size()-ind_sp-1));
            }
            catch(std::out_of_range){
                continue;
            }
            
        } catch( std::invalid_argument ){
            continue;
        }
        
        results.push_back({score, name});

    }
    fin.close();
    results.push_back( {curscore, p_name} );

    vector< pair< long long, string >  > results_tmp;

    for(int i=0; i<results.size(); i++){
        string tmstr=results[i].second;
        if(tmstr.size()>=3 && tmstr.substr( tmstr.size()-3, 3 ) == "..." ){
            tmstr=tmstr.substr(0, tmstr.size()-3);
        }
        tmstr=space_suf_del(tmstr);
        results[i].second=tmstr;
        if(results[i].second.size()!=0){
            results_tmp.push_back(results[i]);
        }
    }

    results=results_tmp;
    

    sort( results.begin(), results.end(), greater<pair<long long, string> >() );
    int n=results.size();

    ofstream fout;
    fout.open("leaderboard.txt");
    lbsize=min(lbsize, n);
    for(int i=0;i<lbsize; i++ ){
        lbscore.push_back( {results[i].second, results[i].first} );
        fout<<results[i].second<<" "<<results[i].first<<'\n';
    }
    fout.close();
    return;
    
}