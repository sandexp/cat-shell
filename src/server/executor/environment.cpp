#include <stdio.h>

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

}

void Environment::stop(){

}

void Environment::load_from_path(char* path){

}

void Environment::load_from_paths(std::vector<char*> paths){

}

Executor* Environment::fetch_executor(char* cmd_name){

}

void Environment::addExecutor(Executor* executor){

}

void Environment::onPathDelete(char* path){

}

void Environment::onPathAdded(char* path){
    
}

