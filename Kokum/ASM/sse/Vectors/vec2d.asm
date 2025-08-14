global kokum_vec2d_add
global kokum_vec2d_sub
global kokum_vec2d_mul
global kokum_vec2d_div
global kokum_vec2d_scalar_mul
global kokum_vec2d_scalar_div
global kokum_vec2d_dot
global kokum_vec2d_negate
global kokum_vec2d_abs
global kokum_vec2d_min
global kokum_vec2d_max
global kokum_vec2d_norm

section .rodata align=16
mask_abs: dd 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF

section .text

kokum_vec2d_add:
    movupd xmm0, [rdi]
    movupd xmm1, [rsi]
    addpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_sub:
    movupd xmm0, [rdi]
    movupd xmm1, [rsi]
    subpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_mul:
    movupd xmm0, [rdi]
    movupd xmm1, [rsi]
    mulpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_scalar_mul:
    movss xmm1, [rsi]
    shufpd xmm1, xmm1, 0x00
    movupd xmm0, [rdi]
    mulpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_div:
    movupd xmm0, [rdi]
    movupd xmm1, [rsi]
    divpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_scalar_div:
    movss xmm1, [rsi]
    shufpd xmm1, xmm1, 0x00
    movupd xmm0, [rdi]
    divpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_dot:
    movupd xmm0, [rdi]
    movupd xmm1, [rsi]
    dppd xmm0, xmm1, 0x31
    ret


kokum_vec2d_negate:
    xorpd xmm1, xmm1
    movupd xmm0, [rdi]
    subpd xmm1, xmm0
    movupd [rdx], xmm1
    ret

kokum_vec2d_abs:
    movupd xmm0, [rdi]
    andpd xmm0, [rel mask_abs]
    movupd [rdx], xmm0
    ret

kokum_vec2d_min:
    movupd xmm0, [rdi]
    movupd xmm1, [rsi]
    minpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_max:
    movupd xmm0, [rdi]
    movupd xmm1, [rsi]
    maxpd xmm0, xmm1
    movupd [rdx], xmm0
    ret

kokum_vec2d_norm:
    movupd xmm0, [rdi]
    movapd xmm1, xmm0
    mulpd xmm1, xmm1
    movapd xmm2, xmm1
    haddpd xmm2, xmm2
    sqrtss xmm2, xmm2
    shufpd xmm2, xmm2, 0x00
    divpd xmm0, xmm2
    movupd [rsi], xmm0
    ret