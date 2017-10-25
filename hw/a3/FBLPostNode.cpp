#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPostNode.h"

FBLPostNode::FBLPostNode(){
    data = nullptr;
    next = nullptr;
}

FBLPostNode::FBLPostNode(FBLPost* fbp){
    data = fbp;
    next = nullptr;
}

FBLPostNode::~FBLPostNode() {
    if(next) delete next;
    if(data) delete data;
}

FBLPost* FBLPostNode::get_data(){
    return data;
}

FBLPostNode* FBLPostNode::get_next(){
    return next;
}

void FBLPostNode::set_data(FBLPost* fbp){
    data = fbp;
}

void FBLPostNode::set_next(FBLPostNode* fbn){
    next = fbn;
}
