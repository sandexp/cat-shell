//
// Created by admin on 2021/12/7.
//
#include <stdio.h>

#include <string.h>
#include <vector>
#include <regex>

#include "parser/context.h"
#include "executor/executor.h"
#include "executor/environment.h"

using namespace std;

/**
 * 正则分割函数
 * @param str 源字符串
 * @param delimiter 分隔符
 * @return 分割结果列表
 */
vector<string> split(const string& str, const string& delimiter) {
    vector<string> res;
    if("" == str) return res;
    //先将要切割的字符串从string类型转换为char*类型
    char * strs = new char[str.length() + 1] ; //不要忘了
    strcpy(strs, str.c_str());

    char * d = new char[delimiter.length() + 1];
    strcpy(d, delimiter.c_str());

    char *p = strtok(strs, d);
    while(p) {
        string s = p; //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
    return res;
}

/**
 * 转换为字符数组
 * @param v
 * @return
 */
char** toCharArray(vector<string> v){
    int size=v.size();
    char** ptr;
    for (int i = 1; i < v.size(); ++i) {
        *(ptr+i)=(char*)v[i].c_str();
    }
    return ptr;
}

/**
 * 控制台测试函数
 * @param argc
 * @param argv
 * @return
 */
int main(){

    char options[1024];
    scanf("%[^\n]",options);
    vector<string> params=split(options," ");

    int size=params.size();
    char* args[size];
    for (int i = 0; i < size-1; ++i) {
        args[i]=const_cast<char*>(params[i+1].c_str());
    }
    args[size-1]=NULL;

    string cmd=params[0];
    Context* context=new Context(cmd,size,args);
    //printf("%s\n",context->toString().c_str());
    /**
    Context* context=new Context(cmd,params.size()-1,args);
    Executor* executor=new Executor(context);
     */
    return 0;
}
