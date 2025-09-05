#ifndef CONNECTION_H
#define CONNECTION_H

#include "../lights/lights.h"

class Connection
{
public:
    Connection(const char *ssid, const char *password, const char *hostname);

    void begin();
    void printMac();

private:
    const char *_ssid;
    const char *_password;
    const char *_hostname;
    Lighting *_lights;
};

#endif