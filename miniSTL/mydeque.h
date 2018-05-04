//
//  mydeque.h
//  miniSTL
//
//  Created by dogrest on 15/9/15.
//  Copyright (c) 2015年 dogrest. All rights reserved.
//

#ifndef miniSTL_mydeque_h
#define miniSTL_mydeque_h
#include "mylist.h"
template <typename T>
class myDeque{
private:
    List<T> Deque_use_list;
public:
    
    //如果有元素，从前面删除
    void pop_front(){
        if(Deque_use_list.IsEmpty()){
            std::cout<<"没有可删除的对象"<<std::endl;
        }else{
            Deque_use_list.deleteListNodeFromHead();
        }
    }
    
    
    //采用尾插发从后面插入数据
    void push_back(T i){
        Deque_use_list.addListNodeFromTail(i);
    }
    void display(){
        Deque_use_list.display();
    }
    T getFront(){
        return Deque_use_list.getfirst()->data;
    }
    bool IsEmpty(){
        return Deque_use_list.IsEmpty();
    }
    int getsize(){
        return Deque_use_list.getsize();
    }
};

#endif
