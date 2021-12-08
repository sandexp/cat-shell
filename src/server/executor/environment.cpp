#include <stdio.h>
#include <dirent.h>

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "../executor/executor.h"
#include "../executor/environment.h"

using namespace std;

Environment::Environment(){

}

Environment::~Environment(){
    this->is_running= false;
}

void Environment::start(){
    this->is_running= true;
}

void Environment::stop(){
    this->is_running= false;
}

/**
 * 加载指定目录下的指令cmd信息
 * @param path 指令目录
 */
void Environment::load_from_path(char* path){
    DIR* dir;
    struct dirent* dp;
    dir=opendir(path);
    // insert cmd into path map
    while ((dp=readdir(dir))!=NULL){
        this->path_map.insert(dp->d_name);
    }

}

void Environment::load_from_paths(std::vector<char*> paths){
    for (int i = 0; i < paths.size(); ++i) {
        load_from_path(paths[i]);
    }
}

/**
 * Get executor for cmd, if this cmd is not registered, we will init {@see Context} with args.
 * @param cmd_name
 * @param context
 * @return
 */
Executor* Environment::fetch_executor(string cmd_name,int argc,char** args){
    if(this->executor_map.count(cmd_name)!=0){
        return this->executor_map[cmd_name];
    }
    Context* context=new Context(cmd_name,argc,args);
    Executor* executor=new Executor(context);
    this->executor_map[cmd_name]=executor;
    return executor;
}

void Environment::addExecutor(Executor* executor){

}

void Environment::onPathDelete(char* path){

}

void Environment::onPathAdded(char* path){
    
}

