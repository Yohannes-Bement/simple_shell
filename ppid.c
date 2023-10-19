#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t john_pid;

    john_pid = getppid();
    printf("%u\n", john_pid);
    return (0);
}
