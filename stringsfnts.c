    #include<stdio.h>  
    
       void StrCpy(char *src, char *dest);
       void StrCat(char *src, char *dest);
       void StrRev(char *ptr);
       int StrLen(char *ptr);
       void StrnCmp(char *src, char *dest,int size);
    
    int main()  
    {  
        char a[20] = "Vignesh";
        char b[20] = "Vignesh";
      
      StrnCmp(a,b,StrLen(a));
      
      //printf("%s",a);
    } 
    
    void StrCpy(char *src, char *dest)
    {
        int cnt = 0;
        for(cnt=0;src[cnt]!='\0';cnt++)
        {
            dest[cnt] = src[cnt];
        }
        
    }
    
    void StrnCmp(char *src, char *dest,int size)
    {
        int cnt = 0;
        
        for(cnt=0;cnt<size;cnt++)
        {
            if(src[cnt] != dest[cnt])
            {
                printf("strings not equal");
                return;
            }
        } 
    }
    
    void StrCat(char *src, char *dest)
    {
        int cnt = 0;
        int length = 0;
        
        length = StrLen(src);
        
        for(cnt=0;dest[cnt]!='\0';cnt++)
        {
            src[length+cnt] = dest[cnt];
        } 
    }
    
    int StrLen(char *ptr)
    {
        int cnt = 0;
        int length = 0;
        
        for(cnt=0;ptr[cnt]!='\0';cnt++)
        {
            length++;
        }
        
        return length;
    }
    
    void StrRev(char *ptr)
    {
        int cnt = 0;
        int length = 0;
        char ch=0;
        char *startptr = NULL;
        char *endptr = NULL;
        
        startptr = ptr;
        endptr = ptr;
        
        length = StrLen(ptr);
        
        for(cnt=0;cnt<length/2;cnt++)
        {
            ch = endptr[length-1];
            endptr[length-1] = startptr[cnt];
            startptr[cnt] = ch;
            length--;
        } 
    }
