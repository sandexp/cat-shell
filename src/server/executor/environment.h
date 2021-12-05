#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "./executor.h"

class Environment {

    private:
        std::unordered_map<char*,Executor> executor_map;
        std::unordered_set<char*>   path_map;
        bool is_running;
    
    public:
        Environment();
        ~Environment();
    
    public:
        void start();
        void stop();
        void load_from_path(char* path);
        void load_from_paths(std::vector<char*> paths);
        Executor* fetch_executor(char* cmd_name);
        void addExecutor(Executor* executor);
    
    /**
     * @brief 动态处理配置变化
     */
    public:
        void onPathAdded(char* path);
        void onPathDelete(char* path);
}