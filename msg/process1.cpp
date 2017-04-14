#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MSGSZ 128

using namespace std;

typedef struct msgbuff
{
long  mtype;
char mtext[MSGSZ];
} message;

int main(int argc, char** argv)
{
    key_t key;
    int flag;
    int msqid;
    message sbuf;
    message sbuf_rec;
#ifdef MSZ
cout<< "\nFLAG IS SET\n"<<endl;
#else
cout<< "\nFLAG NOT SET\n"<<endl;
#endif
    key=1234;
    flag=IPC_CREAT | 0666;
    
    int pid = fork();

    //create a queue
    if( (msqid=msgget(key, flag))==-1)
    {
        cout<< "\nerr msgget"<<endl;
        exit(1);
    }else
        cout<< "\nmsqid "<<msqid<<" PID "<<pid<<endl;

    if(pid)
    {
        char c[15] = "whos ur daddy";
        sbuf.mtype=1L;
        sprintf(sbuf.mtext, c);
        cout<<sbuf.mtext<<endl;
        if(msgsnd(msqid, &sbuf, strlen(sbuf.mtext)+1, IPC_NOWAIT) < 0)
        {
            cout<< "\nErr msgsnd"<<endl;
            exit(1);
        }
        else
            cout<< "\nimess success "<<msqid<<" PID "<<pid<<endl;
    }else
    {
        if(msgrcv(msqid, &sbuf_rec, MSGSZ, 1, 0) < 0)
        {
            cout<< "\nErr msgsnd"<<endl;
            exit(1);
        }
        else
            cout<<"I have received: "<<sbuf_rec.mtext<<endl;
    }

}
