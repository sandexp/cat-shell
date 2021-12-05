#include <vector>


class Context {
    public:
        ~Context();
        Context(char *input);
    
    private:
        char *cmd;
        vector<char*> args0;
        vector<char*> args1;
        vector<char*> args2;
    
    public:
        bool validate();
}