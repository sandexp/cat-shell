#include <vector>
#include <memory>
#include <string>

#include "../parser/context.h"

using namespace std;

bool Context::validate(){
    // nop
    return true;
}

Context::Context(string cmd,int argc,char* args[]){
    this->cmd=cmd;
    this->argc=argc;
    for (int i = 0; i < argc; ++i) {
        *(this->args+i)=args[i];
    }
}

Context::~Context(){

}

string Context::get_command() {
    return this->cmd;
}

char* Context::get_arg(int index) {
    return this->args[index];
}

char** Context::get_args() {
    return this->args;
}

/**
 * This method is for test.
 * @return
 */
string Context::toString() {
    string ans="";

    if (cmd.length()!=0){
        ans="Cmd: "+ this->cmd+"\n";
    }else{
        return ans;
    }
    printf("%s\n",ans.c_str());
    for (int i = 1; i < this->argc; ++i) {
        printf("%s\n",args[i]);
        ans+="Args "+std::to_string(i)+" : "+args[i]+"\n";
    }
    return ans;
}