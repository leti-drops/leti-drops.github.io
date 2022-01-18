void setup()
{
    for(size_t p = 22; p <= 29; ++p)
        pinMode(p, OUTPUT);
}

void loop()
{
    for(size_t p = 22; p <= 29; ++p)
        digitalWrite(p, HIGH);
}
