global kokum_vec3f_add
global kokum_vec3f_sub
global kokum_vec3f_mul
global kokum_vec3f_div
global kokum_vec3f_scalar_mul
global kokum_vec3f_scalar_div
global kokum_vec3f_dot
global kokum_vec3f_negate
global kokum_vec3f_abs
global kokum_vec3f_min
global kokum_vec3f_max
global kokum_vec3f_norm

section .rodata align=16
mask_abs: dd 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF

section .text

kokum_vec3f_add:
    movups xmm0, [rdi]
    movups xmm1, [rsi]
    addps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_sub:
    movups xmm0, [rdi]
    movups xmm1, [rsi]
    subps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_mul:
    movups xmm0, [rdi]
    movups xmm1, [rsi]
    mulps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_scalar_mul:
    movss xmm1, [rsi]
    shufps xmm1, xmm1, 0x00
    movups xmm0, [rdi]
    mulps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_div:
    movups xmm0, [rdi]
    movups xmm1, [rsi]
    divps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_scalar_div:
    movss xmm1, [rsi]
    shufps xmm1, xmm1, 0x00
    movups xmm0, [rdi]
    divps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_dot:
    movups xmm0, [rdi]
    movups xmm1, [rsi]
    dpps xmm0, xmm1, 0x71
    ret

kokum_vec3f_negate:
    pxor xmm1, xmm1
    movups xmm0, [rdi]
    subps xmm1, xmm0
    movups [rdx], xmm1
    ret

kokum_vec3f_abs:
    movups xmm0, [rdi]
    andps xmm0, [rel mask_abs]
    movups [rdx], xmm0
    ret

kokum_vec3f_min:
    movups xmm0, [rdi]
    movups xmm1, [rsi]
    minps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_max:
    movups xmm0, [rdi]
    movups xmm1, [rsi]
    maxps xmm0, xmm1
    movups [rdx], xmm0
    ret

kokum_vec3f_norm:
    movups xmm0, [rdi]
    movaps xmm1, xmm0
    mulps xmm1, xmm1
    movaps xmm2, xmm1
    haddps xmm2, xmm2
    sqrtss xmm2, xmm2
    shufps xmm2, xmm2, 0x00
    divps xmm0, xmm2
    movups [rsi], xmm0
    ret