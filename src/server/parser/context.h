#ifndef _CONTEXT_H_
#define _CONTEXT_H_
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Context {
    public:
        ~Context();
        Context(string cmd,int argc,char* args[]);

    private:
        string cmd;
        int argc;
        char* args[];

    public:
        bool validate();

        string get_command();

        char* get_arg(int index);

        char** get_args();

        string toString();
};
#endif