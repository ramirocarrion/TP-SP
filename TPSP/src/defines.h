/* ** por compatibilidad se omiten tildes **
==============================================================================
TALLER System Programming - Arquitectura y Organizacion de Computadoras - FCEN
==============================================================================

  Definiciones globales del sistema.
*/

#ifndef __DEFINES_H__
#define __DEFINES_H__

/* Misc */
/* -------------------------------------------------------------------------- */
// Y Filas
#define SIZE_N 40
#define ROWS   SIZE_N

// X Columnas
#define SIZE_M 80
#define COLS   SIZE_M

/* Indices en la gdt */
/* -------------------------------------------------------------------------- */
#define GDT_COUNT         35

#define GDT_IDX_NULL_DESC 0
#define GDT_IDX_CODE_0 1
#define GDT_IDX_CODE_3 2
#define GDT_IDX_DATA_0 3
#define GDT_IDX_DATA_3 4
#define GDT_IDX_VIDEO  5


/* Offsets en la gdt */
/* -------------------------------------------------------------------------- */
#define GDT_OFF_NULL_DESC (GDT_IDX_NULL_DESC << 3)
#define GDT_OFF_VIDEO  (GDT_IDX_VIDEO << 3)

/* COMPLETAR - Valores para los selectores de segmento de la GDT 
 * Definirlos a partir de los índices de la GDT, definidos más arriba 
 * Hint: usar operadores "<<" y "|" (shift y or) */

// formato del selector de segmento, 16 bits: [0:1] RPL requested privilege level, [2] TI table indicator (0 = GDT, 1 = LDT), [3:15] index

#define GDT_CODE_0_SEL ((GDT_IDX_CODE_0 << 3) | 0) // RPL = 0, TI = 0 GDT
#define GDT_DATA_0_SEL ((GDT_IDX_DATA_0 << 3) | 0) // RPL = 0, TI = 0 GDT
#define GDT_CODE_3_SEL ((GDT_IDX_CODE_3 << 3) | 3) // RPL = 3, TI = 0 GDT
#define GDT_DATA_3_SEL ((GDT_IDX_DATA_3 << 3) | 3) // RPL = 3, TI = 0 GDT

// Macros para trabajar con segmentos de la GDT.

// SEGM_LIMIT_4KIB es el limite de segmento visto como bloques de 4KIB
// principio del ultimo bloque direccionable.
#define GDT_LIMIT_4KIB(X)  (((X) / 4096) - 1)
#define GDT_LIMIT_BYTES(X) ((X)-1)

#define GDT_LIMIT_LOW(limit)  (uint16_t)(((uint32_t)(limit)) & 0x0000FFFF)
#define GDT_LIMIT_HIGH(limit) (uint8_t)((((uint32_t)(limit)) >> 16) & 0x0F)

#define GDT_BASE_LOW(base)  (uint16_t)(((uint32_t)(base)) & 0x0000FFFF)
#define GDT_BASE_MID(base)  (uint8_t)((((uint32_t)(base)) >> 16) & 0xFF)
#define GDT_BASE_HIGH(base) (uint8_t)((((uint32_t)(base)) >> 24) & 0xFF)

/* COMPLETAR - Valores de atributos */ 
#define DESC_CODE_DATA 0x1
#define DESC_SYSTEM    0x0

#define DESC_TYPE_EXECUTE_READ 0xA
#define DESC_TYPE_READ_WRITE   0x2

#define DESC_DPL_3 0x3
#define DESC_DPL_0 0x0

#define DESC_AVL_0 0x0
#define DESC_LONG_0 0x0

#define DESC_PRESENT 0x1

#define DESC_DB_32B 0x1
#define DESC_GRANULARITY 0x1


/* COMPLETAR - Tamaños de segmentos */ 
#define BASE 0x00000000
#define FLAT_SEGM_SIZE   856686592
#define VIDEO_SEGM_SIZE  8000


/* Direcciones de memoria */
/* -------------------------------------------------------------------------- */

// direccion fisica de comienzo del bootsector (copiado)
#define BOOTSECTOR 0x00001000
// direccion fisica de comienzo del kernel
#define KERNEL 0x00001200
// direccion fisica del buffer de video
#define VIDEO 0x000B8000


#endif //  __DEFINES_H__
