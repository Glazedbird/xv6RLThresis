#include "kernel/types.h"
#include "user/user.h"

void
spawn(char *prog)
{
    int pid = fork();

    if(pid < 0){
        printf("fork failed\n");
        return;
    }

    if(pid == 0){
        char *argv[] = { prog, 0 };
        exec(prog, argv);
        printf("exec %s failed\n", prog);
        exit(1);
    }
}

int
main(int argc, char *argv[])
{
    if(argc < 2){
        printf("usage: workload <mode>\n");
        exit(1);
    }

    int mode = atoi(argv[1]);

    printf("mode %d running!\n", mode);

    if(mode == 0){
        spawn("cpu_long");
        spawn("cpu_long");
        spawn("cpu_long");
        spawn("cpu_long");
    } else if(mode == 1){
        for(int i = 0; i < 8; i++)
            spawn("cpu_short");
    } else if(mode == 2){
        spawn("cpu_long");
        spawn("cpu_long");
        for(int i = 0; i < 6; i++)
            spawn("cpu_short");
    } else if(mode == 3){
        spawn("cpu_long");
        for(int i = 0; i < 4; i++)
            spawn("sleepy_job");
    } else {
        printf("invalid mode\n");
        exit(1);
    }

    while(wait(0) != -1)
        ;

    printf("mode %d finished!\n", mode);
    exit(0);
}