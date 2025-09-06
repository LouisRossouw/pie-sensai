#ifndef CONNECTION_H
#define CONNECTION_H

#include "../lights/lights.h"

class Connection
{
public:
    Connection(const char *ssid, const char *password, const char *hostname, Lighting *lights);

    void begin();
    void printMac();

    void loop();

private:
    const char *_ssid;
    const char *_password;
    const char *_hostname;
    Lighting *_lights;
};

#endif