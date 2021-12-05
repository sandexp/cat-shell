#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <sys/time.h>

using namespace std;

int init_unix_socket(const char* unix_sock_path){
    int sockfd=socket(PF_UNIX, SOCK_STREAM, 0);

}

int init_tcp_socket(){

}


int main(int argc,char* args[]){

}
