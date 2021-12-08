#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "./executor.h"

using namespace std;

class Environment {

    private:
        unordered_map<string,Executor*> executor_map;
        unordered_set<char*>   path_map;
        bool is_running;
    
    public:
        Environment();
        ~Environment();
    
    public:
        void start();
        void stop();
        void load_from_path(char* path);
        void load_from_paths(std::vector<char*> paths);
        Executor* fetch_executor(string cmd_name,int argc,char** args);
        void addExecutor(Executor* executor);
    
    /**
     * @brief 动态处理配置变化
     */
    public:
        void onPathAdded(char* path);
        void onPathDelete(char* path);
};

#endif