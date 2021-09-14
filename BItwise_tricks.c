Bitwise Tricks:

1. Set a bit in a number - (num | (1<<pos))
2. Clear a bit in a number - (num & (~(1<<pos)))
3. Toggle a bit - (num ^ (1<<pos))
4. Checking nth bit is set or unset - ((num>>pos) & 1)
5. inverting all bits - num = (~num)
6. 2s complement of a number - (num = (~num+1))
7. stripping the lowest set bit - (num & (num-1))
8. Getting the lowest set bit - (num & (~num))
9. Right shift division - (num>>pos) - (num/pow(2,pos))
10. left shift multiplication - (num<<pos) - (num*pow(2,pos))
11. Clearing all bits from LSB to ith bit - num = num & (~((1 << i+1 ) - 1))
12. setting all bits from LSB to ith bit - num = num | ((1 << i+1) -1)
13. clearing all bits from MSB to ith bit - num = num & ((1 << i) - 1)
14. counting set bits in a number:
int countSetBits(int x)
{
    int count = 0;
    while (x)
    {
        x &= (x-1);
        count++;
    }
    return count;
}
15. find log base 2 of a given number
int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}
16. find whether a number is power of 2
int isPowerof2(int x)
{
    return (x && !(x & x-1));
}
17. swap two numbers without using temporary variable
a ^= b;
b ^= a; 
a ^= b;
18. 