
@{{BLOCK(lame)

@=======================================================================
@
@	lame, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2022-01-26, 15:11:48
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global lameTiles		@ 32 unsigned chars
lameTiles:
	.word 0x00000000,0x00220000,0x02112200,0x21111122,0x11333111,0x01111100,0x00110000,0x00000000

	.section .rodata
	.align	2
	.global lamePal		@ 32 unsigned chars
lamePal:
	.hword 0x0000,0x4231,0x7FFF,0x08E8,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(lame)
