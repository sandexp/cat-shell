#include <stdio.h>
#include <sys/types.h>
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
void Executor::execute(){
    int child_pid=fork();
    if(child_pid<0){
        perror("Fork failed.");
        exit(1);
    }
    if(child_pid==0){
        // 子进程
        char* cmd=context->get_command();
        char* args[]=context->get_arg0();
        if(execl(cmd,args)<0){
            perror("Error executed %d.",child_pid);
            exit(0);
        }else{
           // TODO 重定向输出到控制台中
            onComplete();
        }
    }else{
        // 父进程等待子进程执行完毕
        wait(&child_pid);
        printf("Successfully execute process %d",child_pid);
    }
}

/**
 * @brief 中断指令的执行
 * 异步运行则取消子进程的执行, 否则终止当前进程的进行
 */
void Executor::kill(){
    abort();
}

/**
 * @brief 执行完成的回调逻辑, 将数据返回控制台
 */
void Executor::onComplete(){

}