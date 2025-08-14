global kokum_vec3d_add
global kokum_vec3d_sub
global kokum_vec3d_mul
global kokum_vec3d_div
global kokum_vec3d_scalar_mul
global kokum_vec3d_scalar_div
global kokum_vec3d_dot
global kokum_vec3d_negate
global kokum_vec3d_abs
global kokum_vec3d_min
global kokum_vec3d_max
global kokum_vec3d_norm

section .rodata align=32
mask_abs: dq 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF, 0x7FFFFFFFFFFFFFFF

section .text

kokum_vec3d_add:
    vmovupd ymm0, [rdi]
    vmovupd ymm1, [rsi]
    vaddpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_sub:
    vmovupd ymm0, [rdi]
    vmovupd ymm1, [rsi]
    vsubpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_mul:
    vmovupd ymm0, [rdi]
    vmovupd ymm1, [rsi]
    vmulpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_div:
    vmovupd ymm0, [rdi]
    vmovupd ymm1, [rsi]
    vdivpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_scalar_mul:
    vbroadcastsd ymm1, [rsi]
    vmovupd ymm0, [rdi]
    vmulpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_scalar_div:
    vbroadcastsd ymm1, [rsi]
    vmovupd ymm0, [rdi]
    vdivpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_dot:
    vmovupd ymm0, [rdi]
    vmovupd ymm1, [rsi]
    vmulpd ymm0, ymm0, ymm1
    vextractf128 xmm1, ymm0, 1
    vaddpd xmm0, xmm0, xmm1
    haddpd xmm0, xmm0
    vmovsd [rdx], xmm0
    ret

kokum_vec3d_negate:
    vxorpd ymm1, ymm1, ymm1
    vmovupd ymm0, [rdi]
    vsubpd ymm0, ymm1, ymm0
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_abs:
    vmovupd ymm0, [rdi]
    vandpd ymm0, ymm0, [rel mask_abs]
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_min:
    vmovupd ymm0, [rdi]
    vmovupd ymm1, [rsi]
    vminpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_max:
    vmovupd ymm0, [rdi]
    vmovupd ymm1, [rsi]
    vmaxpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret

kokum_vec3d_norm:
    vmovupd ymm0, [rdi]
    vmulpd ymm1, ymm0, ymm0
    vextractf128 xmm2, ymm1, 1
    vaddpd xmm1, xmm1, xmm2
    haddpd xmm1, xmm1
    vsqrtpd xmm1, xmm1
    vbroadcastsd ymm1, xmm1
    vdivpd ymm0, ymm0, ymm1
    vmovupd [rdx], ymm0
    ret
