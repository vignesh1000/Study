int clearBit(int num, int pos)
{
    return (num & ~(1<<pos));
}

int setBit(int num, int pos)
{
    return (num | (1<<pos));
}

int ToggleBit(int num, int pos)
{
    return (num ^ (1<<pos));
}

int TrailingZeros(int num)
{
    int i,count=0;
    
    for(i=0;i<32;i++)
    {
        if((num>>i) & 0x01)
        {
            break;
        }    
        count++;
    }
    return count;
}

int LeadingZeros(int num)
{
    int i,count=0;
    
    for(i=0;i<32;i++)
    {
        if((num<<i) & 0x80000000)
        {
            break;
        }    
        count++;
    }
    
    return count;
}

void swap(int *a, int *b)
{
    *a = (*a) ^ (* b);
    *b = (*b) ^ (* a);
    *a = (*a) ^ (* b);
}

//HighorLow - pass for high and 0 for low 
int CheckHighorLowOrderSetBit(int num, int HighorLow)
{
     int i,order=-1;
    
    for(i=0;i<32;i++)
    {
        if((num<<i) & 0x1)
        {
            order = i;
            if(HighorLow==0)
            {
                break;
            }
        }    
    } 
    
    return order;
}

int CntZerosAndOnes(int num)
{
    int i,zeros,ones=0;
    
    for(i=0;i<32;i++)
    {
        if(num & 0x1)
        {
            ones++;
        }    
        else
        {
            zeros++;
        }
        
        num = num >> 1;
    }
    
    printf("Ones: %d,Zeros: %d\n",ones,zeros);
}

int RotateLeft(int num,int rotation)
{
    int iMSB = 0;
    rotation = rotation % 31;
    
    while(rotation)
    {
        iMSB = (num>>31) & 0x01;
        num = (num<<1) | iMSB;
        rotation--;
    }
    
    return num;
}

int RotateRight(int num,int rotation)
{
    int iLSB = 0;
    rotation = rotation % 31;
    
    while(rotation)
    {
        iLSB = num & 0x01;
        num = (num>>1) & (~(1<<31));
        num = num | (iLSB<<31);
        rotation--;
    }
    
    return num;
}
