#include <winsock2.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

    // Initialization variables
    WSADATA wsaData;
    SOCKADDR_IN serAddr, cliAddr;
    int iRc;
    int adsize;
    char buffer[256];

    // Initialization socket server
    iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serAddr.sin_port = htons(1024);

    // Bind & listen accept connect
    iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr));
    iRc = listen(ssk, 5);
    adsize = sizeof(cliAddr);
    SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);

    // Receive data from client
    iRc = recv(sk, buffer, 256, 0);
    if (iRc == SOCKET_ERROR)
        printf("Cound not receive data from server.\n");
    else
    {
        buffer[iRc] = 0;
        printf("Message from client: %s\n", buffer);
    }

    // Close socket clear assets
    closesocket(sk);
    closesocket(ssk);
    WSACleanup();

    return 0;
}
