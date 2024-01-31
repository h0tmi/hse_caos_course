	.file	"sm06-1.c"
	.text
.Ltext0:
	.file 0 "/home/h0tmi/sm06/1" "sm06-1.c"
	.globl	__asan_stack_malloc_1
	.section	.rodata
	.align 4
.LC0:
	.string	"4 48 4 8 family:4 64 4 7 model:5 80 4 5 ecx:7 96 4 5 edx:7"
	.align 32
.LC1:
	.string	"family=%d model=%d ecx=0x%x edx=0x%x\n"
	.zero	58
	.text
	.globl	main
	.type	main, @function
main:
.LASANPC0:
.LFB0:
	.file 1 "sm06-1.c"
	.loc 1 3 12
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	subl	$200, %esp
	call	__x86.get_pc_thunk.di
	addl	$_GLOBAL_OFFSET_TABLE_, %edi
	leal	-184(%ebp), %eax
	movl	%eax, -188(%ebp)
	movl	%eax, -204(%ebp)
	movl	__asan_option_detect_stack_use_after_return@GOT(%edi), %eax
	cmpl	$0, (%eax)
	je	.L1
	subl	$12, %esp
	pushl	$128
	movl	%edi, %ebx
	call	__asan_stack_malloc_1@PLT
	addl	$16, %esp
	testl	%eax, %eax
	je	.L1
	movl	%eax, -188(%ebp)
.L1:
	movl	-188(%ebp), %edx
	leal	160(%edx), %eax
	movl	%eax, %ebx
	movl	$1102416563, (%edx)
	leal	.LC0@GOTOFF(%edi), %eax
	movl	%eax, 4(%edx)
	leal	.LASANPC0@GOTOFF(%edi), %eax
	movl	%eax, 8(%edx)
	shrl	$3, %edx
	movl	%edx, %esi
	movl	$-235802127, 536870912(%esi)
	movl	$-234556943, 536870916(%esi)
	movl	$-234556924, 536870920(%esi)
	movl	$-202116348, 536870924(%esi)
	.loc 1 3 12
	movl	%gs:20, %eax
	movl	%eax, -28(%ebp)
	xorl	%eax, %eax
	.loc 1 9 5
#APP
# 9 "sm06-1.c" 1
	movl $1, %eax
cpuid
movl %eax, -96(%ebx)
movl %eax, -112(%ebx)
shrl $4, -96(%ebx)
andl $0xFF, -96(%ebx)
movl $1, -96(%ebx)
shrl $8, -112(%ebx)
andl $0xF, -112(%ebx)
movl %eax, -96(%ebx)
movl %ecx, -80(%ebx)
movl %edx, -64(%ebx)

# 0 "" 2
	.loc 1 27 5
#NO_APP
	leal	-64(%ebx), %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	shrl	$3, %eax
	addl	$536870912, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	setne	%dl
	cmpb	$3, %al
	setle	%al
	andl	%edx, %eax
	testb	%al, %al
	je	.L5
	subl	$12, %esp
	pushl	%ecx
	movl	%edi, %ebx
	call	__asan_report_load4@PLT
.L5:
	movl	-64(%ebx), %eax
	movl	%eax, -192(%ebp)
	leal	-80(%ebx), %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	shrl	$3, %eax
	addl	$536870912, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	setne	%dl
	cmpb	$3, %al
	setle	%al
	andl	%edx, %eax
	testb	%al, %al
	je	.L6
	subl	$12, %esp
	pushl	%ecx
	movl	%edi, %ebx
	call	__asan_report_load4@PLT
.L6:
	movl	-80(%ebx), %eax
	movl	%eax, -196(%ebp)
	leal	-96(%ebx), %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	shrl	$3, %eax
	addl	$536870912, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	setne	%dl
	cmpb	$3, %al
	setle	%al
	andl	%edx, %eax
	testb	%al, %al
	je	.L7
	subl	$12, %esp
	pushl	%ecx
	movl	%edi, %ebx
	call	__asan_report_load4@PLT
.L7:
	movl	-96(%ebx), %eax
	movl	%eax, -200(%ebp)
	leal	-112(%ebx), %eax
	movl	%eax, %ecx
	movl	%ecx, %eax
	shrl	$3, %eax
	addl	$536870912, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	setne	%dl
	cmpb	$3, %al
	setle	%al
	andl	%edx, %eax
	testb	%al, %al
	je	.L8
	subl	$12, %esp
	pushl	%ecx
	movl	%edi, %ebx
	call	__asan_report_load4@PLT
.L8:
	movl	-112(%ebx), %eax
	subl	$12, %esp
	pushl	-192(%ebp)
	pushl	-196(%ebp)
	pushl	-200(%ebp)
	pushl	%eax
	leal	.LC1@GOTOFF(%edi), %eax
	pushl	%eax
	movl	%edi, %ebx
	call	printf@PLT
	addl	$32, %esp
	.loc 1 28 12
	movl	$0, %eax
	.loc 1 29 1
	movl	%eax, %edx
	.loc 1 3 12
	movl	-188(%ebp), %eax
	cmpl	%eax, -204(%ebp)
	je	.L2
	movl	$1172321806, (%eax)
	movl	$-168430091, 536870912(%esi)
	movl	$-168430091, 536870916(%esi)
	movl	$-168430091, 536870920(%esi)
	movl	$-168430091, 536870924(%esi)
	movl	124(%eax), %eax
	movb	$0, (%eax)
	jmp	.L3
.L2:
	movl	$0, 536870912(%esi)
	movl	$0, 536870916(%esi)
	movl	$0, 536870920(%esi)
	movl	$0, 536870924(%esi)
.L3:
	.loc 1 29 1
	movl	-28(%ebp), %eax
	subl	%gs:20, %eax
	je	.L10
	call	__stack_chk_fail_local
.L10:
	movl	%edx, %eax
	leal	-16(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 32
.LC2:
	.string	"sm06-1.c"
	.zero	55
	.section	.data.rel.local,"aw"
	.align 32
	.type	.Lubsan_data0, @object
	.size	.Lubsan_data0, 28
.Lubsan_data0:
	.long	.LC2
	.long	27
	.long	5
	.long	0
	.long	0
	.long	0
	.long	1
	.zero	36
	.section	.rodata
.LC3:
	.string	"*.Lubsan_data0"
.LC4:
	.string	"*.LC1"
.LC5:
	.string	"*.LC2"
	.section	.data.rel.local
	.align 32
	.type	.LASAN0, @object
	.size	.LASAN0, 96
.LASAN0:
	.long	.Lubsan_data0
	.long	28
	.long	64
	.long	.LC3
	.long	.LC2
	.long	0
	.long	0
	.long	0
	.long	.LC1
	.long	38
	.long	96
	.long	.LC4
	.long	.LC2
	.long	0
	.long	0
	.long	0
	.long	.LC2
	.long	9
	.long	64
	.long	.LC5
	.long	.LC2
	.long	0
	.long	0
	.long	0
	.text
	.type	_sub_D_00099_0, @function
_sub_D_00099_0:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	subl	$8, %esp
	pushl	$3
	leal	.LASAN0@GOTOFF(%eax), %edx
	pushl	%edx
	movl	%eax, %ebx
	call	__asan_unregister_globals@PLT
	addl	$16, %esp
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	_sub_D_00099_0, .-_sub_D_00099_0
	.section	.fini_array.00099,"aw"
	.align 4
	.long	_sub_D_00099_0
	.text
	.type	_sub_I_00099_1, @function
_sub_I_00099_1:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	call	__asan_init@PLT
	call	__asan_version_mismatch_check_v8@PLT
	subl	$8, %esp
	pushl	$3
	leal	.LASAN0@GOTOFF(%ebx), %eax
	pushl	%eax
	call	__asan_register_globals@PLT
	addl	$16, %esp
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	_sub_I_00099_1, .-_sub_I_00099_1
	.section	.init_array.00099,"aw"
	.align 4
	.long	_sub_I_00099_1
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LASANPC3:
.LFB3:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE3:
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LASANPC4:
.LFB4:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE4:
	.section	.text.__x86.get_pc_thunk.di,"axG",@progbits,__x86.get_pc_thunk.di,comdat
	.globl	__x86.get_pc_thunk.di
	.hidden	__x86.get_pc_thunk.di
	.type	__x86.get_pc_thunk.di, @function
__x86.get_pc_thunk.di:
.LASANPC5:
.LFB5:
	.cfi_startproc
	movl	(%esp), %edi
	ret
	.cfi_endproc
.LFE5:
	.text
.Letext0:
	.file 2 "/usr/include/stdio.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xe1
	.value	0x5
	.byte	0x1
	.byte	0x4
	.long	.Ldebug_abbrev0
	.uleb128 0x4
	.long	.LASF14
	.byte	0x1d
	.long	.LASF0
	.long	.LASF1
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.long	.LASF2
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.long	.LASF3
	.uleb128 0x5
	.long	0x2d
	.uleb128 0x1
	.byte	0x1
	.byte	0x8
	.long	.LASF4
	.uleb128 0x1
	.byte	0x2
	.byte	0x7
	.long	.LASF5
	.uleb128 0x1
	.byte	0x4
	.byte	0x7
	.long	.LASF6
	.uleb128 0x1
	.byte	0x1
	.byte	0x6
	.long	.LASF7
	.uleb128 0x1
	.byte	0x2
	.byte	0x5
	.long	.LASF8
	.uleb128 0x6
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x1
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x1
	.byte	0x8
	.byte	0x7
	.long	.LASF10
	.uleb128 0x1
	.byte	0x4
	.byte	0x5
	.long	.LASF11
	.uleb128 0x7
	.long	.LASF15
	.byte	0x2
	.value	0x164
	.byte	0xc
	.long	0x5c
	.long	0x90
	.uleb128 0x8
	.long	0x90
	.uleb128 0x9
	.byte	0
	.uleb128 0xa
	.byte	0x4
	.long	0x34
	.uleb128 0xb
	.long	.LASF16
	.byte	0x1
	.byte	0x3
	.byte	0x5
	.long	0x5c
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x2
	.long	.LASF12
	.byte	0x4
	.long	0x26
	.uleb128 0x3
	.byte	0x73
	.sleb128 -112
	.uleb128 0x2
	.long	.LASF13
	.byte	0x5
	.long	0x26
	.uleb128 0x3
	.byte	0x73
	.sleb128 -96
	.uleb128 0x3
	.string	"ecx"
	.byte	0x12
	.long	0x26
	.uleb128 0x3
	.byte	0x73
	.sleb128 -80
	.uleb128 0x3
	.string	"edx"
	.byte	0x17
	.long	0x26
	.uleb128 0x2
	.byte	0x73
	.sleb128 -64
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 18
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0x21
	.sleb128 7
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF9:
	.string	"long long int"
.LASF2:
	.string	"unsigned int"
.LASF6:
	.string	"long unsigned int"
.LASF10:
	.string	"long long unsigned int"
.LASF12:
	.string	"family"
.LASF3:
	.string	"char"
.LASF4:
	.string	"unsigned char"
.LASF16:
	.string	"main"
.LASF11:
	.string	"long int"
.LASF14:
	.string	"GNU C17 11.4.0 -m32 -mtune=generic -march=i686 -g -ggdb -fsanitize=address,undefined -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection"
.LASF5:
	.string	"short unsigned int"
.LASF15:
	.string	"printf"
.LASF8:
	.string	"short int"
.LASF13:
	.string	"model"
.LASF7:
	.string	"signed char"
	.section	.debug_line_str,"MS",@progbits,1
.LASF0:
	.string	"sm06-1.c"
.LASF1:
	.string	"/home/h0tmi/sm06/1"
	.hidden	__stack_chk_fail_local
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
