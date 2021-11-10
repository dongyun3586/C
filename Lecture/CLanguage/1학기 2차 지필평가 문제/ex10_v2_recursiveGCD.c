int gcd_recursive(int a, int b)
{
    if (a == b)
        return a;
    else {
        if (a >= b)
            gcd_recursive(a - b, b);
        else
            gcd_recursive(a, b - a);
    }
}

int gcd(int a, int b)
{
    if (a == b)
        return a;
    else if (a > b)
        return gcd(a - b, b);
    else if (a < b)
        return gcd(a, b - a);
}

int gcd(int a, int b)
{
    if (a > b)
        return gcd(a - b, b);
    else if (a < b)
        return gcd(a, b - a);
    else return a;
}

