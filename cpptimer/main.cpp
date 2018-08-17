//
//  main.cpp
//  cpptimer
//
//  Created by Chris on 2018/8/15.
//  Copyright © 2018年 Chris. All rights reserved.
//

#include <iostream>
#include<iostream>
#include<string>
#include<memory>
#include"timer.hpp"
using namespace std;
void EchoFunc(std::string&& s){
    std::cout << "test : " << s << endl;
}


int main(int argc, const char * argv[]) {
   
    Timer t;
    //周期性执行定时任务
    t.StartTimer(1000, std::bind(EchoFunc,"hello world!"));
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "try to expire timer!" << std::endl;
    t.Expire();
    
    //周期性执行定时任务
    t.StartTimer(1000, std::bind(EchoFunc,  "hello c++11!"));
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << "try to expire timer!" << std::endl;
    t.Expire();
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    //只执行一次定时任务
    //同步
    t.SyncWait(1000, EchoFunc, "hello world!");
    //异步
    t.AsyncWait(1000, EchoFunc, "hello c++11!");
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    return 0;
}
