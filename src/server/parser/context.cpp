#include <vector>
#include <memory>

#include "../parser/context.h"

bool Context::validate(){
    // nop
    return true;
}

Context::Context(char* cmd,vector<char*> arg0,vector<char*>  arg1, vector<char*>  arg2){
    this->cmd=cmd;
    this->args0=arg0;
    this->args1=arg1;
    this->args2=arg2;
}

Context::~Context(){
    this->cmd= nullptr;
    this->args0= nullptr;
    this->args1= nullptr;
    this->args2= nullptr;
    free(this->cmd);
    free(this->args0);
    free(this->args1);
    free(this->args2);
}
