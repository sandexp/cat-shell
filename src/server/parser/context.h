#include <vector>

class Context {
    public:
        ~Context();
        Context(char* cmd,char* arg0,char* arg1, char* arg2);
    
    private:
        char *cmd;
        vector<char*> args0;
        vector<char*> args1;
        vector<char*> args2;
    
    public:
        bool validate();
}