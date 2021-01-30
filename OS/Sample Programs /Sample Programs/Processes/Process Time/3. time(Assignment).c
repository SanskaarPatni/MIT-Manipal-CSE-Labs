#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<sys/time.h>
#include<limits.h>

int main()
{
    clock_t real_srt;
    clock_t real_end;
    clock_t ticks_used;
    
    struct tms *process_start;
    struct tms *process_end;
    
    if((real_srt=times(&process_start)) == -1)
         perror("Could not get starting times.\n");
    else
    {
        if((real_end=times(&process_end)) == -1)    
             perror("Could not get ending times.\n");
        else
        {
             ticks_used=process_end->tms_utime + process_end->tms_cstime - process_start->tms_utime - process_start->tms_cstime;
             printf("Fraction of time running : %f", (double)(ticks_used)/(real_end-real_srt));             
        }
    }
}
