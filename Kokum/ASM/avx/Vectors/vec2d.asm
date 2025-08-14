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

section .rodata align=32
mask_abs: dq 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF, 0, 0

section .text

kokum_vec2d_add:
    vmovapd ymm0, [rdi]
    vmovapd ymm1, [rsi]
    vaddpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_sub:
    vmovapd ymm0, [rdi]
    vmovapd ymm1, [rsi]
    vsubpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_mul:
    vmovapd ymm0, [rdi]
    vmovapd ymm1, [rsi]
    vmulpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_div:
    vmovapd ymm0, [rdi]
    vmovapd ymm1, [rsi]
    vdivpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_scalar_mul:
    vbroadcastsd ymm1, [rsi]
    vmovapd ymm0, [rdi]
    vmulpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_scalar_div:
    vbroadcastsd ymm1, [rsi]
    vmovapd ymm0, [rdi]
    vdivpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_dot:
    vmovapd ymm0, [rdi]
    vmovapd ymm1, [rsi]
    vmulpd ymm0, ymm0, ymm1
    vhaddpd ymm0, ymm0, ymm0
    vmovsd [rdx], xmm0
    ret

kokum_vec2d_negate:
    vxorpd ymm1, ymm1, ymm1
    vmovapd ymm0, [rdi]
    vsubpd ymm0, ymm1, ymm0
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_abs:
    vmovapd ymm0, [rdi]
    vandpd ymm0, ymm0, [rel mask_abs]
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_min:
    vmovapd ymm0, [rdi]
    vmovapd ymm1, [rsi]
    vminpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_max:
    vmovapd ymm0, [rdi]
    vmovapd ymm1, [rsi]
    vmaxpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret

kokum_vec2d_norm:
    vmovapd ymm0, [rdi]
    vmulpd ymm1, ymm0, ymm0
    vhaddpd ymm1, ymm1, ymm1
    vsqrtpd ymm1, ymm1
    vdivpd ymm0, ymm0, ymm1
    vmovapd [rdx], ymm0
    ret
