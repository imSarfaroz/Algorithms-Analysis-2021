	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
LC0:
	.ascii " \0"
	.text
	.globl	__Z27readAndPrintInReversedOrderv
	.def	__Z27readAndPrintInReversedOrderv;	.scl	2;	.type	32;	.endef
__Z27readAndPrintInReversedOrderv:
	push	ebp
	mov	ebp, esp
	sub	esp, 40
	lea	eax, [ebp-12]
	mov	DWORD PTR [esp], eax
	mov	ecx, OFFSET FLAT:__ZSt3cin
	call	__ZNSirsERi
	sub	esp, 4
	mov	edx, DWORD PTR [eax]
	sub	edx, 12
	mov	edx, DWORD PTR [edx]
	add	eax, edx
	mov	ecx, eax
	call	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv
	test	al, al
	je	L3
	call	__Z27readAndPrintInReversedOrderv
	mov	DWORD PTR [esp+4], OFFSET FLAT:LC0
	mov	DWORD PTR [esp], OFFSET FLAT:__ZSt4cout
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	edx, DWORD PTR [ebp-12]
	mov	DWORD PTR [esp], edx
	mov	ecx, eax
	call	__ZNSolsEi
	sub	esp, 4
L3:
	nop
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
	sub	esp, 20
	call	___main
	call	__Z27readAndPrintInReversedOrderv
	mov	DWORD PTR [esp], OFFSET FLAT:__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	ecx, OFFSET FLAT:__ZSt4cout
	call	__ZNSolsEPFRSoS_E
	sub	esp, 4
	mov	eax, 0
	mov	ecx, DWORD PTR [ebp-4]
	leave
	lea	esp, [ecx-4]
	ret
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	ecx, OFFSET FLAT:__ZStL8__ioinit
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	cmp	DWORD PTR [ebp+8], 1
	jne	L9
	cmp	DWORD PTR [ebp+12], 65535
	jne	L9
	mov	ecx, OFFSET FLAT:__ZStL8__ioinit
	call	__ZNSt8ios_base4InitC1Ev
	mov	DWORD PTR [esp], OFFSET FLAT:___tcf_0
	call	_atexit
L9:
	nop
	leave
	ret
	.def	__GLOBAL__sub_I__Z27readAndPrintInReversedOrderv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z27readAndPrintInReversedOrderv:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	DWORD PTR [esp+4], 65535
	mov	DWORD PTR [esp], 1
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z27readAndPrintInReversedOrderv
	.ident	"GCC: (GNU) 9.2.0"
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
