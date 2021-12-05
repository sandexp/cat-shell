
#include <stdio.h>
#include "../parser/context.h"


class Executor{

    private:
        Context *context;

    public:
        ~Executor();
        Executor(Context *context);

    public:
        /**
        * @brief 同步执行Shell指令逻辑
        */
        void executor_sync();

        /**
         * @brief 异步执行shell指令逻辑(默认回调)
         */
        void execute_async();
        
        /**
        * @brief kill当前任务
        */
        void kill();


        /**
        * @brief 任务成功时候回调
        */
        void onComplete();
}