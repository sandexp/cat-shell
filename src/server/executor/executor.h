
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
        void execute();
        
        /**
        * @brief kill当前任务
        */
        void kill();


        /**
        * @brief 任务成功时候回调
        */
        void onComplete();
}