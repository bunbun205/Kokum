global kokum_vec4i_add
global kokum_vec4i_sub
global kokum_vec4i_mul
global kokum_vec4i_div
global kokum_vec4i_dot
global kokum_vec4i_negate
global kokum_vec4i_abs
global kokum_vec4i_min
global kokum_vec4i_max

section .text

kokum_vec4i_add:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    paddd xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec4i_sub:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    psubd xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec4i_mul:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pmulld xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec4i_div:
    ; No direct SIMD integer division, so fallback
    ; Call scalar loop or leave stub for now
    ; (You can implement a loop here)
    ret

kokum_vec4i_dot:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pmulld xmm0, xmm1
    ; horizontal add
    movhlps xmm2, xmm0
    paddd xmm0, xmm2
    pshufd xmm2, xmm0, 1
    paddd xmm0, xmm2
    movd eax, xmm0
    ret

kokum_vec4i_negate:
    pxor xmm1, xmm1
    movdqu xmm0, [rdi]
    psubd xmm1, xmm0
    movdqu [rsi], xmm1
    ret

kokum_vec4i_abs:
    movdqu xmm0, [rdi]
    pabsd xmm0, xmm0
    movdqu [rsi], xmm0
    ret

kokum_vec4i_min:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pminsd xmm0, xmm1
    movdqu [rdx], xmm0
    ret

kokum_vec4i_max:
    movdqu xmm0, [rdi]
    movdqu xmm1, [rsi]
    pmaxsd xmm0, xmm1
    movdqu [rdx], xmm0
    ret
