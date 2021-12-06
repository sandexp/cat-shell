#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <memory>

#include "../executor/executor.h"
#include "../parser/context.h"

using namespace std;

Executor::Executor(Context* context){
    this->context=context;
}

Executor::~Executor(){
    this->context= nullptr;
    free(this->context);
}

/**
 * @brief 执行执行器中的shell指令 同步执行
 */
void Executor::executor_sync(){
    int child_pid;
    if(fork()==0){
        char* cmd=context->get_command();
        char* args[]=context->get_arg0();
        if(execv(cmd,args)<0){
            perror("Error executed %d.",child_pid);
            exit(0);
        }
    }else{
        wait(&child_pid);
        printf("Successfully execute process %d",child_pid);
    }
}

/**
 * @brief 执行执行器中的shell指令 异步执行
 * 使用fork新建一个子进程, 子进程负责后台执行逻辑
 * 主进程直接返回进程号到控制台。
 */
void Executor::executor_async(){

}

/**
 * @brief 中断指令的执行
 * 异步运行则取消子进程的执行, 否则终止当前进程的进行
 */
void Executor::kill(){

}

/**
 * @brief 执行完成的回调逻辑, 将数据返回控制台
 */
void Executor::onComplete(){

}