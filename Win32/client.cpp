#include <winsock2.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Initialization variables
    WSADATA wsaData;
    SOCKADDR_IN rAddr;
    char buffer[20];
    int iRc;

    // Initialization Socket
    iRc = WSAStartup(MAKEWORD(2,2),&wsaData);
    SOCKET sk = socket(AF_INET,SOCK_STREAM,0);

    // Initialization connect to server
    rAddr.sin_family = AF_INET;
    rAddr.sin_addr.s_addr= inet_addr("127.0.0.1");
    rAddr.sin_port = htons(1024);
    iRc = connect(sk,(LPSOCKADDR)&rAddr,sizeof(rAddr));

    // Enter msg & send to server
    printf("Message: ");
    gets(buffer);
    iRc = send(sk,buffer,strlen(buffer),0);

    // Close connect Socket
    closesocket(sk);
    WSACleanup();

    return 0;

}
