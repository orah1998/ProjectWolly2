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
using namespace std;
Client::Client(const char* serverIP, int serverPort):
        serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
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





void Client::sendExercise(char* arg1) {
// Write the exercise arguments to the socket
int n = write(clientSocket, &arg1, sizeof(arg1));
if (n == -1) {
throw "Error writing arg1 to socket";
}

// Read the result from the server
}


Cell* Client::readFromServer() {
    string result;
    int n = read(clientSocket, &result, sizeof(result));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    Cell c=Cell(0,0);
    c.StringToCell(result);
    return &c;
}

