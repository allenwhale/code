	.file	"ans.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z7pow_modnnn
	.type	_Z7pow_modnnn, @function
_Z7pow_modnnn:
.LFB12701:
	.cfi_startproc
	movq	%rcx, %rax
	orq	%rdx, %rax
	jne	.L4
	movl	$1, %eax
	xorl	%edx, %edx
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	jmp	_Z7pow_modnnn.part.5
	.cfi_endproc
.LFE12701:
	.size	_Z7pow_modnnn, .-_Z7pow_modnnn
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.globl	__modti3
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.type	_Z7pow_modnnn.part.5, @function
_Z7pow_modnnn.part.5:
.LFB14002:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%r9, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rdx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%r8, %r12
	shrdq	$1, %rcx, %rdx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	sarq	%rcx
	movq	%rdi, %rbx
	movq	%rsi, 8(%rsp)
	call	_Z7pow_modnnn
	imulq	%rax, %rdx
	movq	%rax, %rsi
	movq	%rsi, %rax
	leaq	(%rdx,%rdx), %rcx
	mulq	%rsi
	movq	%rdx, %rbp
	movq	%rax, %rdi
	addq	%rcx, %rbp
	cmpq	%rbp, %r15
	jg	.L6
	jge	.L16
.L12:
	movq	%rbp, %rsi
	movq	%r12, %rdx
	movq	%r15, %rcx
	call	__modti3
	movq	%rax, %rdi
	movq	%rdx, %rbp
.L6:
	andl	$1, %r13d
	movq	%rdi, %rax
	movq	%rbp, %rdx
	je	.L8
	movq	8(%rsp), %rax
	movq	%rbx, %rcx
	imulq	%rbp, %rcx
	imulq	%rdi, %rax
	addq	%rax, %rcx
	movq	%rbx, %rax
	mulq	%rdi
	movq	%rdx, %rbp
	movq	%rax, %rdi
	addq	%rcx, %rbp
	cmpq	%rbp, %r15
	jle	.L17
.L11:
	movq	%rdi, %rax
	movq	%rbp, %rdx
.L8:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	.cfi_restore_state
	jge	.L18
.L13:
	movq	%rbp, %rsi
	movq	%r12, %rdx
	movq	%r15, %rcx
	call	__modti3
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	.cfi_restore_state
	cmpq	%rax, %r12
	ja	.L6
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L18:
	cmpq	%rax, %r12
	ja	.L11
	jmp	.L13
	.cfi_endproc
.LFE14002:
	.size	_Z7pow_modnnn.part.5, .-_Z7pow_modnnn.part.5
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	_Z8get_hashiiinn
	.type	_Z8get_hashiiinn, @function
_Z8get_hashiiinn:
.LFB12702:
	.cfi_startproc
	movslq	%esi, %rsi
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	imulq	$2000020, %rsi, %rsi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leal	-1(%rdx), %ebx
	movslq	%ecx, %rbp
	movq	%r8, %rdx
	movq	%r8, %rax
	movslq	%ebx, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%rdi, %r15
	addq	%rsi, %rbx
	leaq	(%rsi,%rbp), %r11
	movq	88(%rsp), %r10
	movq	%rbx, %rcx
	movq	80(%rsp), %r12
	salq	$4, %rcx
	movq	%r11, %r13
	movq	%r11, (%rsp)
	imulq	rolling(%rcx), %r9
	imulq	rolling+8(%rcx), %rdx
	salq	$4, %r13
	movq	%r10, 8(%rsp)
	leaq	(%r9,%rdx), %rsi
	mulq	rolling(%rcx)
	xorl	%ecx, %ecx
	addq	%rdx, %rsi
	movq	%rax, %rdi
	movabsq	$68720001023, %rdx
	call	__modti3
	movq	rolling+8(%r13), %r14
	movq	rolling(%r13), %r13
	movq	8(%rsp), %r10
	movq	(%rsp), %r11
	subq	%rax, %r13
	movq	%r12, %rax
	sbbq	%rdx, %r14
	leaq	1000010(%rbx), %rdx
	leaq	1000010(%r11), %rbp
	xorl	%ecx, %ecx
	salq	$4, %rdx
	salq	$4, %rbp
	imulq	rolling(%rdx), %r10
	imulq	rolling+8(%rdx), %rax
	movq	%rbp, (%rsp)
	leaq	(%r10,%rax), %rsi
	movq	%r12, %rax
	mulq	rolling(%rdx)
	addq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$101, %edx
	call	__modti3
	movq	(%rsp), %rbp
	movq	rolling(%rbp), %rcx
	movq	rolling+8(%rbp), %rbx
	subq	%rax, %rcx
	sbbq	%rdx, %rbx
	testq	%r14, %r14
	movq	%rcx, %rax
	movq	%rbx, %rdx
	js	.L23
.L20:
	testq	%rdx, %rdx
	jns	.L21
	addq	$101, %rax
	adcq	$0, %rdx
.L21:
	movq	%r13, (%r15)
	movq	%r14, 8(%r15)
	movq	%rax, 16(%r15)
	movq	%rdx, 24(%r15)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	movq	%r15, %rax
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	.cfi_restore_state
	movabsq	$68720001023, %rcx
	xorl	%ebx, %ebx
	addq	%rcx, %r13
	adcq	%rbx, %r14
	jmp	.L20
	.cfi_endproc
.LFE12702:
	.size	_Z8get_hashiiinn, .-_Z8get_hashiiinn
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,comdat
	.align 2
.LCOLDB3:
	.section	.text._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,comdat
.LHOTB3:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv
	.type	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv, @function
_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv:
.LFB13390:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	16(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L26
	.p2align 4,,10
	.p2align 3
.L30:
	movq	(%rdi), %rbx
	call	_ZdlPv
	testq	%rbx, %rbx
	movq	%rbx, %rdi
	jne	.L30
.L26:
	movq	8(%rbp), %rax
	movq	0(%rbp), %rdi
	xorl	%esi, %esi
	leaq	0(,%rax,8), %rdx
	call	memset
	movq	$0, 24(%rbp)
	movq	$0, 16(%rbp)
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE13390:
	.size	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv, .-_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv
	.section	.text.unlikely._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,comdat
.LCOLDE3:
	.section	.text._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv,comdat
.LHOTE3:
	.section	.text.unlikely._ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev,"axG",@progbits,_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED5Ev,comdat
	.align 2
.LCOLDB4:
	.section	.text._ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev,"axG",@progbits,_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED5Ev,comdat
.LHOTB4:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev
	.type	_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev, @function
_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev:
.LFB13972:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	addq	$48, %rbx
	call	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv
	movq	-48(%rbx), %rdi
	cmpq	%rbx, %rdi
	je	.L34
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv
	.p2align 4,,10
	.p2align 3
.L34:
	.cfi_restore_state
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE13972:
	.size	_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev, .-_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev
	.section	.text.unlikely._ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev,"axG",@progbits,_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED5Ev,comdat
.LCOLDE4:
	.section	.text._ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev,"axG",@progbits,_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED5Ev,comdat
.LHOTE4:
	.weak	_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED1Ev
	.set	_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED1Ev,_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED2Ev
	.section	.text.unlikely._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,comdat
	.align 2
.LCOLDB5:
	.section	.text._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,comdat
.LHOTB5:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE
	.type	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE, @function
_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE:
.LFB13574:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA13574
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rsi, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rdx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbp
	movq	%rcx, %r12
	addq	$32, %rdi
	movl	$1, %ecx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	movq	-8(%rdi), %rdx
	movq	-24(%rdi), %rsi
	movq	8(%rdi), %r14
.LEHB0:
	call	_ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEmmm
.LEHE0:
	testb	%al, %al
	je	.L38
	cmpq	$1, %rdx
	movq	%rdx, %rbx
	je	.L70
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rdx
	ja	.L71
	leaq	0(,%rdx,8), %r15
	movq	%r15, %rdi
.LEHB1:
	call	_Znwm
	movq	%r15, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, %r14
	call	memset
	leaq	48(%rbp), %r10
.L40:
	movq	16(%rbp), %rcx
	movq	$0, 16(%rbp)
	testq	%rcx, %rcx
	je	.L42
	xorl	%r8d, %r8d
	leaq	16(%rbp), %r9
	jmp	.L44
	.p2align 4,,10
	.p2align 3
.L45:
	movq	(%rsi), %rdx
	movq	%rdx, (%rcx)
	movq	(%rax), %rax
	movq	%rcx, (%rax)
.L46:
	testq	%rdi, %rdi
	movq	%rdi, %rcx
	je	.L42
.L44:
	movq	64(%rcx), %rax
	xorl	%edx, %edx
	movq	(%rcx), %rdi
	divq	%rbx
	leaq	(%r14,%rdx,8), %rax
	movq	(%rax), %rsi
	testq	%rsi, %rsi
	jne	.L45
	movq	16(%rbp), %rsi
	movq	%rsi, (%rcx)
	movq	%rcx, 16(%rbp)
	movq	%r9, (%rax)
	cmpq	$0, (%rcx)
	je	.L55
	testq	%rdi, %rdi
	movq	%rcx, (%r14,%r8,8)
	movq	%rdx, %r8
	movq	%rdi, %rcx
	jne	.L44
	.p2align 4,,10
	.p2align 3
.L42:
	movq	0(%rbp), %rdi
	cmpq	%r10, %rdi
	je	.L47
	call	_ZdlPv
.L47:
	movq	%r13, %rax
	xorl	%edx, %edx
	movq	%rbx, 8(%rbp)
	divq	%rbx
	movq	%r14, 0(%rbp)
	movq	%rdx, %r15
.L48:
	salq	$3, %r15
	movq	%r13, 64(%r12)
	leaq	(%r14,%r15), %rax
	movq	(%rax), %rdx
	testq	%rdx, %rdx
	je	.L51
	movq	(%rdx), %rdx
	movq	%rdx, (%r12)
	movq	(%rax), %rax
	movq	%r12, (%rax)
.L52:
	addq	$1, 24(%rbp)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r12, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L38:
	.cfi_restore_state
	movq	0(%rbp), %r14
	jmp	.L48
	.p2align 4,,10
	.p2align 3
.L51:
	movq	16(%rbp), %rax
	testq	%rax, %rax
	movq	%rax, (%r12)
	movq	%r12, 16(%rbp)
	je	.L53
	movq	(%r12), %rax
	xorl	%edx, %edx
	movq	64(%rax), %rax
	divq	8(%rbp)
	movq	%r12, (%r14,%rdx,8)
.L53:
	movq	0(%rbp), %rax
	leaq	16(%rbp), %rdx
	movq	%rdx, (%rax,%r15)
	jmp	.L52
	.p2align 4,,10
	.p2align 3
.L55:
	movq	%rdx, %r8
	jmp	.L46
.L70:
	leaq	48(%rbp), %r14
	movq	$0, 48(%rbp)
	movq	%r14, %r10
	jmp	.L40
.L71:
	call	_ZSt17__throw_bad_allocv
.LEHE1:
.L58:
.L49:
	movq	%rax, %rdi
	call	__cxa_begin_catch
	movq	%r14, 40(%rbp)
.LEHB2:
	call	__cxa_rethrow
.LEHE2:
.L57:
	movq	%rax, %rbx
.L50:
	call	__cxa_end_catch
	movq	%rbx, %rdi
	call	__cxa_begin_catch
	movq	%r12, %rdi
	call	_ZdlPv
.LEHB3:
	call	__cxa_rethrow
.LEHE3:
.L56:
	movq	%rax, %rbx
.L54:
	call	__cxa_end_catch
	movq	%rbx, %rdi
.LEHB4:
	call	_Unwind_Resume
.LEHE4:
	.cfi_endproc
.LFE13574:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,"aG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,comdat
	.align 4
.LLSDA13574:
	.byte	0xff
	.byte	0x3
	.uleb128 .LLSDATT13574-.LLSDATTD13574
.LLSDATTD13574:
	.byte	0x1
	.uleb128 .LLSDACSE13574-.LLSDACSB13574
.LLSDACSB13574:
	.uleb128 .LEHB0-.LFB13574
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB13574
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L58-.LFB13574
	.uleb128 0x1
	.uleb128 .LEHB2-.LFB13574
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L57-.LFB13574
	.uleb128 0x3
	.uleb128 .LEHB3-.LFB13574
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L56-.LFB13574
	.uleb128 0
	.uleb128 .LEHB4-.LFB13574
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE13574:
	.byte	0x1
	.byte	0
	.byte	0
	.byte	0x7d
	.align 4
	.long	0

.LLSDATT13574:
	.section	.text._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,comdat
	.size	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE, .-_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE
	.section	.text.unlikely._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,comdat
.LCOLDE5:
	.section	.text._ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,"axG",@progbits,_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE,comdat
.LHOTE5:
	.section	.text.unlikely._ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,"axG",@progbits,_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,comdat
	.align 2
.LCOLDB6:
	.section	.text._ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,"axG",@progbits,_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,comdat
.LHOTB6:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_
	.type	_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_, @function
_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_:
.LFB13392:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	xorl	%edx, %edx
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	(%rsi), %r10
	movq	16(%rsi), %r13
	movq	8(%rdi), %r9
	movq	8(%rsi), %r11
	movq	24(%rsi), %r14
	movq	%r10, %rbx
	xorq	%r13, %rbx
	movq	%rbx, %rax
	divq	%r9
	movq	(%rdi), %rax
	movq	(%rax,%rdx,8), %r15
	movq	%rdx, %rbp
	testq	%r15, %r15
	je	.L73
	movq	(%r15), %r8
	movq	64(%r8), %rcx
.L76:
	cmpq	%rbx, %rcx
	je	.L91
.L74:
	movq	(%r8), %rdi
	testq	%rdi, %rdi
	je	.L73
	movq	64(%rdi), %rcx
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r9
	cmpq	%rdx, %rbp
	je	.L81
.L73:
	movl	$80, %edi
	movq	%rsi, 8(%rsp)
	call	_Znwm
	movq	8(%rsp), %rsi
	movq	%r12, %rdi
	movq	$0, (%rax)
	movq	$0, 48(%rax)
	movq	$0, 56(%rax)
	movq	%rax, %rcx
	movq	(%rsi), %rdx
	movq	%rdx, 16(%rax)
	movq	8(%rsi), %rdx
	movq	%rdx, 24(%rax)
	movq	16(%rsi), %rdx
	movq	%rdx, 32(%rax)
	movq	24(%rsi), %rdx
	movq	%rbp, %rsi
	movq	%rdx, 40(%rax)
	movq	%rbx, %rdx
	call	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS5_10_Hash_nodeIS3_Lb1EEE
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	addq	$48, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L91:
	.cfi_restore_state
	movq	%r11, %rdx
	movq	%r10, %rax
	xorq	24(%r8), %rdx
	xorq	16(%r8), %rax
	orq	%rax, %rdx
	jne	.L74
	movq	%r14, %rdx
	movq	%r13, %rax
	xorq	40(%r8), %rdx
	xorq	32(%r8), %rax
	orq	%rax, %rdx
	jne	.L74
	movq	(%r15), %rax
	testq	%rax, %rax
	je	.L73
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	addq	$48, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L81:
	.cfi_restore_state
	movq	%r8, %r15
	movq	%rdi, %r8
	jmp	.L76
	.cfi_endproc
.LFE13392:
	.size	_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_, .-_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_
	.section	.text.unlikely._ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,"axG",@progbits,_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,comdat
.LCOLDE6:
	.section	.text._ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,"axG",@progbits,_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_,comdat
.LHOTE6:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC7:
	.string	"%d"
.LC8:
	.string	"%d%s%s"
.LC9:
	.string	"%lld\n"
	.section	.text.unlikely
.LCOLDB10:
	.section	.text.startup,"ax",@progbits
.LHOTB10:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB12773:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	$.LC7, %edi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$200, %rsp
	.cfi_def_cfa_offset 256
	movq	%fs:40, %rax
	movq	%rax, 184(%rsp)
	xorl	%eax, %eax
	leaq	136(%rsp), %rsi
	call	scanf
.L125:
	movl	136(%rsp), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, 136(%rsp)
	je	.L128
	movl	$cnt, %edi
	call	_ZNSt10_HashtableISt4pairInnES0_IKS1_nESaIS3_ENSt8__detail10_Select1stESt8equal_toIS1_E9pair_hashNS5_18_Mod_range_hashingENS5_20_Default_ranged_hashENS5_20_Prime_rehash_policyENS5_17_Hashtable_traitsILb1ELb0ELb1EEEE5clearEv
	leaq	140(%rsp), %rsi
	movl	$s+1000011, %ecx
	movl	$s+1, %edx
	movl	$.LC8, %edi
	xorl	%eax, %eax
	call	scanf
	movl	$s+1, %edi
	call	strlen
	movslq	140(%rsp), %rbp
	movq	%rax, 64(%rsp)
	movl	%eax, 20(%rsp)
	movq	%rbp, %r12
	movq	%rbp, %rbx
	sarq	$63, %r12
	movq	%r12, %rax
	orq	%rbp, %rax
	jne	.L129
	movq	$1, 72(%rsp)
	movq	$0, 48(%rsp)
	xorl	%r15d, %r15d
	movq	$1, 24(%rsp)
.L94:
	testl	%ebx, %ebx
	jle	.L98
	movq	64(%rsp), %rdi
	movl	$s+1, %ecx
	movl	%edi, %eax
	leal	1(%rbx,%rdi), %esi
	addl	$1, %eax
	movl	%eax, %edx
	.p2align 4,,10
	.p2align 3
.L97:
	movzbl	(%rcx), %r8d
	movslq	%edx, %rdi
	addl	$1, %edx
	addq	$1, %rcx
	cmpl	%esi, %edx
	movb	%r8b, s(%rdi)
	jne	.L97
	movl	$s+1000011, %edx
	.p2align 4,,10
	.p2align 3
.L99:
	movzbl	(%rdx), %edi
	movslq	%eax, %rcx
	addl	$1, %eax
	addq	$1, %rdx
	cmpl	%esi, %eax
	movb	%dil, s+1000010(%rcx)
	jne	.L99
.L98:
	movl	64(%rsp), %eax
	movl	$137, %r14d
	movq	80(%rsp), %r13
	movq	%r14, (%rsp)
	movq	88(%rsp), %r14
	movq	$rolling, 104(%rsp)
	movq	$s+1, 56(%rsp)
	addl	%ebx, %eax
	movq	$rolling, 32(%rsp)
	movl	%ebx, 116(%rsp)
	movl	%eax, 112(%rsp)
	salq	$4, %rax
	movq	%r15, 120(%rsp)
	addq	$16, %rax
	movq	%rax, 96(%rsp)
.L96:
	movl	112(%rsp), %edx
	testl	%edx, %edx
	js	.L102
	movq	32(%rsp), %rax
	movq	96(%rsp), %rbx
	movq	56(%rsp), %r12
	addq	%rax, %rbx
	movq	%rax, %r15
	.p2align 4,,10
	.p2align 3
.L103:
	movsbl	(%r12), %eax
	imulq	$137, 8(%r15), %rcx
	subl	$97, %eax
	cltq
	movq	%rax, %r13
	sarq	$63, %rax
	movq	%rax, %r14
	movq	(%rsp), %rax
	mulq	(%r15)
	addq	%rcx, %rdx
	addq	%r13, %rax
	adcq	%r14, %rdx
	movq	%rax, %rdi
	xorl	%ecx, %ecx
	movq	%rdx, %rsi
	movabsq	$68720001023, %rdx
	call	__modti3
	imulq	$29, 16000168(%r15), %rcx
	movq	%rax, 16(%r15)
	movq	%rdx, 24(%r15)
	movl	$29, %eax
	mulq	16000160(%r15)
	addq	%rcx, %rdx
	addq	%r13, %rax
	adcq	%r14, %rdx
	movq	%rax, %rdi
	xorl	%ecx, %ecx
	movq	%rdx, %rsi
	movl	$101, %edx
	addq	$16, %r15
	call	__modti3
	movq	%rax, 16000160(%r15)
	movq	%rdx, 16000168(%r15)
	addq	$1, %r12
	cmpq	%r15, %rbx
	jne	.L103
.L102:
	addq	$32000320, 32(%rsp)
	movl	$rolling+64000640, %ebx
	addq	$1000010, 56(%rsp)
	movq	32(%rsp), %rax
	cmpq	%rax, %rbx
	jne	.L96
	movl	64(%rsp), %eax
	movq	%r13, 80(%rsp)
	movq	%r14, 88(%rsp)
	movl	116(%rsp), %ebx
	movq	120(%rsp), %r15
	testl	%eax, %eax
	jle	.L115
	movl	$1, %r12d
	movq	104(%rsp), %r14
	movq	72(%rsp), %r13
	jmp	.L108
	.p2align 4,,10
	.p2align 3
.L105:
	testq	%rdx, %rdx
	js	.L130
.L106:
	leaq	144(%rsp), %rsi
	movl	$cnt, %edi
	movq	%r9, 144(%rsp)
	movq	%r10, 152(%rsp)
	movq	%rax, 160(%rsp)
	movq	%rdx, 168(%rsp)
	call	_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_
	addq	$1, (%rax)
	adcq	$0, 8(%rax)
	addl	$1, %r12d
	addq	$16, %r14
	cmpl	%r12d, 20(%rsp)
	jl	.L107
	movl	140(%rsp), %ebx
.L108:
	movq	48(%rsp), %rsi
	movq	%r13, %rax
	leal	-1(%r12,%rbx), %r11d
	imulq	8(%r14), %rax
	imulq	(%r14), %rsi
	movslq	%r11d, %r8
	xorl	%ecx, %ecx
	movq	%r8, %rbx
	movq	%r8, 32(%rsp)
	salq	$4, %rbx
	addq	%rax, %rsi
	movq	%r13, %rax
	mulq	(%r14)
	addq	%rdx, %rsi
	movq	%rax, %rdi
	movabsq	$68720001023, %rdx
	call	__modti3
	movq	rolling(%rbx), %r9
	movq	24(%rsp), %rcx
	movq	%r15, %rsi
	movq	rolling+8(%rbx), %r10
	movq	32(%rsp), %r8
	subq	%rax, %r9
	movq	%rcx, %rax
	sbbq	%rdx, %r10
	leaq	1000010(%r8), %rbx
	movq	%r9, (%rsp)
	imulq	16000168(%r14), %rax
	imulq	16000160(%r14), %rsi
	salq	$4, %rbx
	movq	%r10, 8(%rsp)
	addq	%rax, %rsi
	movq	%rcx, %rax
	xorl	%ecx, %ecx
	mulq	16000160(%r14)
	addq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$101, %edx
	call	__modti3
	movq	rolling(%rbx), %rcx
	movq	8(%rsp), %r10
	movq	rolling+8(%rbx), %rbx
	movq	(%rsp), %r9
	subq	%rax, %rcx
	sbbq	%rdx, %rbx
	testq	%r10, %r10
	movq	%rcx, %rax
	movq	%rbx, %rdx
	jns	.L105
	movabsq	$68720001023, %rbx
	xorl	%esi, %esi
	addq	%rbx, %r9
	adcq	%rsi, %r10
	testq	%rdx, %rdx
	jns	.L106
.L130:
	addq	$101, %rax
	adcq	$0, %rdx
	jmp	.L106
.L107:
	movl	$rolling+32000320, %r12d
	xorl	%eax, %eax
	xorl	%edx, %edx
	movq	%r15, 64(%rsp)
	movl	$1, (%rsp)
	movq	%r12, %r15
	movq	%rdx, %r13
	movq	%rax, %r12
	movq	72(%rsp), %r14
	jmp	.L111
	.p2align 4,,10
	.p2align 3
.L109:
	testq	%rdx, %rdx
	js	.L131
.L110:
	leaq	144(%rsp), %rsi
	movl	$cnt, %edi
	movq	%rdx, 168(%rsp)
	movq	%r9, 144(%rsp)
	movq	%r10, 152(%rsp)
	movq	%rax, 160(%rsp)
	call	_ZNSt8__detail9_Map_baseISt4pairInnES1_IKS2_nESaIS4_ENS_10_Select1stESt8equal_toIS2_E9pair_hashNS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb1ELb0ELb1EEELb1EEixEOS2_
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	addq	%rax, %r12
	adcq	%rdx, %r13
	addl	$1, (%rsp)
	addq	$16, %r15
	movl	(%rsp), %eax
	cmpl	%eax, 20(%rsp)
	jl	.L132
.L111:
	movq	48(%rsp), %rsi
	movq	%r14, %rax
	movl	(%rsp), %r8d
	imulq	8(%r15), %rax
	imulq	(%r15), %rsi
	addl	140(%rsp), %r8d
	xorl	%ecx, %ecx
	subl	$1, %r8d
	movslq	%r8d, %r8
	addq	%rax, %rsi
	movq	%r14, %rax
	leaq	2000020(%r8), %rbx
	mulq	(%r15)
	salq	$4, %rbx
	movq	%r8, 56(%rsp)
	addq	%rdx, %rsi
	movq	%rax, %rdi
	movabsq	$68720001023, %rdx
	call	__modti3
	movq	rolling(%rbx), %r9
	movq	24(%rsp), %rcx
	movq	rolling+8(%rbx), %r10
	movq	64(%rsp), %rsi
	movq	56(%rsp), %r8
	subq	%rax, %r9
	movq	%rcx, %rax
	sbbq	%rdx, %r10
	movq	%r9, 32(%rsp)
	imulq	16000168(%r15), %rax
	imulq	16000160(%r15), %rsi
	leaq	3000030(%r8), %rbx
	movq	%r10, 40(%rsp)
	salq	$4, %rbx
	addq	%rax, %rsi
	movq	%rcx, %rax
	xorl	%ecx, %ecx
	mulq	16000160(%r15)
	addq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$101, %edx
	call	__modti3
	movq	rolling(%rbx), %rcx
	movq	40(%rsp), %r10
	movq	rolling+8(%rbx), %rbx
	movq	32(%rsp), %r9
	subq	%rax, %rcx
	sbbq	%rdx, %rbx
	testq	%r10, %r10
	movq	%rcx, %rax
	movq	%rbx, %rdx
	jns	.L109
	movabsq	$68720001023, %rbx
	xorl	%esi, %esi
	addq	%rbx, %r9
	adcq	%rsi, %r10
	testq	%rdx, %rdx
	jns	.L110
.L131:
	addq	$101, %rax
	adcq	$0, %rdx
	jmp	.L110
.L132:
	movq	%r12, %rax
.L104:
	movq	%rax, %rdx
	movl	$.LC9, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L125
.L129:
	movabsq	$68720001023, %r8
	xorl	%r9d, %r9d
	movq	%r12, %rcx
	movl	$137, %edi
	xorl	%esi, %esi
	movq	%rbp, %rdx
	call	_Z7pow_modnnn.part.5
	movl	$101, %r8d
	movq	%rdx, 48(%rsp)
	xorl	%r9d, %r9d
	movq	%rbp, %rdx
	movq	%r12, %rcx
	movl	$29, %edi
	xorl	%esi, %esi
	movq	%rax, 72(%rsp)
	call	_Z7pow_modnnn.part.5
	movq	%rax, 24(%rsp)
	movq	%rdx, %r15
	jmp	.L94
.L128:
	xorl	%eax, %eax
	movq	184(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L133
	addq	$200, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L115:
	.cfi_restore_state
	xorl	%eax, %eax
	jmp	.L104
.L133:
	call	__stack_chk_fail
	.cfi_endproc
.LFE12773:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE10:
	.section	.text.startup
.LHOTE10:
	.section	.text.unlikely
.LCOLDB12:
	.section	.text.startup
.LHOTB12:
	.p2align 4,,15
	.type	_GLOBAL__sub_I_s, @function
_GLOBAL__sub_I_s:
.LFB13996:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
	movq	$cnt+48, cnt(%rip)
	movq	$1, cnt+8(%rip)
	movl	$__dso_handle, %edx
	movq	$0, cnt+16(%rip)
	movq	$0, cnt+24(%rip)
	movl	$cnt, %esi
	movl	$0x3f800000, cnt+32(%rip)
	movq	$0, cnt+40(%rip)
	movl	$_ZNSt13unordered_mapISt4pairInnEn9pair_hashSt8equal_toIS1_ESaIS0_IKS1_nEEED1Ev, %edi
	movq	$0, cnt+48(%rip)
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE13996:
	.size	_GLOBAL__sub_I_s, .-_GLOBAL__sub_I_s
	.section	.text.unlikely
.LCOLDE12:
	.section	.text.startup
.LHOTE12:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_s
	.globl	cnt
	.bss
	.align 32
	.type	cnt, @object
	.size	cnt, 56
cnt:
	.zero	56
	.globl	rolling
	.align 32
	.type	rolling, @object
	.size	rolling, 64000640
rolling:
	.zero	64000640
	.globl	s
	.align 32
	.type	s, @object
	.size	s, 2000020
s:
	.zero	2000020
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.3.1-14ubuntu2) 5.3.1 20160413"
	.section	.note.GNU-stack,"",@progbits
