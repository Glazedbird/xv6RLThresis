#include "kernel/types.h"
#include "user/user.h"

void spawn(char *prog)
{
    int pid = fork();

    if(pid == 0)
    {
        exec(prog, 0);
        exit(0);
    }
}

int main(int argc, char *argv[])
{
    int mode = atoi(argv[1]);

    printf("mode %d running!\n", mode);
    
    if(mode == 0)
    {
        // CPU heavy
        spawn("cpu_long");
        spawn("cpu_long");
        spawn("cpu_long");
        spawn("cpu_long");
    }

    if(mode == 1)
    {
        // short jobs
        for(int i = 0; i < 8; i++)
            spawn("cpu_short");
    }

    if(mode == 2)
    {
        // mixed
        spawn("cpu_long");
        spawn("cpu_long");

        for(int i = 0; i < 6; i++)
            spawn("cpu_short");
    }

    if(mode == 3)
    {
        // sleep heavy
        spawn("cpu_long");

        for(int i = 0; i < 4; i++)
            spawn("sleepy_job");
    }

    while(wait(0) != -1);

    exit(0);
}