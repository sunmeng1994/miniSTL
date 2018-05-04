//
//  mystack.h
//  miniSTL
//
//  Created by dogrest on 15/9/15.
//  Copyright (c) 2015年 dogrest. All rights reserved.
//

#ifndef miniSTL_mystack_h
#define miniSTL_mystack_h
#include"mylist.h"
template <typename T>
class myStack{
protected:
    List<T> stack_use_list;
public:
    void pop(){
        stack_use_list.deleteListNodeFromHead();
    }
    bool IsEmpty(){
        return stack_use_list.IsEmpty();
    }
    size_t getSize(){
        return stack_use_list.getsize();
    }
    void push(T i){
        stack_use_list.addListNodeFromHead(i);
    }
    void display(){
        stack_use_list.display();
    }
    T gettop(){
        return (stack_use_list.getfirst())->data;
    }
};

#endif
