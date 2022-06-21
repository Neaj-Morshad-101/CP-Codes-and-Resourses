//Maybe 0 indexed

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}

int Reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}

bool Check(int N,int pos)
{
    return (bool)(N &(1<<pos));
}
