#include <sys/syscall.h>

void _start() {
    asm volatile("movl 4(%esp), %ecx\n"
                 "leal 8(%esp), %eax\n"
                 "leal 12(%esp, %ecx, 4), %edx\n"
                 "push %edx\n"
                 "push %eax\n"
                 "push %ecx\n"
                 "call main\n"
                 "movl %eax, %ebx\n"
                 );
    asm volatile("int $0x80\n"
                          :
                          : "a"(SYS_exit)
                          :
             );
}

int main(int argc, char *argv[]) {
    return 42;
}
