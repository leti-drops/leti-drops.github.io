#define PIN_SENSOR_FLOOR     3
#define PIN_SENSOR_TOP        5

#define PIN_LED_RED        0
#define PIN_LED_GREEN        1

void setup()
{
    pinMode(PIN_SENSOR_FLOOR, INPUT_PULLUP);
    pinMode(PIN_SENSOR_TOP, INPUT_PULLUP);
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
}

void loop()
{
    int sens_low = digitalRead(PIN_SENSOR_FLOOR);
    int sens_high = digitalRead(PIN_SENSOR_TOP);

    if(sens_low == HIGH)
    { digitalWrite(PIN_LED_RED, HIGH); digitalWrite(PIN_LED_GREEN, LOW); }
    else if(sens_low == LOW && sens_high == HIGH)
    { digitalWrite(PIN_LED_RED, LOW); digitalWrite(PIN_LED_GREEN, LOW); }
    else
    { digitalWrite(PIN_LED_RED, LOW); digitalWrite(PIN_LED_GREEN, HIGH); }
}
