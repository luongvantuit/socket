# __Programming Socket__

## __Win32__

- __Library `"winsock2.h"`__

- __TCP__

- __Client__

    - Initialization Socket client 

    ```cpp
    iRc = WSAStartup(MAKEWORD(2,2),&wsaData);
    SOCKET sk = socket(AF_INET,SOCK_STREAM,0);
    ```

    - Connect to Socket server, wait accept

    ```cpp
    rAddr.sin_family = AF_INET;
    rAddr.sin_addr.s_addr= inet_addr("127.0.0.1");
    rAddr.sin_port = htons(1024);
    iRc = connect(sk,(LPSOCKADDR)&rAddr,sizeof(rAddr));
    ```

    - Send message to server 

    ```cpp
    printf("Message: ");
    gets(buffer);
    iRc = send(sk,buffer,strlen(buffer),0);
    ```

    - Close connect & clean up asset

    ```cpp
    closesocket(sk);
    WSACleanup();
    ```

- __Server__

    - Initialization Socket

    ```cpp
    iRc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET ssk = socket(AF_INET, SOCK_STREAM, 0);
    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serAddr.sin_port = htons(1024); 
    ```

    - Bind & accept connect from client 

    ```cpp
    iRc = bind(ssk, (LPSOCKADDR)&serAddr, sizeof(serAddr));
    iRc = listen(ssk, 5);
    adsize = sizeof(cliAddr);
    SOCKET sk = accept(ssk, (LPSOCKADDR)&cliAddr, &adsize);
    ```

    - Receive & read data from client 

    ```cpp
    iRc = recv(sk, buffer, 256, 0);
    if (iRc == SOCKET_ERROR)
        printf("Cound not receive data from server.\n");
    else
    {
        buffer[iRc] = 0;
        printf("Message from client: %s\n", buffer);
    }
    ```

    - Close & clean up asset 

    ```cpp
    closesocket(sk);
    closesocket(ssk);
    WSACleanup();
    ```
