void pow(int& a, int b)
{
        int c = a;
        a = 1;
        for(int i = 0; i < b; ++i)
                a *= c;
}
