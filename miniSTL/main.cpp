//
//  main.cpp
//  miniSTL
//
//  Created by dogrest on 15/9/15.
//  Copyright (c) 2015年 dogrest. All rights reserved.
//

#include <iostream>
#include "myvector.h"
#include "mystack.h"
#include "mydeque.h"
#include "AVL.h"

int main(int argc, const char * argv[]) {
    using namespace std;
    cout<<"**************************"<<endl;
    cout<<"     #vector test# "<<endl;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    myVector<int>array1;
    for(auto i:a){
        array1.push_back(i);
    }
    myVector<int>array2;
    array2=array1;
    for(int i=0;i<array1.size();i++){
        cout<<array2[i];
    }
    cout<<endl;
    cout<<"****************************"<<endl;
    cout<<"     #list test#            "<<endl;
    List<int>*list1=new List<int>;
    for(int i=0;i<9;i++){
        (*list1).addListNodeFromHead(i);
    }
    (*list1).display();
    cout<<"使用下标输出一个值"<<endl;
    cout<<(*list1)[0]<<endl;
    delete list1;
    cout<<"****************************"<<endl;
    cout<<"    #stack test#            "<<endl;
    myStack<int>*stack1=new myStack<int>;
    for(int i=0;i<9;i++){
        (*stack1).push(i);
    }
    cout<<"输出栈的顶端，然后弹出，知道栈为空"<<endl;
    while (!(*stack1).IsEmpty()) {
        int i=(*stack1).gettop();
        cout<<i<<" ";
        (*stack1).pop();
        }
    delete stack1;
    cout<<endl;
    cout<<"*****************************"<<endl;
    cout<<"        #deque test#         "<<endl;
    myDeque<int>*deque1=new myDeque<int>;
    for(int i=50;i<60;i++){
        (*deque1).push_back(i);
    }
    while (!(*deque1).IsEmpty()) {
        cout<<(*deque1).getFront()<<" ";
        (*deque1).pop_front();
    }
    delete deque1;
    cout<<endl;
    cout<<"******************************"<<endl;
    cout<<"      #avlmap test#"<<endl;
    Tree<char, int>*map1=new Tree<char, int>;
    char c[]={'a','c','d','e','f','a','g'};
    for(char i:c){
        (*map1)[i];
        (*map1)[i]->val+=1;
    }
    (*map1).InOrderTraverse();
    return 0;
}
