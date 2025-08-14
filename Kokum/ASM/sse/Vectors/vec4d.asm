global kokum_vec4d_add
global kokum_vec4d_sub
global kokum_vec4d_mul
global kokum_vec4d_div
global kokum_vec4d_scalar_mul
global kokum_vec4d_scalar_div
global kokum_vec4d_dot
global kokum_vec4d_negate
global kokum_vec4d_abs
global kokum_vec4d_min
global kokum_vec4d_max
global kokum_vec4d_norm

section .rodata align=16
mask_abs: dq 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF

section .text

kokum_vec4d_add:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    addpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    movapd xmm1, [rsi + 16]
    addpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_sub:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    subpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    movapd xmm1, [rsi + 16]
    subpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_mul:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    mulpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    movapd xmm1, [rsi + 16]
    mulpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_div:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    divpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    movapd xmm1, [rsi + 16]
    divpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_scalar_mul:
    movsd xmm1, [rsi]
    movddup xmm1, xmm1
    movapd xmm0, [rdi]
    mulpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    mulpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_scalar_div:
    movsd xmm1, [rsi]
    movddup xmm1, xmm1
    movapd xmm0, [rdi]
    divpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    divpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_dot:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    mulpd xmm0, xmm1
    movapd xmm2, [rdi + 16]
    movapd xmm3, [rsi + 16]
    mulpd xmm2, xmm3
    movhlps xmm4, xmm0
    addsd xmm0, xmm4
    movhlps xmm4, xmm2
    addsd xmm2, xmm4
    addsd xmm0, xmm2
    movsd [rdx], xmm0
    ret

kokum_vec4d_negate:
    xorpd xmm1, xmm1
    movapd xmm0, [rdi]
    subpd xmm1, xmm0
    movapd [rdx], xmm1
    movapd xmm0, [rdi + 16]
    xorpd xmm1, xmm1
    subpd xmm1, xmm0
    movapd [rdx + 16], xmm1
    ret

kokum_vec4d_abs:
    movapd xmm0, [rdi]
    andpd xmm0, [rel mask_abs]
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    andpd xmm0, [rel mask_abs]
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_min:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    minpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    movapd xmm1, [rsi + 16]
    minpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_max:
    movapd xmm0, [rdi]
    movapd xmm1, [rsi]
    maxpd xmm0, xmm1
    movapd [rdx], xmm0
    movapd xmm0, [rdi + 16]
    movapd xmm1, [rsi + 16]
    maxpd xmm0, xmm1
    movapd [rdx + 16], xmm0
    ret

kokum_vec4d_norm:
    movapd xmm0, [rdi]
    movapd xmm1, xmm0
    mulpd xmm1, xmm1
    movhlps xmm2, xmm1
    addsd xmm1, xmm2
    movapd xmm3, [rdi + 16]
    movapd xmm2, xmm3
    mulpd xmm2, xmm2
    movhlps xmm4, xmm2
    addsd xmm2, xmm4
    addsd xmm1, xmm2
    sqrtsd xmm1, xmm1
    movddup xmm1, xmm1
    divpd xmm0, xmm1
    movapd [rdx], xmm0
    divpd xmm3, xmm1
    movapd [rdx + 16], xmm3
    ret
