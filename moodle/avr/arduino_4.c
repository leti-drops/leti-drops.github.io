#include "DHT.h"

#define PIN_LED_HUMIDITY_LOW    0
#define PIN_LED_HUMIDITY_HIGH    1

#define PIN_TEMP_SENSOR_DHT    3


DHT dht(PIN_TEMP_SENSOR_DHT, DHT22);

void setup()
{
    pinMode(PIN_LED_HUMIDITY_LOW, OUTPUT);
    pinMode(PIN_LED_HUMIDITY_HIGH, OUTPUT);

    dht.begin();
}

void loop()
{
    delay(10);
    float humidity = dht.readHumidity();
    if(humidity < 45)
    { digitalWrite(PIN_LED_HUMIDITY_LOW, HIGH); digitalWrite(PIN_LED_HUMIDITY_HIGH, LOW); }
    else if(humidity > 60)
    { digitalWrite(PIN_LED_HUMIDITY_LOW, LOW); digitalWrite(PIN_LED_HUMIDITY_HIGH, HIGH); }
    else
    { digitalWrite(PIN_LED_HUMIDITY_LOW, LOW); digitalWrite(PIN_LED_HUMIDITY_HIGH, LOW); }
}
