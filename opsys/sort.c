#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

struct message_t {
        long addr;
        char str[11];
};

int main(int argc, char** argv) {

        if ( argc != 2 ) {
                printf("Error!\n");
                return 1;
        }

        int handler = msgget(IPC_PRIVATE, 0777 | IPC_CREAT);

        int N = atoi(argv[1]);

        struct message_t msg;

        int child = 0;
        for( ; child < N && fork(); child++ ) ;

        if (child == N) {
                msg.addr = 1;
                sprintf(msg.str, "Te jössz!");
                msgsnd(handler, &msg, sizeof(struct message_t) - sizeof(long), 0777);
        }
        else {
                msgrcv(handler, &msg, sizeof(struct message_t) - sizeof(long), child+1, 0777);
                printf("%d\n", child);

                msg.addr++;
                msgsnd(handler, &msg, sizeof(struct message_t) - sizeof(long), 0777);
        }

        return 0;
}
