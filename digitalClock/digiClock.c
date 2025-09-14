#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<Windows.h>
int main(){

    //holds unix epoch jan 1 1970 utc -> this is epoc
    time_t rawTime =0;
    struct tm *pTime = NULL;
    bool isRunning = true;


    printf("digital clock\n");

    while(isRunning){
        time(&rawTime);
        //long decimal type specifier
        //printf("%ld",rawTime);
        //pointer to time struct which contains the current time
        pTime = localtime(&rawTime);
        //pTime->tm_hour == *(pTime).tm_hour
        //02 is 0 padding
        //carrage return \r
        printf("\r%02d:%02d:%02d",pTime->tm_hour,pTime->tm_min,pTime->tm_sec);
        Sleep(1000);
    }
    isRunning = false;
    
    return 0;
}

