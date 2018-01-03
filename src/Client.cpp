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
    cout<<"123"<<endl;
    cout<<serverIP<<endl;
    cout<<serverPort<<endl;
    cout << "Client"<< endl;
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





void Client::sendExercise(int x,int y) {
// Write the exercise arguments to the socket
int n = write(clientSocket, &x, sizeof(x));
if (n == -1) {
throw "Error writing arg1 to socket";
}

    int n2 = write(clientSocket, &y, sizeof(y));
    if (n2 == -1) {
        throw "Error writing arg1 to socket";
    }

// Read the result from the server
}


Cell Client::readFromServer() {
    string result;
    int n = read(clientSocket, &result, sizeof(result));
    if (n == -1) {
        throw "Error reading result from socket";
    }

    stringstream str(result);
    string command;
    str>> command;

    string x;
    str >> x;

    string y;
    str >> y;



    stringstream str2(x);
    stringstream str3(y);
    int indexX=0;
    int indexY=0;
    str2>>indexX;
    str3>>indexY;

    Cell c=Cell(indexX,indexY);

    return c;
}


int Client::firstReadFromServer() {
    int turn;
    int n = read(clientSocket, &turn, sizeof(int));
    return turn;
}