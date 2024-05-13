#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define BUF 1
#define FILE "EncodedMessage.txt"

char* Decode(char* str){
    if((*str>='A'&&*str<='Z')||(*str>='a'&&*str<='z')){
            if ((*str>='A'&&*str<'D')||(*str>='a'&&*str<'d'))
            {   
                *str+=23;
            }
            else{
                *str-=3;
              }
        }
        return str;
}



int main(){
    int fd=open(FILE, O_RDWR);
    char str[BUF];
    int i=0;
    while (pread(fd,str,BUF,i)){
            pwrite(fd,Decode(str),BUF,i);
              i++;
    }

    

    return 0;
}
