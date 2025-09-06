#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include "Arduino.h"

class HttpServer
{

public:
    HttpServer();
    void begin();
    void loop();

private:
    void routes();
    // static void handleRoot();
};

#endif