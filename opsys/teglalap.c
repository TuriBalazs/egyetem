#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

/*
IPC = Inter Process Communication
        - File
        - Körenyezeti változók
        - Signal
        - SHM = ossztott memoria
        - MSG = Message queueu
*/

struct message_t {
        long addr;
        int a, b;
        int K, T;
};

int main(){
        //int a, b;
        //int K, T;

        int handler = msgget(IPC_PRIVATE, 0777 | IPC_CREAT);

        struct message_t msg;

        int child = 0;


        for( ; child < 2 && fork(); child++) ;

        if ( child == 2 ) {
                printf("A="); scanf("%d", &msg.a);
                printf("B="); scanf("%d", &msg.b);

                msg.addr = 1;
                msgsnd(handler, &msg, sizeof(struct message_t) - sizeof(long), 0777);


                msgrcv(handler, &msg, sizeof(struct message_t) - sizeof(long), 3, 0777);
                printf("A=%d, B=%d, K=%d, T=%d\n", msg.a, msg.b, msg.K, msg.T);
                msgctl(IPC_RMID, handler, NULL);
        }
        else if( child == 0 ) {
                msgrcv(handler, &msg, sizeof(struct message_t) - sizeof(long), 1, 0777);
                msg.K = 2*(msg.a + msg.b);

                msg.addr = 2;
                msgsnd(handler, &msg, sizeof(struct message_t) - sizeof(long), 0777);
        }
        else {
                msgrcv(handler, &msg, sizeof(struct message_t) - sizeof(long), 2, 0777);
                msg.T = msg.a * msg.b;

                msg.addr = 3;
                msgsnd(handler, &msg, sizeof(struct message_t) - sizeof(long), 0777);
        }


        return 0;
}
