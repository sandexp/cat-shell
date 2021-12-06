#include <stdio.h>
#include <unistd.h>
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
    pid_t pid;
    pid=fork();
}

/**
 * @brief 执行执行器中的shell指令 异步执行
 */
void Executor::executor_async(){

}

/**
 * @brief 中断指令的执行
 */
void Executor::kill(){

}

/**
 * @brief 执行完成的回调逻辑, 将数据返回控制台
 */
void Executor::onComplete(){

}