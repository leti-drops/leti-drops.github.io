void swap(int& a, int& b){
    int c = a; a = b; b = c;
}

void swap(char*& a, char*& b){
    char swapbuf[20];
    strcpy(swapbuf, a);
    strcpy(a, b);
    strcpy(b, swapbuf);
}
