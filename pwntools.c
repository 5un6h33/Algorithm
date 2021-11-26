#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<string.h>
#define PORT 3006

void recv_data(int sock, char *buffer, int len)
{
    int valread;

    valread = read(sock, buffer, len);

    while (valread != 0)
    {
        printf("%s", buffer);
        valread = read(sock, buffer, len);
    }
}

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    struct in_addr **addr_list;
    struct hostent *he;
    char *hostname = "ctf.j0n9hyun.xyz";
    char ip[100];
    char cmd[1024] = {0};
    char *msg = "Hello World!\n";
    char buffer[1024] = {0};

    if((he = gethostbyname(hostname)) == NULL)
    {
        printf("\n[-] Hostname Error \n");
        return -1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for(int i = 0; addr_list[i] != NULL; i++)
        strcpy(ip, inet_ntoa(*addr_list[i]));
    
    // printf("%s resolved to : %s", hostname, ip);

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n[-] Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0)
    {
        printf("\n[-] Invalid address or Address not supported\n");
        return -1;
    }

    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\n[-] Connection Failed\n");
        return -1;
    }

    // valread = read(sock, buffer, 1024);
    // printf("%s", buffer);
    // send(sock, msg, strlen(msg), 0);
    // valread = read(sock, buffer, 1024);
    // printf("%s", buffer);
    // valread = read(sock, buffer, 1024);
    // printf("%s", buffer);
    recv_data(sock, buffer, 1024);

    while(1)
    {
        puts("hi");
        scanf("$ %s", cmd);
        send(sock, cmd, strlen(cmd), 0);
        valread = read(sock, buffer, 1024);
        sleep(1);
        printf("%s", buffer);
    }

    return 0;
}