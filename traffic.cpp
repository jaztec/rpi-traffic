#include <wiringPi.h>
#include <iostream>
#include <time.h>

#define GREEN 7
#define YELLOW 2
#define RED 0

#define WALK_RED 4
#define WALK_GREEN 1

#define WALK_BUTTON 30
#define EXIT_BUTTON 21

class TrafficLight
{
    private:
        bool running;
        bool processingPedestrian;

        void listenButtons();
        void processPedestrian();

        void stopTraffic();
        void allowWalk();
        void startTraffic();

    public:
        TrafficLight();
        ~TrafficLight();
        void run();
                
};

TrafficLight::TrafficLight()
{
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(WALK_RED, OUTPUT);
    pinMode(WALK_GREEN, OUTPUT);
    pinMode(WALK_BUTTON, INPUT);
    pinMode(EXIT_BUTTON, INPUT);

    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(WALK_RED, HIGH);
    digitalWrite(WALK_GREEN, LOW);

    this->running = true;
    this->processingPedestrian = false;
}

TrafficLight::~TrafficLight()
{
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    digitalWrite(WALK_RED, LOW);
    digitalWrite(WALK_GREEN, LOW);
}

void TrafficLight::run()
{
    this->listenButtons();
}

void TrafficLight::listenButtons()
{
    while (this->running) {
        if (digitalRead(EXIT_BUTTON) == LOW) {
            this->running = false;
        }

        if (digitalRead(WALK_BUTTON) == LOW) {
            this->processingPedestrian = true;
            this->processPedestrian();
            this->processingPedestrian = false;
        }

        delay(100);
    }
}

void TrafficLight::processPedestrian()
{
    std::cout << "A pedestrian pushed the button" << std::endl;
    delay(2000);
    this->stopTraffic();
    this->allowWalk();
    this->startTraffic();
}

void TrafficLight::stopTraffic()
{
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    delay(2000);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
}

void TrafficLight::startTraffic()
{
    delay(1500);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
}

void TrafficLight::allowWalk()
{
    digitalWrite(WALK_RED, LOW);
    digitalWrite(WALK_GREEN, HIGH);
    delay(5000);
    digitalWrite(WALK_GREEN, LOW);
    delay(500);
    digitalWrite(WALK_GREEN, HIGH);
    delay(500);
    digitalWrite(WALK_GREEN, LOW);
    delay(500);
    digitalWrite(WALK_GREEN, HIGH);
    delay(500);
    digitalWrite(WALK_GREEN, LOW);
    delay(500);
    digitalWrite(WALK_GREEN, HIGH);
    delay(500);
    digitalWrite(WALK_GREEN, LOW);
    digitalWrite(WALK_RED, HIGH);
}

int main(void)
{
    wiringPiSetup();

    TrafficLight* trafficLight = new TrafficLight();

    trafficLight->run();

    delete trafficLight;

    return 0;
}
