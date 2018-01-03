//
// Created by or on 07/12/17.
//

#include <sys/socket.h>
#include "../include/Client.h"
#include "../include/Client.h"
#include "../include/Cell.h"
#include <iostream>
#include<sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#define SIZEOF 2000
using namespace std;


Client::Client(){
    //defining a new client
    std::ifstream file("../src/client_definitions");
    string ip;
    int port;
    file >> ip;
    file >> port;
    const char* ip2=ip.c_str();
    this->serverPort=port;
    this->serverIP=ip2;
    this->clientSocket=0;
}

Client::Client(const char* serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
}
void Client::connectToServer() {
// Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM,0);
    if (clientSocket== -1) {
        throw "Error opening socket";
    }

// Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }


// Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
//htons converts values between host and network byte orders
    serverAddress.sin_port=htons(serverPort);
//Establish a connection with the TCP server

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) ==-1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
}

void Client::sendExercise(char move[]) {
// Write the exercise arguments to the socket
    cout<<"sending"<<endl;
    cout<<move<<endl;
    int n = write(clientSocket, move, SIZEOF);
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
}


int Client::startGame(){
    int start;
    int n = read(clientSocket, &start, sizeof(int));
    return start;
}


Cell Client::readFromServer() {
    char result[SIZEOF];
    int n = read(clientSocket, result, SIZEOF);
    if (n == -1) {
        throw "Error reading result from socket";
    }
    cout << " the point is : " << result << endl;

    stringstream str(result);

    string x;
    str >> x;

    string y;
    str >> y;

    stringstream str2(x);
    stringstream str3(y);
    int indexX = 0;
    int indexY = 0;
    str2 >> indexX;
    str3 >> indexY;

    Cell c = Cell(indexX, indexY);

    return c;
}


int Client::firstReadFromServer() {

    cout << "choose command" << endl;
    char result[SIZEOF];
    char command[SIZEOF];
    char y[SIZEOF];
    stringstream str(command);
//x is the command
    char x[SIZEOF];
    cin >> x;
    strcat(command, x);
if(strcmp(x,"list_games")!=0) {
    //y is the name (etc)
    cin >> y;
    strcat(command, " ");
    strcat(command, y);
}else{
    strcat(command, " ");
    strcat(command,"2");
}
    do {
        if (strcmp(x, "join") == 0) {
            long n = write(clientSocket, &command, SIZEOF);
            if(n<=0){
                throw "exit";
            }
            cout << "you chose join" << endl;
            return 1;

        }

        if (strcmp(x, "start") == 0) {
            long n = write(clientSocket, &command, SIZEOF);
            if(n<=0){
                throw "exit";
            }
            cout << "you chose start" << endl;
            return 0;
        }


        if (strcmp(x, "list_games") == 0) {
            int n = write(clientSocket, &command, sizeof(command));
            if(n<=0){
                throw "exit";
            }
            n = read(clientSocket, result, sizeof(command));
            if(n<=0){
                throw "exit";
            }
            cout << result << endl;
        }

        cout << "choose your command" << endl;
        string result;
        char command[SIZEOF];

        stringstream str(command);
//x is the command
        char xi[SIZEOF];
        cin >> xi;
        strcpy(x,xi);
        strcpy(command, x);
        if(strcmp(x,"list_games")!=0) {
            //y is the name (etc)
            char yi[SIZEOF];
            cin >> yi;
            strcpy(y, yi);
            strcat(command, " ");
            strcat(command, y);
        }else{
            strcat(command, " ");
            strcat(command,"2");
        }


    } while (true);
}





