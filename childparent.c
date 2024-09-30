/* ----------------------------------------------------*/
/* ИМЯ: user ID пользователя: 1000 */
/* СРОК : 09/17/2024 */
/* ИМЯ ФАЙЛА: childparent.c */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ: */
/* В программе создаются два процесса */
/* родительский и дочерний с помощью fork() */
/* с итерационными циклами */
/* ----------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>

#define MAX_COUNT 200 // максимальное значение счётчика


/* child process с циклом*/
void  ChildProcess(void){
    for (int i = 1; i <= MAX_COUNT; i++)
        printf("This line is from child (pid = %d, ppid = %d), value = %d\n", getpid(), getppid(), i);
}

/* parent process с циклом */
void  ParentProcess(void){
    for (int i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent (pid = %d, ppid = %d), value = %d\n", getpid(), getppid(), i);
}

int main(){
        int pid;
        printf("I'm the original process with pid %d and ppid %d\n", getpid(), getppid());
	pid = fork();
        if (pid!=0){
            ParentProcess();
        }else{
            ChildProcess();
        }
	sleep(5);
	execl("/bin/ps", "ps", NULL);
    return 0;
}
