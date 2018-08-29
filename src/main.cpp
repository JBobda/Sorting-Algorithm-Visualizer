#include "Application.h"

const uint WIDTH = 800;
const uint HEIGHT = WIDTH * 9 /16;

int main(){
    Application application("Window Title", WIDTH, HEIGHT);
    application.run();
    return 0;
}