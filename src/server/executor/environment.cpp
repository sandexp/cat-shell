#include <stdio.h>
#include <dirent.h>

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "../executor/executor.h"
#include "../executor/environment.h"

Environment::Environment(){

}

Environment::~Environment(){

}

void Environment::start(){
    static_assert(!this->is_running);
    this->is_running= true;
}

void Environment::stop(){
    static_assert(this->is_running);
    this->is_running= false;
}

void Environment::load_from_path(char* path){


}

void Environment::load_from_paths(std::vector<char*> paths){
    for (int i = 0; i < paths.size(); ++i) {
        load_from_path(paths[i]);
    }
}

Executor* Environment::fetch_executor(char* cmd_name){
    return this->executor_map[cmd_name];
}

void Environment::addExecutor(Executor* executor){

}

void Environment::onPathDelete(char* path){

}

void Environment::onPathAdded(char* path){
    
}

