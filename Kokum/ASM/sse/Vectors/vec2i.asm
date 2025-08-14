global kokum_vec2i_add
global kokum_vec2i_sub
global kokum_vec2i_mul
global kokum_vec2i_dot
global kokum_vec2i_cross
global kokum_vec2i_negate
global kokum_vec2i_abs
global kokum_vec2i_min
global kokum_vec2i_max

section .text

kokum_vec2i_add:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    paddd xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec2i_sub:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    psubd xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec2i_mul:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pmulld xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec2i_dot:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pmulld xmm0, xmm1
    movhlps xmm2, xmm0
    paddd xmm0, xmm2
    pshufd xmm2, xmm0, 1
    paddd xmm0, xmm2
    movd eax, xmm0
    ret

kokum_vec2i_negate:
    pxor xmm1, xmm1
    movdqu xmm0, [rdi]
    psubd xmm1, xmm0
    movdqu [rsi], xmm1
    ret

kokum_vec2i_abs:
    movdqu xmm0, [rdi]
    pabsd xmm0, xmm0
    movdqu [rsi], xmm0
    ret

kokum_vec2i_min:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pminsd xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec2i_max:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pmaxsd xmm0, xmm1
    movdqu [rdx], xmm0
    ret
