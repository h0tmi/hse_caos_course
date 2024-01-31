#include <stdio.h>

int main() {
    int fam_id = 0;
    int model_id = 0;
    int ecx = 0;
    int edx = 0;
    int extended_model_id = 0;
    asm(
    "movl $1, %%eax\n"
    "cpuid\n"
    "sarl $4, %%eax\n"
    "movl %%eax, %%edi\n"
    "andl $0xf, %%edi\n"
    "movl %%edi, %[model]\n"
    "sarl $4, %%eax\n"
    "movl %%eax, %%edi\n"
    "andl $0xf, %%edi\n"
    "movl %%edi, %[family]\n"
    "sarl $4, %%eax\n"
    "movl %%eax, %%edi\n"
    "andl $0xf, %%edi\n"
    "movl %%edi, %[extended_model]\n"
    "movl %%ecx, %[ecx]\n"
    "movl %%edx, %[edx]\n"
    :
    [family] "=rm" (fam_id),
    [model] "=rm" (model_id),
    [ecx] "=rm" (ecx),
    [edx] "=rm" (edx),
    [extended_model] "=m" (extended_model_id)
    :
    : "%eax", "%ebx", "%ecx", "%edx", "%edi"
    );
    // extended_model_id <<= 4;
    model_id += extended_model_id;
    printf("family=%d model=%d ecx=0x%x edx=0x%x\n", fam_id, model_id, ecx, edx);
    return 0;
}
