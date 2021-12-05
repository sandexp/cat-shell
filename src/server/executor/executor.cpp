#include <stdio.h>

#include "../executor/executor.h"
#include "../parser/context.h"

using namespace std;


Executor::Executor(Context* context){
    
}

Executor::~Executor(){

}

/**
 * @brief 执行执行器中的shell指令 同步执行
 */
void Executor::executor_sync(){

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