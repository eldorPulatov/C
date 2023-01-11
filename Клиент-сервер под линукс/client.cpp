#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <unistd.h> 

#include <cstdio>

#include <iostream>
#include <sstream>
#include <fstream>
#include <thread>

#define PORT 8080
#define SA struct sockaddr 

const int LIMIT = 80;

class potok1
{


private:
    std::string a;
    unsigned int size_a;
    std::ofstream filestr = std::ofstream("text.txt");
public:
    void get_string();
    void sortStr();
    void strToKB();
    void strToFile();
};
class potok2
{
private:
    std::string b;
    char buff[LIMIT];
    unsigned int size_buff;
    int sum;
public:
    void getStrFromFile();
    void getSumm();
    void sendToprogram2(int sockfd);
};


int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");


    potok1 t1;
    potok2 t2;
    char Ok;
    do {
        t1.get_string();
        t1.sortStr();
        t1.strToKB();
        t1.strToFile();
        t2.getStrFromFile();
        t2.getSumm();
        t2.sendToprogram2(sockfd);
        std::cout << "Do it again?(y/n): ";
        std::cin >> Ok;
    } while (Ok == 'y');
 
    char ch[LIMIT] = "exit";
    write(sockfd, ch, sizeof(ch));

    close(sockfd);
}

void potok1::get_string()
{
    int k = 1;
    while (k != 0) {
        std::cout << "Input str: ";
        std::cin >> a;
        size_a = a.size();
        if (size_a > 64)
            std::cout << "Error! size < 64" << std::endl;
        else {
            for (const auto& i : a)
                if (i < 48 || i > 57) {
                    std::cout << "Error! Just numbers!" << std::endl;
                    k = 1;
                    break;
                }
                else
                    k = 0;
        }
    }
}

void potok1::sortStr()
{
    char q;
    for (auto& i : a)
        for (auto& j : a)
            if (i > j) {
                q = j;
                j = i;
                i = q;
            }
}

void potok1::strToKB()
{
    std::string b;
    for (auto& i : a)
        if (i % 2 == 0)
            b += "KB";
        else
            b += i;
    this->a = b;
}

void potok1::strToFile()
{
    if (filestr.is_open()) {
        filestr << a;
        filestr.close();
    }
    else {
        filestr.open("./text.txt");
        filestr << a;
        filestr.close();
    }
}

void potok2::getStrFromFile()
{
    std::ifstream fin("./text.txt");
    fin >> b;
    fin.close();
    std::ofstream clearfile = std::ofstream("./text.txt");
    clearfile.close();
}

void potok2::getSumm()
{
    sum = 0;
    for (auto& i : b) {
        if (i > 47 && i < 58) {
            sum += i - '0';
        }
    }
}

void potok2::sendToprogram2(int sockfd)
{
    bzero(buff, sizeof(buff));
    sprintf(buff, "%d", sum);
    write(sockfd, buff, sizeof(buff));
}
