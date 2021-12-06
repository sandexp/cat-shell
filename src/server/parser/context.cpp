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

char* Context::get_command() {
    return this->cmd;
}

std::vector<char*> Context::get_arg0() {
    return this->args0;
}

std::vector<char*> Context::get_arg1() {
    return this->args1;
}

std::vector<char*> Context::get_arg2() {
    return this->args2;
}
