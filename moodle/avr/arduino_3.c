#define PIN_SENSOR_FLOOR     3
#define PIN_SENSOR_TOP        5

#define PIN_LED_RED        0
#define PIN_LED_GREEN        1

#define PIN_PUMP        10
#define PIN_PUMP_BUTTON        12

void setup()
{
    pinMode(PIN_SENSOR_FLOOR, INPUT_PULLUP);
    pinMode(PIN_SENSOR_TOP, INPUT_PULLUP);
    pinMode(PIN_LED_RED, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_PUMP, OUTPUT);
    pinMode(PIN_PUMP_BUTTON, INPUT_PULLUP);
}

void loop()
{
    int sens_low = digitalRead(PIN_SENSOR_FLOOR);
    int sens_high = digitalRead(PIN_SENSOR_TOP);

    if(sens_low == HIGH) // вода ниже нижнего датчика
    {
        digitalWrite(PIN_LED_RED, HIGH); digitalWrite(PIN_LED_GREEN, LOW);
        digitalWrite(PIN_PUMP, HIGH);
    }
    else if(sens_low == LOW && sens_high == HIGH) // вода между 2мя датчиками
    {
        digitalWrite(PIN_LED_RED, LOW); digitalWrite(PIN_LED_GREEN, LOW);
        if(digitalRead(PIN_PUMP_BUTTON) == LOW)
            digitalWrite(PIN_PUMP, HIGH);
        else
            digitalWrite(PIN_PUMP, LOW);
    }
    else // вода выше верхнего датчика
    {
        digitalWrite(PIN_LED_RED, LOW); digitalWrite(PIN_LED_GREEN, HIGH);
        digitalWrite(PIN_PUMP, LOW);
    }
}
