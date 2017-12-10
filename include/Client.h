//
// Created by or on 07/12/17.
//

#ifndef UNTITLED_CLIENT_H
#define UNTITLED_CLIENT_H


#include "Cell.h"

class
Client
{
public:
    Client(const char* serverIP, int serverPort);
    void connectToServer();
    void sendExercise(char* arg1);
    Cell* readFromServer();
    int firstReadFromServer();
private:
    const char* serverIP;
    int serverPort;
    int clientSocket;
};
#endif //UNTITLED_CLIENT_H
