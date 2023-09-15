        .section .rodata

@ code_803B050 #1
        .align 2,0
        .string "pksdir0\0"
    .global gUnknown_80E7F3C
gUnknown_80E7F3C: @ 80E7F3C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

    .global gUnknown_80E7F54
gUnknown_80E7F54: @ 80E7F54
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x06, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x18, 0x00, 0x11, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

    .global gUnknown_80E7F6C
gUnknown_80E7F6C: @ 80E7F6C
        .string "Script\0"

@ code_803B050 #2
        .align 2,0
        .string "pksdir0\0"

@ code_803B050 #3
        .align 2,0
        .string "pksdir0\0"

@ code_803B050 #4
        .align 2,0
        .string "pksdir0\0"

@ code_803B050 #5
        .align 2,0
        .string "pksdir0\0"

        .align 2,0
	.global gUnknown_80E7F94
gUnknown_80E7F94: @ 80E7F94
.macro st_80E7F94 a, b, c, e, f, g, h, i, j, k, m, n
    .byte \a, \b, \c
    .align 2, 0
    .4byte \e, \f
    .2byte \g, \h
    .byte \i, \j, \k
    .align 2, 0
    .4byte \m, \n
.endm
    st_80E7F94 5, 1, 4, 0xC2B,  0x123456, 0x19, 0x182, 0x38, 8, 0x3A, sUnknown_80E8088, sUnknown_80E8070
    st_80E7F94 5, 1, 4, 0x112C, 0x123456, 4,    0x115, 0x38, 8, 0x3A, sUnknown_80E8060, sUnknown_80E8048
    st_80E7F94 5, 1, 4, 0x112D, 0x123456, 1,    0x118, 0x38, 8, 0x3A, sUnknown_80E8038, sUnknown_80E8020
    st_80E7F94 5, 1, 0, 0x1B2E, 0x123456, 7,    0x9B,  0x38, 8, 0x3A, 0,         0
    st_80E7F94 5, 1, 0, 0x903,  0x123456, 0x98, 0x9E,  0x38, 8, 0x3A, 0,         0

sUnknown_80E8020: @ 80E8020
    .string "SHOW RESCUE 00\n"
    .string " EVENT02\0"
    .align 2, 0

sUnknown_80E8038: @ 80E8038
    .string "SHOW　TITLE02\0"
    .align 2, 0

sUnknown_80E8048: @ 80E8048
    .string "SHOW RESCUE 00\n"
    .string " EVENT01\0"
    .align 2, 0

sUnknown_80E8060: @ 80E8060
    .string "SHOW　TITLE01\0"
    .align 2, 0

sUnknown_80E8070: @ 80E8070
    .string "SHOW RESCUE 00\n"
    .string " EVENT00\0"
    .align 2, 0

sUnknown_80E8088: @ 80E8088
    .string "SHOW　TITLE00\0"
    .align 2, 0

@ code_803B050 #6 (code_803C1D0)
    .string "pksdir0\0"
    .align 2, 0

	.global gUnknown_80E80A0
gUnknown_80E80A0: @ 80E80A0
    .4byte 1
    .4byte 5
    .4byte 10
    .4byte 20
    .4byte 40
    .4byte 60
    .4byte 80
    .4byte 100
    .4byte 150
    .4byte 200
    .4byte 300
    .4byte 500
    .4byte 700
    .4byte 1000
    .4byte 1500
    .4byte 2000

	.global gUnknown_80E80E0
gUnknown_80E80E0: @ 80E80E0
    .2byte 201
    .2byte 376
    .2byte 380
    .2byte 291
    .2byte 293
    .2byte 14
    .2byte 81
    .2byte 82
    .2byte 307
    .2byte 94
    .2byte 145
    .2byte 146
    .2byte 144
    .2byte 412
    .2byte 269
    .2byte 268
    .2byte 270
    .2byte 275
    .2byte 150
    .2byte 409
    .2byte 408
    .2byte 413
    .2byte 274
    .2byte 276
    .2byte 405
    .2byte 406
    .2byte 407
    .2byte 151
    .2byte 411
    .2byte 410
    .2byte 414
    .2byte 420
    .2byte 421
    .2byte 422
    .2byte 0

	.global gUnknown_80E8126
gUnknown_80E8126: @ 80E8126
    .2byte 380
    .2byte 53
    .2byte 40
    .2byte 115
    .2byte 341
    .2byte 304
    .2byte 296
    .2byte 69
    .2byte 234
    .2byte 365
    .2byte 387
    .2byte 10
    .2byte 11
    .2byte 12
    .2byte 51
    .2byte 50
    .2byte 252
    .2byte 189
    .2byte 300
    .2byte 65
    .2byte 6
    .2byte 273
    .2byte 23
    .2byte 333
    .2byte 178
    .2byte 38
    .2byte 9
    .2byte 249
    .2byte 76
    .2byte 388
    .2byte 227
    .2byte 56
    .2byte 0

	.global gUnknown_80E8168
gUnknown_80E8168: @ 80E8168
    .2byte 32
    .2byte 29
    .2byte 33
    .2byte 30
    .2byte 34
    .2byte 31
    .2byte 128
    .2byte 266
    .2byte 338
    .2byte 339
    .2byte 337
    .2byte 336

	.global gUnknown_80E8180
gUnknown_80E8180: @ 80E8180
    .2byte 44
    .2byte 116
    .2byte 70
    .2byte 116
    .2byte 102
    .2byte 116
    .2byte 299
    .2byte 116
    .2byte 44
    .2byte 111
    .2byte 191
    .2byte 111
    .2byte 25
    .2byte 108
    .2byte 133
    .2byte 108
    .2byte 37
    .2byte 113
    .2byte 58
    .2byte 113
    .2byte 133
    .2byte 113
    .2byte 61
    .2byte 114
    .2byte 90
    .2byte 114
    .2byte 120
    .2byte 114
    .2byte 133
    .2byte 114
    .2byte 296
    .2byte 114
    .2byte 30
    .2byte 112
    .2byte 33
    .2byte 112
    .2byte 35
    .2byte 112
    .2byte 39
    .2byte 112
    .2byte 325
    .2byte 112

	.global gUnknown_80E81D4
gUnknown_80E81D4: @ 80E81D4
    .2byte 23
    .2byte 93
    .2byte 24
    .2byte 93
    .2byte 373
    .2byte 98
    .2byte 292
    .2byte 97
    .2byte 332
    .2byte 92
    .2byte 119
    .2byte 88
    .2byte 280
    .2byte 87
    .2byte 372
    .2byte 98
    .2byte 387
    .2byte 101
    .2byte 308
    .2byte 97
    .2byte 309
    .2byte 97
    .2byte 168
    .2byte 97
    .2byte 159
    .2byte 88
    .2byte 416
    .2byte 96
    .2byte 133
    .2byte 86
    .2byte 74
    .2byte 98
    .2byte 167
    .2byte 97
    .2byte 246
    .2byte 91
    .2byte 339
    .2byte 97
    .2byte 95
    .2byte 98
    .2byte 59
    .2byte 87
    .2byte 185
    .2byte 98
    .2byte 70
    .2byte 89
    .2byte 71
    .2byte 89
    .2byte 194
    .2byte 88
    .2byte 245
    .2byte 91
    .2byte 252
    .2byte 102
    .2byte 190
    .2byte 86
    .2byte 196
    .2byte 96
    .2byte 325
    .2byte 86
    .2byte 326
    .2byte 86
    .2byte 107
    .2byte 92
    .2byte 264
    .2byte 90
    .2byte 125
    .2byte 90
    .2byte 269
    .2byte 87
    .2byte 302
    .2byte 86
    .2byte 160
    .2byte 88
    .2byte 162
    .2byte 86
    .2byte 249
    .2byte 88
    .2byte 57
    .2byte 92
    .2byte 161
    .2byte 86
    .2byte 259
    .2byte 86
    .2byte 390
    .2byte 91
    .2byte 21
    .2byte 86
    .2byte 22
    .2byte 86
    .2byte 139
    .2byte 98
    .2byte 138
    .2byte 98
    .2byte 58
    .2byte 87
    .2byte 410
    .2byte 88
    .2byte 68
    .2byte 92
    .2byte 149
    .2byte 100
    .2byte 127
    .2byte 97
    .2byte 380
    .2byte 86
    .2byte 381
    .2byte 99
    .2byte 143
    .2byte 86
    .2byte 140
    .2byte 98
    .2byte 141
    .2byte 98
    .2byte 262
    .2byte 92
    .2byte 8
    .2byte 88
    .2byte 9
    .2byte 88
    .2byte 83
    .2byte 86
    .2byte 104
    .2byte 94
    .2byte 105
    .2byte 94
    .2byte 291
    .2byte 97
    .2byte 115
    .2byte 86
    .2byte 311
    .2byte 89
    .2byte 310
    .2byte 89
    .2byte 343
    .2byte 88
    .2byte 192
    .2byte 89
    .2byte 277
    .2byte 89
    .2byte 10
    .2byte 97
    .2byte 303
    .2byte 88
    .2byte 130
    .2byte 88
    .2byte 78
    .2byte 87
    .2byte 38
    .2byte 87
    .2byte 228
    .2byte 86
    .2byte 306
    .2byte 96
    .2byte 182
    .2byte 89
    .2byte 255
    .2byte 88
    .2byte 99
    .2byte 88
    .2byte 44
    .2byte 89
    .2byte 328
    .2byte 102
    .2byte 229
    .2byte 97
    .2byte 411
    .2byte 94
    .2byte 232
    .2byte 94
    .2byte 287
    .2byte 101
    .2byte 98
    .2byte 88
    .2byte 235
    .2byte 86
    .2byte 169
    .2byte 93
    .2byte 63
    .2byte 96
    .2byte 314
    .2byte 86
    .2byte 290
    .2byte 97
    .2byte 94
    .2byte 99
    .2byte 128
    .2byte 86
    .2byte 129
    .2byte 88
    .2byte 81
    .2byte 90
    .2byte 92
    .2byte 99
    .2byte 93
    .2byte 99
    .2byte 349
    .2byte 87
    .2byte 67
    .2byte 92
    .2byte 14
    .2byte 97
    .2byte 341
    .2byte 93
    .2byte 329
    .2byte 102
    .2byte 54
    .2byte 88
    .2byte 330
    .2byte 102
    .2byte 318
    .2byte 86
    .2byte 299
    .2byte 89
    .2byte 256
    .2byte 94
    .2byte 400
    .2byte 100
    .2byte 19
    .2byte 86
    .2byte 55
    .2byte 88
    .2byte 42
    .2byte 93
    .2byte 76
    .2byte 98
    .2byte 75
    .2byte 98
    .2byte 48
    .2byte 97
    .2byte 307
    .2byte 96
    .2byte 112
    .2byte 94
    .2byte 111
    .2byte 94
    .2byte 396
    .2byte 88
    .2byte 272
    .2byte 98
    .2byte 247
    .2byte 88
    .2byte 356
    .2byte 89
    .2byte 384
    .2byte 99
    .2byte 344
    .2byte 88
    .2byte 106
    .2byte 92
    .2byte 360
    .2byte 86
    .2byte 145
    .2byte 90
    .2byte 135
    .2byte 90
    .2byte 27
    .2byte 94
    .2byte 28
    .2byte 94
    .2byte 117
    .2byte 88
    .2byte 397
    .2byte 88
    .2byte 90
    .2byte 88
    .2byte 288
    .2byte 86
    .2byte 367
    .2byte 88
    .2byte 134
    .2byte 88
    .2byte 279
    .2byte 89
    .2byte 87
    .2byte 88
    .2byte 278
    .2byte 89
    .2byte 382
    .2byte 99
    .2byte 413
    .2byte 102
    .2byte 270
    .2byte 88
    .2byte 121
    .2byte 88
    .2byte 123
    .2byte 97
    .2byte 41
    .2byte 93
    .2byte 301
    .2byte 86
    .2byte 15
    .2byte 97
    .2byte 97
    .2byte 96
    .2byte 96
    .2byte 96
    .2byte 7
    .2byte 88
    .2byte 276
    .2byte 96
    .2byte 388
    .2byte 96
    .2byte 227
    .2byte 96
    .2byte 363
    .2byte 98
    .2byte 300
    .2byte 89
    .2byte 51
    .2byte 94
    .2byte 116
    .2byte 88
    .2byte 399
    .2byte 100
    .2byte 298
    .2byte 89
    .2byte 391
    .2byte 91
    .2byte 102
    .2byte 89
    .2byte 402
    .2byte 102
    .2byte 152
    .2byte 89
    .2byte 333
    .2byte 92
    .2byte 170
    .2byte 88
    .2byte 386
    .2byte 96
    .2byte 359
    .2byte 100
    .2byte 358
    .2byte 86
    .2byte 315
    .2byte 97
    .2byte 238
    .2byte 97
    .2byte 50
    .2byte 94
    .2byte 419
    .2byte 96
    .2byte 316
    .2byte 97
    .2byte 248
    .2byte 88
    .2byte 250
    .2byte 91
    .2byte 253
    .2byte 101
    .2byte 181
    .2byte 90
    .2byte 84
    .2byte 86
    .2byte 85
    .2byte 86
    .2byte 260
    .2byte 86
    .2byte 109
    .2byte 93
    .2byte 73
    .2byte 88
    .2byte 294
    .2byte 97
    .2byte 176
    .2byte 86
    .2byte 175
    .2byte 86
    .2byte 319
    .2byte 86
    .2byte 118
    .2byte 88
    .2byte 364
    .2byte 88
    .2byte 392
    .2byte 91
    .2byte 393
    .2byte 91
    .2byte 11
    .2byte 97
    .2byte 385
    .2byte 89
    .2byte 257
    .2byte 94
    .2byte 347
    .2byte 87
    .2byte 43
    .2byte 89
    .2byte 353
    .2byte 94
    .2byte 103
    .2byte 89
    .2byte 312
    .2byte 86
    .2byte 365
    .2byte 88
    .2byte 34
    .2byte 93
    .2byte 31
    .2byte 93
    .2byte 29
    .2byte 93
    .2byte 32
    .2byte 93
    .2byte 30
    .2byte 93
    .2byte 33
    .2byte 93
    .2byte 52
    .2byte 86
    .2byte 240
    .2byte 101
    .2byte 61
    .2byte 88
    .2byte 186
    .2byte 88
    .2byte 62
    .2byte 88
    .2byte 60
    .2byte 88
    .2byte 195
    .2byte 88
    .2byte 317
    .2byte 97
    .2byte 284
    .2byte 88
    .2byte 177
    .2byte 96
    .2byte 178
    .2byte 96
    .2byte 369
    .2byte 94
    .2byte 357
    .2byte 89
    .2byte 231
    .2byte 86
    .2byte 324
    .2byte 98
    .2byte 394
    .2byte 88
    .2byte 86
    .2byte 88
    .2byte 233
    .2byte 102
    .2byte 348
    .2byte 87
    .2byte 320
    .2byte 86
    .2byte 157
    .2byte 87
    .2byte 148
    .2byte 100
    .2byte 282
    .2byte 87
    .2byte 296
    .2byte 88
    .2byte 295
    .2byte 88
    .2byte 12
    .2byte 97
    .2byte 237
    .2byte 97
    .2byte 352
    .2byte 86
    .2byte 187
    .2byte 89
    .2byte 350
    .2byte 96
    .2byte 267
    .2byte 86
    .2byte 361
    .2byte 93
    .2byte 46
    .2byte 97
    .2byte 47
    .2byte 97
    .2byte 236
    .2byte 88
    .2byte 322
    .2byte 92
    .2byte 122
    .2byte 96
    .2byte 261
    .2byte 92
    .2byte 91
    .2byte 88
    .2byte 338
    .2byte 97
    .2byte 273
    .2byte 98
    .2byte 395
    .2byte 88
    .2byte 173
    .2byte 86
    .2byte 13
    .2byte 97
    .2byte 25
    .2byte 90
    .2byte 36
    .2byte 86
    .2byte 18
    .2byte 86
    .2byte 17
    .2byte 86
    .2byte 172
    .2byte 90
    .2byte 35
    .2byte 86
    .2byte 4
    .2byte 87
    .2byte 120
    .2byte 88
    .2byte 155
    .2byte 87
    .2byte 354
    .2byte 94
    .2byte 191
    .2byte 89
    .2byte 241
    .2byte 86
    .2byte 100
    .2byte 90
    .2byte 374
    .2byte 88
    .2byte 146
    .2byte 87
    .2byte 136
    .2byte 87
    .2byte 65
    .2byte 96
    .2byte 126
    .2byte 87
    .2byte 351
    .2byte 96
    .2byte 230
    .2byte 97
    .2byte 40
    .2byte 86
    .2byte 2
    .2byte 89
    .2byte 1
    .2byte 89
    .2byte 3
    .2byte 89
    .2byte 142
    .2byte 98
    .2byte 265
    .2byte 87
    .2byte 174
    .2byte 86
    .2byte 355
    .2byte 94
    .2byte 336
    .2byte 90
    .2byte 197
    .2byte 101
    .2byte 144
    .2byte 91
    .2byte 39
    .2byte 86
    .2byte 234
    .2byte 86
    .2byte 366
    .2byte 88
    .2byte 153
    .2byte 89
    .2byte 88
    .2byte 93
    .2byte 89
    .2byte 93
    .2byte 239
    .2byte 97
    .2byte 304
    .2byte 88
    .2byte 254
    .2byte 101
    .2byte 53
    .2byte 86
    .2byte 108
    .2byte 86
    .2byte 275
    .2byte 87
    .2byte 346
    .2byte 88
    .2byte 345
    .2byte 88
    .2byte 163
    .2byte 86
    .2byte 401
    .2byte 100
    .2byte 331
    .2byte 102
    .2byte 286
    .2byte 101
    .2byte 16
    .2byte 86
    .2byte 77
    .2byte 87
    .2byte 188
    .2byte 89
    .2byte 137
    .2byte 86
    .2byte 258
    .2byte 86
    .2byte 379
    .2byte 86
    .2byte 337
    .2byte 90
    .2byte 244
    .2byte 87
    .2byte 321
    .2byte 92
    .2byte 243
    .2byte 87
    .2byte 156
    .2byte 87
    .2byte 69
    .2byte 89
    .2byte 110
    .2byte 93
    .2byte 289
    .2byte 86
    .2byte 293
    .2byte 97
    .2byte 183
    .2byte 88
    .2byte 184
    .2byte 88
    .2byte 342
    .2byte 93
    .2byte 101
    .2byte 90
    .2byte 56
    .2byte 92
    .2byte 251
    .2byte 88
    .2byte 283
    .2byte 88
    .2byte 147
    .2byte 100
    .2byte 151
    .2byte 96
    .2byte 150
    .2byte 96
    .2byte 266
    .2byte 86
    .2byte 375
    .2byte 88
    .2byte 200
    .2byte 99
    .2byte 263
    .2byte 91
    .2byte 154
    .2byte 89
    .2byte 404
    .2byte 102
    .2byte 132
    .2byte 86
    .2byte 403
    .2byte 102
    .2byte 72
    .2byte 88
    .2byte 179
    .2byte 90
    .2byte 180
    .2byte 90
    .2byte 49
    .2byte 97
    .2byte 114
    .2byte 89
    .2byte 368
    .2byte 94
    .2byte 199
    .2byte 88
    .2byte 80
    .2byte 88
    .2byte 79
    .2byte 88
    .2byte 198
    .2byte 101
    .2byte 327
    .2byte 101
    .2byte 313
    .2byte 86
    .2byte 193
    .2byte 97
    .2byte 389
    .2byte 91
    .2byte 371
    .2byte 98
    .2byte 64
    .2byte 96
    .2byte 271
    .2byte 98
    .2byte 383
    .2byte 99
    .2byte 164
    .2byte 86
    .2byte 268
    .2byte 90
    .2byte 26
    .2byte 90
    .2byte 335
    .2byte 90
    .2byte 285
    .2byte 88
    .2byte 334
    .2byte 90
    .2byte 113
    .2byte 86
    .2byte 20
    .2byte 86
    .2byte 408
    .2byte 100
    .2byte 409
    .2byte 100
    .2byte 398
    .2byte 88
    .2byte 131
    .2byte 88
    .2byte 45
    .2byte 89
    .2byte 305
    .2byte 96
    .2byte 171
    .2byte 88
    .2byte 5
    .2byte 87
    .2byte 6
    .2byte 87
    .2byte 370
    .2byte 98
    .2byte 242
    .2byte 86
    .2byte 124
    .2byte 91
    .2byte 274
    .2byte 96
    .2byte 362
    .2byte 98
    .2byte 323
    .2byte 86
    .2byte 297
    .2byte 88
    .2byte 82
    .2byte 90
    .2byte 406
    .2byte 91
    .2byte 407
    .2byte 102
    .2byte 405
    .2byte 98
    .2byte 412
    .2byte 100
    .2byte 166
    .2byte 97
    .2byte 165
    .2byte 97
    .2byte 37
    .2byte 87
    .2byte 340
    .2byte 89
    .2byte 281
    .2byte 87
    .2byte 189
    .2byte 89
    .2byte 158
    .2byte 88
    .2byte 66
    .2byte 92

	.global gMankeyMission
gMankeyMission: @ 80E87DC
        .string "Punish bad {COLOR_1 YELLOW}Mankey{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gSmeargleMission
gSmeargleMission: @ 80E87F4
        .string "{COLOR_1 YELLOW}Smeargle{END_COLOR_TEXT_1}{APOSTROPHE}s desperate plea!\0"
        .align 2,0

	.global gMedichamMission
gMedichamMission: @ 80E8818
        .string "{COLOR_1 YELLOW}Medicham{END_COLOR_TEXT_1}: Help me!\0"
        .align 2,0

	.global gUnknown_80E8830
gUnknown_80E8830: @ 80E8830
        .string "Deliver one {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8848
gUnknown_80E8848: @ 80E8848
        .string "One {COLOR_1 GREEN}%s{END_COLOR_TEXT_1} wanted!\0"
        .align 2,0

	.global gUnknown_80E885C
gUnknown_80E885C: @ 80E885C
        .string "Save my child!\0"
        .align 2,0

	.global gUnknown_80E886C
gUnknown_80E886C: @ 80E886C
        .string "Escort me to my love!\0"
        .align 2,0

	.global gUnknown_80E8884
gUnknown_80E8884: @ 80E8884
        .string "Near %s\0"
        .align 2,0

	.global gUnknown_80E888C
gUnknown_80E888C: @ 80E888C
        .string "Rescue Description\0"
        .align 2,0

	.global gMankeyMissionDescription
gMankeyMissionDescription: @ 80E88A0
        .string "Please punish bad {COLOR_1 YELLOW}Mankey{END_COLOR_TEXT_1}{APOSTROPHE}s gang.\0"
        .align 2,0

	.global gSmeargleMissionDescription
gSmeargleMissionDescription: @ 80E88C8
        .string "I didn{APOSTROPHE}t want to become a grown-up{COMMA} so I\n"
        .string "fled{COMMA} but now I{APOSTROPHE}ve lost my way! Help!\0"
        .align 2,0

	.global gMedichamMissionDescription
gMedichamMissionDescription: @ 80E8920
        .string "This is {COLOR_1 YELLOW}Medicham{END_COLOR_TEXT_1}. Rescue me{COMMA} please!\n"
        .string "The reward is a secret"
        .byte 0x81, 0x60
        .string "♪ "
        .align 2,0

	.global gUnknown_80E8968
gUnknown_80E8968: @ 80E8968
        .string "With the item {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}{COMMA} I can\n"
        .string "evolve! I{APOSTROPHE}m yearning to evolve! Help!\0"
        .align 2,0

	.global gUnknown_80E89B0
gUnknown_80E89B0: @ 80E89B0
        .string "The {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}! What I love to eat\n"
        .string "and can{APOSTROPHE}t live without! Please get one!\0"
        .align 2,0

	.global gUnknown_80E89FC
gUnknown_80E89FC: @ 80E89FC
        .string "This is a rescue through communication.\n"
        .string "Get a friend to help you!\0"
        .align 2,0

	.global gUnknown_80E8A40
gUnknown_80E8A40: @ 80E8A40
        .string "This is a rescue through communication.\n"
        .string "Rescue a friend!\0"
        .align 2,0

	.global gUnknown_80E8A7C
gUnknown_80E8A7C: @ 80E8A7C
        .string "This is a rescue through communication.\n"
        .string "Send your thanks to your friend!\0"
        .align 2,0

	.global gUnknown_80E8AC8
gUnknown_80E8AC8: @ 80E8AC8
        .string "Client:\0"
        .align 2,0

	.global gUnknown_80E8AD0
gUnknown_80E8AD0: @ 80E8AD0
        .string "%s{COLOR_1 GREEN}"
        .byte 0x81
        .string "i%s"
        .byte 0x81
        .string "j{END_COLOR_TEXT_1}\0"
        .align 2,0

	.global gUnknown_80E8AE0
gUnknown_80E8AE0: @ 80E8AE0
        .string "Objective:\0"
        .align 2,0

	.global gUnknown_80E8AEC
gUnknown_80E8AEC: @ 80E8AEC
        .string "Friend Rescue\0"
        .align 2,0

	.global gUnknown_80E8AFC
gUnknown_80E8AFC: @ 80E8AFC
        .string "Deliver {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8B10
gUnknown_80E8B10: @ 80E8B10
        .string "Find {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8B20
gUnknown_80E8B20: @ 80E8B20
        .string "Help me.\0"
        .align 2,0

	.global gUnknown_80E8B2C
gUnknown_80E8B2C: @ 80E8B2C
        .string "Escort to {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gUnknown_80E8B40
gUnknown_80E8B40: @ 80E8B40
        .string "Find {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

	.global gSpecialMissionText
gSpecialMissionText: @ 80E8B50
        .string "Special mission\0"
        .align 2,0

	.global gPlaceText
gPlaceText: @ 80E8B60
        .string "Place:\0"
        .align 2,0

	.global gDifficultyText
gDifficultyText: @ 80E8B68
        .string "Difficulty:\0"
        .align 2,0

	.global gRewardText
gRewardText: @ 80E8B74
        .string "Reward:\0"
        .align 2,0

	.global gUnknown_80E8B7C
gUnknown_80E8B7C: @ 80E8B7C
        .string "Wonder Mail:\0"
        .align 2,0

@ code_803B050 #7
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_80E8B94
gUnknown_80E8B94: @ 80E8B94
        .4byte UnkData_80E8BC8
        .4byte UnkData_80E8BC4
        .4byte UnkData_80E8BC0
        .4byte UnkData_80E8BBC
        .4byte UnkData_80E8BB8
        .4byte UnkData_80E8BB4
        .4byte UnkData_80E8BB0

        .global UnkData_80E8BB0
        UnkData_80E8BB0:
        .byte 0x83, 0xc3, 0x00, 0x00

        .global UnkData_80E8BB4
        UnkData_80E8BB4:
        .byte 0x83, 0xc2, 0x00, 0x00

        .global UnkData_80E8BB8
        UnkData_80E8BB8:
        .byte 0x83, 0xc1, 0x00, 0x00

        .global UnkData_80E8BBC
        UnkData_80E8BBC:
        .byte 0x83, 0xc0, 0x00, 0x00

        .global UnkData_80E8BC0
        UnkData_80E8BC0:
        .byte 0x87, 0x40, 0x00, 0x00

        .global UnkData_80E8BC4
        UnkData_80E8BC4:
        .byte 0x84, 0x87, 0x00, 0x00

        .global UnkData_80E8BC8
        UnkData_80E8BC8:
        .byte 0x81, 0x40, 0x00, 0x00


	.global gUnknown_80E8BCC
gUnknown_80E8BCC: @ 80E8BCC
        .4byte UnkData_80E8BC8
        .4byte SuspendText
        .4byte TakeJobText
        .4byte DoneText

        .global DoneText
        DoneText:
        .string "Done\0"
        .align 2,0

        .global TakeJobText
        TakeJobText:
        .string "Take Job\0"
        .align 2,0

        .global SuspendText
        SuspendText:
        .string "Suspend\0"
        .align 2,0

	.global gUnknown_80E8BF8
gUnknown_80E8BF8: @ 80E8BF8
    .4byte sUnknown_80E8C40
    .4byte sUnknown_80E8C38
    .4byte sUnknown_80E8C30
    .4byte sUnknown_80E8C28
    .4byte sUnknown_80E8C20
    .4byte sUnknown_80E8C18
    .4byte sUnknown_80E8C14

sUnknown_80E8C14: @ 80E8C14
    .string "{STAR_BULLET}\0"
    .align 2, 0

sUnknown_80E8C18: @ 80E8C18
    .string "{COLOR_1 RED}S{END_COLOR_TEXT_1}\0"
    .align 2, 0

sUnknown_80E8C20: @ 80E8C20
    .string "{COLOR_1 CYAN}A{END_COLOR_TEXT_1}\0"
    .align 2, 0

sUnknown_80E8C28: @ 80E8C28
    .string "{COLOR_1 CYAN}B{END_COLOR_TEXT_1}\0"
    .align 2, 0

sUnknown_80E8C30: @ 80E8C30
    .string "{COLOR_1 GREEN}C{END_COLOR_TEXT_1}\0"
    .align 2, 0

sUnknown_80E8C38: @ 80E8C38
    .string "{COLOR_1 GREEN}D{END_COLOR_TEXT_1}\0"
    .align 2, 0

sUnknown_80E8C40: @ 80E8C40
    .string "{COLOR_1 WHITE}E{END_COLOR_TEXT_1}\0"
    .align 2, 0

	.global gMissionRewardText
gMissionRewardText: @ 80E8C48
    .4byte sUnknown_80E8C90
    .4byte sUnknown_80E8C84
    .4byte sUnknown_80E8C7C
    .4byte sUnknown_80E8C70
    .4byte sUnknown_80E8C64
    .4byte sUnknown_80E8C60

sUnknown_80E8C60: @ 80E8C60
    .string "???\0"
    .align 2, 0

sUnknown_80E8C64: @ 80E8C64
    .string "Friend Area\0"
    .align 2, 0

sUnknown_80E8C70: @ 80E8C70
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1} + ?\0"
    .align 2, 0

sUnknown_80E8C7C: @ 80E8C7C
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}\0"
    .align 2, 0

sUnknown_80E8C84: @ 80E8C84
    .string "%d {POKE} + ?\0"
    .align 2, 0

sUnknown_80E8C90: @ 80E8C90
    .string "%d {POKE}\0"
    .align 2, 0

	.global gUnknown_80E8C98
gUnknown_80E8C98: @ 80E8C98
    .4byte sUnknown_80E8DDC
    .4byte sUnknown_80E8DC8
    .4byte sUnknown_80E8DB4
    .4byte sUnknown_80E8DA4
    .4byte sUnknown_80E8D88
    .4byte sUnknown_80E8D7C
    .4byte sUnknown_80E8D6C
    .4byte sUnknown_80E8D5C
    .4byte sUnknown_80E8D44
    .4byte sUnknown_80E8D28
    .4byte sUnknown_80E8D18
    .4byte sUnknown_80E8D0C
    .4byte sUnknown_80E8CF4
    .4byte sUnknown_80E8CE0
    .4byte sUnknown_80E8CD4

sUnknown_80E8CD4: @ 80E8CD4
    .string "Help me!\0"
    .align 2, 0

sUnknown_80E8CE0: @ 80E8CE0
    .string "I can{APOSTROPHE}t get home!\0"
    .align 2, 0

sUnknown_80E8CF4: @ 80E8CF4
    .string "I{APOSTROPHE}m sad and lonely.\0"
    .align 2, 0

sUnknown_80E8D0C: @ 80E8D0C
    .string "Where am I?\0"
    .align 2, 0

sUnknown_80E8D18: @ 80E8D18
    .string "I was KO{APOSTROPHE}d...\0"
    .align 2, 0

sUnknown_80E8D28: @ 80E8D28
    .string "I{APOSTROPHE}m too tired to move.\0"
    .align 2, 0

sUnknown_80E8D44: @ 80E8D44
    .string "I{APOSTROPHE}m not a fighter...\0"
    .align 2, 0

sUnknown_80E8D5C: @ 80E8D5C
    .string "I fainted...\0"
    .align 2, 0

sUnknown_80E8D6C: @ 80E8D6C
    .string "I was attacked!\0"
    .align 2, 0

sUnknown_80E8D7C: @ 80E8D7C
    .string "I{APOSTROPHE}m lost.\0"
    .align 2, 0

sUnknown_80E8D88: @ 80E8D88
    .string "I can{APOSTROPHE}t seem to get out.\0"
    .align 2, 0

sUnknown_80E8DA4: @ 80E8DA4
    .string "I{APOSTROPHE}m scared!\0"
    .align 2, 0

sUnknown_80E8DB4: @ 80E8DB4
    .string "I{APOSTROPHE}m in trouble...\0"
    .align 2, 0

sUnknown_80E8DC8: @ 80E8DC8
    .string "I can{APOSTROPHE}t get out!\0"
    .align 2, 0

sUnknown_80E8DDC: @ 80E8DDC
    .string "Help!\0"
    .align 2, 0

	.global gUnknown_80E8DE4
gUnknown_80E8DE4: @ 80E8DE4
    .4byte sUnknown_80E8F7C
    .4byte sUnknown_80E8F50
    .4byte sUnknown_80E8F2C
    .4byte sUnknown_80E8F10
    .4byte sUnknown_80E8EF8
    .4byte sUnknown_80E8ED0
    .4byte sUnknown_80E8EB4
    .4byte sUnknown_80E8E98
    .4byte sUnknown_80E8E80
    .4byte sUnknown_80E8E6C
    .4byte sUnknown_80E8E4C
    .4byte sUnknown_80E8E2C
    .4byte sUnknown_80E8E18

sUnknown_80E8E18: @ 80E8E18
    .string "I{APOSTROPHE}m famished...\0"
    .align 2, 0

sUnknown_80E8E2C: @ 80E8E2C
    .string "I can{APOSTROPHE}t move another step.\0"
    .align 2, 0

sUnknown_80E8E4C: @ 80E8E4C
    .string "Whoa! It{APOSTROPHE}s too rough here...\0"
    .align 2, 0

sUnknown_80E8E6C: @ 80E8E6C
    .string "I was done in...\0"
    .align 2, 0

sUnknown_80E8E80: @ 80E8E80
    .string "I lost in a battle...\0"
    .align 2, 0

sUnknown_80E8E98: @ 80E8E98
    .string "I{APOSTROPHE}m close to fainting...\0"
    .align 2, 0

sUnknown_80E8EB4: @ 80E8EB4
    .string "I{APOSTROPHE}ve reached my limit...\0"
    .align 2, 0

sUnknown_80E8ED0: @ 80E8ED0
    .string "Fighting the tough foe was a mistake...\0"
    .align 2, 0

sUnknown_80E8EF8: @ 80E8EF8
    .string "This dungeon is scary!\0"
    .align 2, 0

sUnknown_80E8F10: @ 80E8F10
    .string "I got lost in this dungeon!\0"
    .align 2, 0

sUnknown_80E8F2C: @ 80E8F2C
    .string "I{APOSTROPHE}m simply no good at fighting.\0"
    .align 2, 0

sUnknown_80E8F50: @ 80E8F50
    .string "I was attacked when I was sitting still!\0"
    .align 2, 0

sUnknown_80E8F7C: @ 80E8F7C
    .string "I don{APOSTROPHE}t know how I did it{COMMA} but I can{APOSTROPHE}t exit!\0"
    .align 2, 0

	.global gUnknown_80E8FB0
gUnknown_80E8FB0: @ 80E8FB0
    .4byte sUnknown_80E90F4
    .4byte sUnknown_80E90E8
    .4byte sUnknown_80E90D4
    .4byte sUnknown_80E90B4
    .4byte sUnknown_80E9090
    .4byte sUnknown_80E907C
    .4byte sUnknown_80E9064
    .4byte sUnknown_80E903C
    .4byte sUnknown_80E9024
    .4byte sUnknown_80E900C
    .4byte sUnknown_80E8DDC
    .4byte sUnknown_80E8FF4
    .4byte sUnknown_80E8FE4

sUnknown_80E8FE4: @ 80E8FE4
    .string "Aiyeeeeeeeeh!\0"
    .align 2, 0

sUnknown_80E8FF4: @ 80E8FF4
    .string "...Gasp! Waaaaaaaah!\0"
    .align 2, 0

sUnknown_80E900C: @ 80E900C
    .string "Someone{COMMA} please help!\0"
    .align 2, 0

sUnknown_80E9024: @ 80E9024
    .string "Rescue is requested!\0"
    .align 2, 0

sUnknown_80E903C: @ 80E903C
    .string "My consciousness is slipping... Help...\0"
    .align 2, 0

sUnknown_80E9064: @ 80E9064
    .string "Wroooooaaar! Someone!\0"
    .align 2, 0

sUnknown_80E907C: @ 80E907C
    .string "Where am I? Help!\0"
    .align 2, 0

sUnknown_80E9090: @ 80E9090
    .string "Why? Why is everyone attacking me?\0"
    .align 2, 0

sUnknown_80E90B4: @ 80E90B4
    .string "I feel faint... Please help...\0"
    .align 2, 0

sUnknown_80E90D4: @ 80E90D4
    .string "Someone{COMMA} help!\0"
    .align 2, 0

sUnknown_80E90E8: @ 80E90E8
    .string "Someone!\0"
    .align 2, 0

sUnknown_80E90F4: @ 80E90F4
    .string "Please{COMMA} I need help!\0"
    .align 2, 0

	.global gUnknown_80E910C
gUnknown_80E910C: @ 80E910C
    .4byte sUnknown_80E91BC
    .4byte sUnknown_80E91A8
    .4byte sUnknown_80E9190
    .4byte sUnknown_80E917C
    .4byte sUnknown_80E8DDC
    .4byte sUnknown_80E9170
    .4byte sUnknown_80E9160
    .4byte sUnknown_80E914C
    .4byte sUnknown_80E9144
    .4byte sUnknown_80E9134

sUnknown_80E9134: @ 80E9134
    .string "Disappearance!\0"
    .align 2, 0

sUnknown_80E9144: @ 80E9144
    .string "Hurry!\0"
    .align 2, 0

sUnknown_80E914C: @ 80E914C
    .string "Hasn{APOSTROPHE}t come back.\0"
    .align 2, 0

sUnknown_80E9160: @ 80E9160
    .string "I{APOSTROPHE}m worried.\0"
    .align 2, 0

sUnknown_80E9170: @ 80E9170
    .string "Somebody!\0"
    .align 2, 0

sUnknown_80E917C: @ 80E917C
    .string "Failed to return.\0"
    .align 2, 0

sUnknown_80E9190: @ 80E9190
    .string "Hurry{COMMA} save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

sUnknown_80E91A8: @ 80E91A8
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} needs help!\0"
    .align 2, 0

sUnknown_80E91BC: @ 80E91BC
    .string "Please help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

	.global gUnknown_80E91D4
gUnknown_80E91D4: @ 80E91D4
    .4byte sUnknown_80E97FC
    .4byte sUnknown_80E97E0
    .4byte sUnknown_80E97C4
    .4byte sUnknown_80E97A0
    .4byte sUnknown_80E9788
    .4byte sUnknown_80E976C
    .4byte sUnknown_80E9748
    .4byte sUnknown_80E9728
    .4byte sUnknown_80E9708
    .4byte sUnknown_80E96E4
    .4byte sUnknown_80E96C4
    .4byte sUnknown_80E96A8
    .4byte sUnknown_80E9688
    .4byte sUnknown_80E9668
    .4byte sUnknown_80E9650
    .4byte sUnknown_80E9628
    .4byte sUnknown_80E9608
    .4byte sUnknown_80E95EC
    .4byte sUnknown_80E95C8
    .4byte sUnknown_80E95AC
    .4byte sUnknown_80E9588
    .4byte sUnknown_80E955C
    .4byte sUnknown_80E9538
    .4byte sUnknown_80E951C
    .4byte sUnknown_80E94FC
    .4byte sUnknown_80E94E0
    .4byte sUnknown_80E94C0
    .4byte sUnknown_80E94A0
    .4byte sUnknown_80E9480
    .4byte sUnknown_80E9460
    .4byte sUnknown_80E9440
    .4byte sUnknown_80E9420
    .4byte sUnknown_80E9400
    .4byte sUnknown_80E93E0
    .4byte sUnknown_80E93B8
    .4byte sUnknown_80E9394
    .4byte sUnknown_80E9378
    .4byte sUnknown_80E9358
    .4byte sUnknown_80E9344
    .4byte sUnknown_80E9328
    .4byte sUnknown_80E9300
    .4byte sUnknown_80E92E0
    .4byte sUnknown_80E92C4
    .4byte sUnknown_80E92A4
    .4byte sUnknown_80E9288

sUnknown_80E9288: @ 80E9288
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} fell into a trap!\0"
    .align 2, 0

sUnknown_80E92A4: @ 80E92A4
    .string "I lost contact with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

sUnknown_80E92C4: @ 80E92C4
    .string "I can{APOSTROPHE}t contact {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

sUnknown_80E92E0: @ 80E92E0
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} can{APOSTROPHE}t walk anymore!\0"
    .align 2, 0

sUnknown_80E9300: @ 80E9300
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{APOSTROPHE}s been missing three days!\0"
    .align 2, 0

sUnknown_80E9328: @ 80E9328
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} went the wrong way!\0"
    .align 2, 0

sUnknown_80E9344: @ 80E9344
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is lost!\0"
    .align 2, 0

sUnknown_80E9358: @ 80E9358
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} appears to be stuck!\0"
    .align 2, 0

sUnknown_80E9378: @ 80E9378
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} appears to be lost!\0"
    .align 2, 0

sUnknown_80E9394: @ 80E9394
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} may have had an accident!\0"
    .align 2, 0

sUnknown_80E93B8: @ 80E93B8
    .string "I{APOSTROPHE}m worried for {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{APOSTROPHE}s safety!\0"
    .align 2, 0

sUnknown_80E93E0: @ 80E93E0
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is fighting all alone!\0"
    .align 2, 0

sUnknown_80E9400: @ 80E9400
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is too hungry to move!\0"
    .align 2, 0

sUnknown_80E9420: @ 80E9420
    .string "Hurry{COMMA} bring back {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
    .align 2, 0

sUnknown_80E9440: @ 80E9440
    .string "I got separated from {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
    .align 2, 0

sUnknown_80E9460: @ 80E9460
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is running out of time!\0"
    .align 2, 0

sUnknown_80E9480: @ 80E9480
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} was attacked{COMMA} maybe!\0"
    .align 2, 0

sUnknown_80E94A0: @ 80E94A0
    .string "Something happened to {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

sUnknown_80E94C0: @ 80E94C0
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} appears to be trapped!\0"
    .align 2, 0

sUnknown_80E94E0: @ 80E94E0
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is stuck in a cave!\0"
    .align 2, 0

sUnknown_80E94FC: @ 80E94FC
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} appears to be helpless!\0"
    .align 2, 0

sUnknown_80E951C: @ 80E951C
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} hasn{APOSTROPHE}t reemerged!\0"
    .align 2, 0

sUnknown_80E9538: @ 80E9538
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} was attacked by assailants!\0"
    .align 2, 0

sUnknown_80E955C: @ 80E955C
    .string "It appears as if {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} can{APOSTROPHE}t escape!\0"
    .align 2, 0

sUnknown_80E9588: @ 80E9588
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} may have fainted already!\0"
    .align 2, 0

sUnknown_80E95AC: @ 80E95AC
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is about to faint!\0"
    .align 2, 0

sUnknown_80E95C8: @ 80E95C8
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{APOSTROPHE}s been gone a long time!\0"
    .align 2, 0

sUnknown_80E95EC: @ 80E95EC
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} has been cornered!\0"
    .align 2, 0

sUnknown_80E9608: @ 80E9608
    .string "I{APOSTROPHE}m worried about {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

sUnknown_80E9628: @ 80E9628
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{APOSTROPHE}s whereabouts are unknown!\0"
    .align 2, 0

sUnknown_80E9650: @ 80E9650
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} was paralyzed!\0"
    .align 2, 0

sUnknown_80E9668: @ 80E9668
    .string "Trouble may have found {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

sUnknown_80E9688: @ 80E9688
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} appears to be freezing!\0"
    .align 2, 0

sUnknown_80E96A8: @ 80E96A8
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} may be confused!\0"
    .align 2, 0

sUnknown_80E96C4: @ 80E96C4
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is too scared to move!\0"
    .align 2, 0

sUnknown_80E96E4: @ 80E96E4
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} went missing this morning!\0"
    .align 2, 0

sUnknown_80E9708: @ 80E9708
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} appears to be injured!\0"
    .align 2, 0

sUnknown_80E9728: @ 80E9728
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} may be facing danger!\0"
    .align 2, 0

sUnknown_80E9748: @ 80E9748
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} might be unable to return.\0"
    .align 2, 0

sUnknown_80E976C: @ 80E976C
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} hasn{APOSTROPHE}t come back!\0"
    .align 2, 0

sUnknown_80E9788: @ 80E9788
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} can{APOSTROPHE}t swim!\0"
    .align 2, 0

sUnknown_80E97A0: @ 80E97A0
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} hasn{APOSTROPHE}t been heard from!\0"
    .align 2, 0

sUnknown_80E97C4: @ 80E97C4
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is still missing.\0"
    .align 2, 0

sUnknown_80E97E0: @ 80E97E0
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} may be endangered!\0"
    .align 2, 0

sUnknown_80E97FC: @ 80E97FC
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} passed out from the heat!\0"
    .align 2, 0

	.global gUnknown_80E9820
gUnknown_80E9820: @ 80E9820
    .4byte sUnknown_80E9908
    .4byte sUnknown_80E98F0
    .4byte sUnknown_80E98DC
    .4byte sUnknown_80E98B4
    .4byte sUnknown_80E8CD4
    .4byte sUnknown_80E9898
    .4byte sUnknown_80E90D4
    .4byte sUnknown_80E987C
    .4byte sUnknown_80E985C
    .4byte sUnknown_80E9848

sUnknown_80E9848: @ 80E9848
    .string "Reward upon rescue!\0"
    .align 2, 0

sUnknown_80E985C: @ 80E985C
    .string "A rescue is urgently needed!\0"
    .align 2, 0

sUnknown_80E987C: @ 80E987C
    .string "Please send a rescue team!\0"
    .align 2, 0

sUnknown_80E9898: @ 80E9898
    .string "I{APOSTROPHE}m pleading for help!\0"
    .align 2, 0

sUnknown_80E98B4: @ 80E98B4
    .string "I don{APOSTROPHE}t care who it is! Please help!\0"
    .align 2, 0

sUnknown_80E98DC: @ 80E98DC
    .string "Someone! Anyone?\0"
    .align 2, 0

sUnknown_80E98F0: @ 80E98F0
    .string "Please! I need help!\0"
    .align 2, 0

sUnknown_80E9908: @ 80E9908
    .string "Please! Someone help!\0"
    .align 2, 0

	.global gUnknown_80E9920
gUnknown_80E9920: @ 80E9920
.macro st_80E9920 a, b, c
    .2byte \a, \b
    .4byte \c
.endm
    st_80E9920 15, 13, sUnknown_80E9F5C
    st_80E9920 18, 16, sUnknown_80E9F24
    st_80E9920 20, 19, sUnknown_80E9ED8
    st_80E9920 26, 172, sUnknown_80E9E80
    st_80E9920 36, 173, sUnknown_80E9E40
    st_80E9920 40, 174, sUnknown_80E9DFC
    st_80E9920 169, 41, sUnknown_80E9DA4
    st_80E9920 45, 43, sUnknown_80E9D50
    st_80E9920 62, 60, sUnknown_80E9D04
    st_80E9920 176, 175, sUnknown_80E9CC4
    st_80E9920 184, 323, sUnknown_80E9C80
    st_80E9920 242, 241, sUnknown_80E9C38
    st_80E9920 257, 256, sUnknown_80E9BFC
    st_80E9920 125, 264, sUnknown_80E9BAC
    st_80E9920 126, 265, sUnknown_80E9B58
    st_80E9920 273, 271, sUnknown_80E9B18
    st_80E9920 292, 290, sUnknown_80E9ACC
    st_80E9920 331, 329, sUnknown_80E9A94
    st_80E9920 355, 353, sUnknown_80E9A54
    st_80E9920 393, 391, sUnknown_80E9A0C
    st_80E9920 302, 301, sUnknown_80E99C8

sUnknown_80E99C8: @ 80E99C8
    .string "Please look for Taillow!\n"
    .string "My baby is very timid{COMMA} so I{APOSTROPHE}m worried!\0"
    .align 2, 0

sUnknown_80E9A0C: @ 80E9A0C
    .string "Save my baby Spheal! My baby is easy to\n"
    .string "spot because she likes to roll!\0"
    .align 2, 0

sUnknown_80E9A54: @ 80E9A54
    .string "Please find my little Trapinch!\n"
    .string "My baby is probably lying low!\0"
    .align 2, 0

sUnknown_80E9A94: @ 80E9A94
    .string "Please find my Aron!\n"
    .string "He{APOSTROPHE}s my only child! Please help!\0"
    .align 2, 0

sUnknown_80E9ACC: @ 80E9ACC
    .string "My Wurmple went missing! Please look\n"
    .string "for the cute spikes on his rear end!\0"
    .align 2, 0

sUnknown_80E9B18: @ 80E9B18
    .string "Please search for Larvitar!\n"
    .string "He loves to eat dirt! I need help!\0"
    .align 2, 0

sUnknown_80E9B58: @ 80E9B58
    .string "My baby Magby is lost. I{APOSTROPHE}m worried sick.\n"
    .string "She{APOSTROPHE}s a cheerful child who loves fire.\0"
    .align 2, 0

sUnknown_80E9BAC: @ 80E9BAC
    .string "My son can be wild with thunderbolts{COMMA}\n"
    .string "but he{APOSTROPHE}s kindhearted. Please help!\0"
    .align 2, 0

sUnknown_80E9BFC: @ 80E9BFC
    .string "Please look for Phanpy!\n"
    .string "My son has a distinctive long nose!\0"
    .align 2, 0

sUnknown_80E9C38: @ 80E9C38
    .string "Please find Teddiursa! My baby{APOSTROPHE}s head\n"
    .string "has a cute crescent mark! Help!\0"
    .align 2, 0

sUnknown_80E9C80: @ 80E9C80
    .string "Please save my adorable Azurill!\n"
    .string "Watch for a round and bouncy tail!\0"
    .align 2, 0

sUnknown_80E9CC4: @ 80E9CC4
    .string "Help! Togepi{APOSTROPHE}s just a baby!\n"
    .string "I{APOSTROPHE}m worried sick! Please help!\0"
    .align 2, 0

sUnknown_80E9D04: @ 80E9D04
    .string "My baby Poliwag! He wandered off...\n"
    .string "He only just learned how to walk! Help!\0"
    .align 2, 0

sUnknown_80E9D50: @ 80E9D50
    .string "Oddish disappeared from sight! She may be\n"
    .string "buried somewhere! Someone{COMMA} please help!\0"
    .align 2, 0

sUnknown_80E9DA4: @ 80E9DA4
    .string "Please rescue Zubat! He{APOSTROPHE}s so young he\n"
    .string "can{APOSTROPHE}t even hang from cavern ceilings well!\0"
    .align 2, 0

sUnknown_80E9DFC: @ 80E9DFC
    .string "Please find Igglybuff! Oh{COMMA} where did that\n"
    .string "child roll off to?! Oh!\0"
    .align 2, 0

sUnknown_80E9E40: @ 80E9E40
    .string "Cleffa disappeared! Please let me know\n"
    .string "if you find my child!\0"
    .align 2, 0

sUnknown_80E9E80: @ 80E9E80
    .string "Please rescue Pichu! He{APOSTROPHE}s a little cutie\n"
    .string "who can{APOSTROPHE}t charge power well yet. Please!\0"
    .align 2, 0

sUnknown_80E9ED8: @ 80E9ED8
    .string "Rattata is missing! My precious child!\n"
    .string "Please{COMMA} won{APOSTROPHE}t someone help me?\0"
    .align 2, 0

sUnknown_80E9F24: @ 80E9F24
    .string "Oh{COMMA} my cute little Pidgey!\n"
    .string "Please{COMMA} someone help!\0"
    .align 2, 0

sUnknown_80E9F5C: @ 80E9F5C
    .string "Please rescue Weedle!\n"
    .string "He{APOSTROPHE}s my son! Please!\0"
    .align 2, 0

	.global gUnknown_80E9F8C
gUnknown_80E9F8C: @ 80E9F8C
.macro st_80E9F8C a, b, c, d
    .2byte \a, \b
    .4byte \c, \d
.endm
    st_80E9F8C 103, 85, sUnknown_80EAE44, sUnknown_80EADFC
    st_80E9F8C 22, 112, sUnknown_80EAE44, sUnknown_80EADD0
    st_80E9F8C 90, 394, sUnknown_80EAE44, sUnknown_80EAD94
    st_80E9F8C 89, 342, sUnknown_80EAE44, sUnknown_80EAD50
    st_80E9F8C 52, 325, sUnknown_80EAE44, sUnknown_80EAD20
    st_80E9F8C 129, 374, sUnknown_80EAE44, sUnknown_80EACD4
    st_80E9F8C 13, 290, sUnknown_80EAE44, sUnknown_80EAC88
    st_80E9F8C 293, 291, sUnknown_80EAE44, sUnknown_80EAC38
    st_80E9F8C 301, 16, sUnknown_80EAE44, sUnknown_80EABE8
    st_80E9F8C 37, 347, sUnknown_80EAE44, sUnknown_80EABA8
    st_80E9F8C 174, 173, sUnknown_80EAE44, sUnknown_80EAB68
    st_80E9F8C 49, 294, sUnknown_80EAE44, sUnknown_80EAB10
    st_80E9F8C 313, 57, sUnknown_80EAE44, sUnknown_80EAAC8
    st_80E9F8C 286, 58, sUnknown_80EAE44, sUnknown_80EAA84
    st_80E9F8C 69, 238, sUnknown_80EAE44, sUnknown_80EAA34
    st_80E9F8C 86, 392, sUnknown_80EAE44, sUnknown_80EA9F8
    st_80E9F8C 97, 122, sUnknown_80EAE44, sUnknown_80EA9A4
    st_80E9F8C 98, 366, sUnknown_80EAE44, sUnknown_80EA968
    st_80E9F8C 143, 314, sUnknown_80EAE44, sUnknown_80EA914
    st_80E9F8C 127, 239, sUnknown_80EAE44, sUnknown_80EA8D0
    st_80E9F8C 240, 360, sUnknown_80EAE44, sUnknown_80EA880
    st_80E9F8C 323, 175, sUnknown_80EAE44, sUnknown_80EA84C
    st_80E9F8C 132, 185, sUnknown_80EAE44, sUnknown_80EA7FC
    st_80E9F8C 241, 352, sUnknown_80EAE44, sUnknown_80EA7A8
    st_80E9F8C 79, 312, sUnknown_80EAE44, sUnknown_80EA784
    st_80E9F8C 164, 198, sUnknown_80EAE44, sUnknown_80EA730
    st_80E9F8C 340, 182, sUnknown_80EAE44, sUnknown_80EA6E4
    st_80E9F8C 250, 304, sUnknown_80EAE44, sUnknown_80EA698
    st_80E9F8C 397, 38, sUnknown_80EAE44, sUnknown_80EA650
    st_80E9F8C 187, 386, sUnknown_80EAE44, sUnknown_80EA614
    st_80E9F8C 200, 381, sUnknown_80EAE44, sUnknown_80EA5C4
    st_80E9F8C 247, 398, sUnknown_80EAE44, sUnknown_80EA57C
    st_80E9F8C 176, 267, sUnknown_80EAE44, sUnknown_80EA534
    st_80E9F8C 32, 29, sUnknown_80EA51C, sUnknown_80EA4E4
    st_80E9F8C 33, 30, sUnknown_80EA51C, sUnknown_80EA4A0
    st_80E9F8C 34, 31, sUnknown_80EA51C, sUnknown_80EA45C
    st_80E9F8C 128, 266, sUnknown_80EA51C, sUnknown_80EA41C
    st_80E9F8C 338, 339, sUnknown_80EA51C, sUnknown_80EA3DC
    st_80E9F8C 337, 336, sUnknown_80EA51C, sUnknown_80EA398
    st_80E9F8C 360, 361, sUnknown_80EA384, sUnknown_80EA33C
    st_80E9F8C 106, 107, sUnknown_80EA384, sUnknown_80EA30C
    st_80E9F8C 362, 363, sUnknown_80EA384, sUnknown_80EA2BC
    st_80E9F8C 138, 140, sUnknown_80EA384, sUnknown_80EA26C
    st_80E9F8C 370, 372, sUnknown_80EA384, sUnknown_80EA214
    st_80E9F8C 172, 172, sUnknown_80EA1FC, sUnknown_80EA1A8

sUnknown_80EA1A8: @ 80EA1A8
    .string "My little brother Pichu disappeared!\n"
    .string "I{APOSTROPHE}m really worried! Someone{COMMA} please help!\0"
    .align 2, 0

sUnknown_80EA1FC: @ 80EA1FC
    .string "Please help my brother!\0"
    .align 2, 0

sUnknown_80EA214: @ 80EA214
    .string "We{APOSTROPHE}ve been rivals with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} for\n"
    .string "generations. It can{APOSTROPHE}t suddenly end like this!\0"
    .align 2, 0

sUnknown_80EA26C: @ 80EA26C
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} has been a rival since my\n"
    .string "ancestors{APOSTROPHE} time. The rivalry can{APOSTROPHE}t end!\0"
    .align 2, 0

sUnknown_80EA2BC: @ 80EA2BC
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} can{APOSTROPHE}t leave without settling\n"
    .string "which one of us is better. Please help!\0"
    .align 2, 0

sUnknown_80EA30C: @ 80EA30C
    .string "Please save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\n"
    .string "We owe each other a game!\0"
    .align 2, 0

sUnknown_80EA33C: @ 80EA33C
    .string "Please rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! We detest\n"
    .string "each other{COMMA} but we need each other!\0"
    .align 2, 0

sUnknown_80EA384: @ 80EA384
    .string "Rescue my rival!\0"
    .align 2, 0

sUnknown_80EA398: @ 80EA398
    .string "I can{APOSTROPHE}t live without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "My heart is breaking! Please! Help!\0"
    .align 2, 0

sUnknown_80EA3DC: @ 80EA3DC
    .string "Please save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "We{APOSTROPHE}re no good if we{APOSTROPHE}re not together!\0"
    .align 2, 0

sUnknown_80EA41C: @ 80EA41C
    .string "Please save my {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! Now I\n"
    .string "know what {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} means to me...\0"
    .align 2, 0

sUnknown_80EA45C: @ 80EA45C
    .string "Please rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! We\n"
    .string "promised our futures together! Please!\0"
    .align 2, 0

sUnknown_80EA4A0: @ 80EA4A0
    .string "Please rescue my precious {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "We{APOSTROPHE}re in love! Please help!\0"
    .align 2, 0

sUnknown_80EA4E4: @ 80EA4E4
    .string "Please! Please rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "We{APOSTROPHE}re madly in love!\0"
    .align 2, 0

sUnknown_80EA51C: @ 80EA51C
    .string "Please save my love!\0"
    .align 2, 0

sUnknown_80EA534: @ 80EA534
    .string "We make each other happy--it{APOSTROPHE}s in our\n"
    .string "nature. Please save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
    .align 2, 0

sUnknown_80EA57C: @ 80EA57C
    .string "Please rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! The beach\n"
    .string "feels empty without my usual friend...\0"
    .align 2, 0

sUnknown_80EA5C4: @ 80EA5C4
    .string "I feel lonely without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} to pull\n"
    .string "pranks and mess around with. Please help!\0"
    .align 2, 0

sUnknown_80EA614: @ 80EA614
    .string "Help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{COMMA} please!\n"
    .string "We often took strolls on the wind!\0"
    .align 2, 0

sUnknown_80EA650: @ 80EA650
    .string "Please save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! We{APOSTROPHE}re both\n"
    .string "old-timers who are longtime friends!\0"
    .align 2, 0

sUnknown_80EA698: @ 80EA698
    .string "Please save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}. We{APOSTROPHE}ve been in\n"
    .string "the delivery business for many years!\0"
    .align 2, 0

sUnknown_80EA6E4: @ 80EA6E4
    .string "I{APOSTROPHE}m sad without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{APOSTROPHE}s company.\n"
    .string "We showed flowers to each other...\0"
    .align 2, 0

sUnknown_80EA730: @ 80EA730
    .string "Without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{COMMA} there{APOSTROPHE}s no one for\n"
    .string "me to play with in the dark! Please help!\0"
    .align 2, 0

sUnknown_80EA784: @ 80EA784
    .string "...Help... Please...\n"
    .string "Who was it?\0"
    .align 2, 0

sUnknown_80EA7A8: @ 80EA7A8
    .string "Please save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}. We{APOSTROPHE}re both alike\n"
    .string "in being kind of vacant and unpredictable!\0"
    .align 2, 0

sUnknown_80EA7FC: @ 80EA7FC
    .string "Without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} around{COMMA} there{APOSTROPHE}s no\n"
    .string "one to heckle! Please break my boredom!\0"
    .align 2, 0

sUnknown_80EA84C: @ 80EA84C
    .string "Please help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "My tiny and round best friend!\0"
    .align 2, 0

sUnknown_80EA880: @ 80EA880
    .string "We promised to show each other how\n"
    .string "sharp our claws could be... Someone{COMMA} help!\0"
    .align 2, 0

sUnknown_80EA8D0: @ 80EA8D0
    .string "I lock horns with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} for fun.\n"
    .string "I terribly miss doing that...\0"
    .align 2, 0

sUnknown_80EA914: @ 80EA914
    .string "Please help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! We{APOSTROPHE}re both lazy{COMMA}\n"
    .string "so we{APOSTROPHE}re comfortable around each other!\0"
    .align 2, 0

sUnknown_80EA968: @ 80EA968
    .string "I want to help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "We both have a thing for pincers!\0"
    .align 2, 0

sUnknown_80EA9A4: @ 80EA9A4
    .string "We promised each other to perform magic\n"
    .string "and hypnosis shows together. Please help!\0"
    .align 2, 0

sUnknown_80EA9F8: @ 80EA9F8
    .string "Someone save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}--my friend\n"
    .string "and rival at ball juggling!\0"
    .align 2, 0

sUnknown_80EAA34: @ 80EAA34
    .string "Please help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! Our cries are\n"
    .string "identical! We can tell each other anything!\0"
    .align 2, 0

sUnknown_80EAA84: @ 80EAA84
    .string "I can{APOSTROPHE}t play the biting game without my pal\n"
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}! Please help!\0"
    .align 2, 0

sUnknown_80EAAC8: @ 80EAAC8
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is really noisy.\n"
    .string "But it{APOSTROPHE}s lonely without the racket... Sob...\0"
    .align 2, 0

sUnknown_80EAB10: @ 80EAB10
    .string "Without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{COMMA} it{APOSTROPHE}s no fun playing\n"
    .string "with toxic powders! Someone{COMMA} please help!\0"
    .align 2, 0

sUnknown_80EAB68: @ 80EAB68
    .string "Please rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "We{APOSTROPHE}ve been friends since we were eggs!\0"
    .align 2, 0

sUnknown_80EABA8: @ 80EABA8
    .string "Please help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}--a good\n"
    .string "friend who shares my love of fire!\0"
    .align 2, 0

sUnknown_80EABE8: @ 80EABE8
    .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} and I are of the same height.\n"
    .string "We{APOSTROPHE}re lifelong friends! Please help!\0"
    .align 2, 0

sUnknown_80EAC38: @ 80EAC38
    .string "We identify with each other because we\n"
    .string "both evolved from Wurmple. Please help!\0"
    .align 2, 0

sUnknown_80EAC88: @ 80EAC88
    .string "Help! I{APOSTROPHE}m friends with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}\n"
    .string "because we both evolve fast! Please help!\0"
    .align 2, 0

sUnknown_80EACD4: @ 80EACD4
    .string "Help! {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} isn{APOSTROPHE}t much now{COMMA} but\n"
    .string "my friend is amazing after evolution!\0"
    .align 2, 0

sUnknown_80EAD20: @ 80EAD20
    .string "Please rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "We always play together!\0"
    .align 2, 0

sUnknown_80EAD50: @ 80EAD50
    .string "Please rescue {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\n"
    .string "I can{APOSTROPHE}t stand to see a sludge buddy hurt!\0"
    .align 2, 0

sUnknown_80EAD94: @ 80EAD94
    .string "Please save my best friend {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\n"
    .string "We{APOSTROPHE}re both bivalves!\0"
    .align 2, 0

sUnknown_80EADD0: @ 80EADD0
    .string "Please save {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{COMMA}\n"
    .string "my drilling buddy!\0"
    .align 2, 0

sUnknown_80EADFC: @ 80EADFC
    .string "This precious friend can chat separately\n"
    .string "with three heads. Please help!\0"
    .align 2, 0

sUnknown_80EAE44: @ 80EAE44
    .string "Please save my friend!\0"
    .align 2, 0

@ Escort Mission Text
	.global gUnknown_80EAE5C
gUnknown_80EAE5C: @ 80EAE5C
        .4byte TakeMe_Text
        .4byte WantToSee_Text
        .4byte TakeMeWith_Text
        .4byte EscortMe_Text


        .global EscortMe_Text
        EscortMe_Text:
        .asciz "Escort me!"
        .align 2,0

        .global TakeMeWith_Text
        TakeMeWith_Text:
        .asciz "Please take me with you!"
        .align 2,0

        .global WantToSee_Text
        WantToSee_Text:
        .string "I want to see {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}."
        .align 2,0

        .global TakeMe_Text
        TakeMe_Text:
        .asciz "Take me!"
        .align 2,0

	.global gUnknown_80EAEB8
gUnknown_80EAEB8: @ 80EAEB8
@ replacing .incbin "baserom.gba", 0x000eaeb8, 0x2e0
        .4byte WaitingForMe_80EB17C
        .4byte PromisedMeet_80EB158
        .4byte WantMeet_80EB138
        .4byte WorriedAbout_80EB118
        .4byte GoMyself_80EB0FC
        .4byte OwnPower_80EB0DC
        .4byte TooWeak_80EB0B4
        .4byte WaitingInDungeon_80EB090
        .4byte WaitingForever_80EB06C
        .4byte InTrouble_80EB048
        .4byte WantToHelp_80EB030
        .4byte HasntReturned_80EB014
        .4byte FaintedInside_80EAFF0
        .4byte SickWorry_80EAFD4
        .4byte LongTime_80EAFA4
        .4byte HaveToGo_80EAF94
        .4byte HaveToMeet_80EAF70
        .4byte MustMeet_80EAF4C
        .4byte Apologize_80EAF2C
        .4byte CloseFriends_80EAF08

        .global CloseFriends_80EAF08
	CloseFriends_80EAF08:
        .string "I{APOSTROPHE}m close friends with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!"
        .align 2,0

        .global Apologize_80EAF2C
	Apologize_80EAF2C:
        .string "I want to apologize to {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}."
        .align 2,0

        .global MustMeet_80EAF4C
	MustMeet_80EAF4C:
        .string "I don{APOSTROPHE}t care how--we must meet!\0"
        .align 2,0

        .global HaveToMeet_80EAF70
	HaveToMeet_80EAF70:
        .asciz "We have to meet--whatever it takes!"
        .align 2,0

        .global HaveToGo_80EAF94
	HaveToGo_80EAF94:
        .asciz "I have to go!"
        .align 2,0

        .global LongTime_80EAFA4
	LongTime_80EAFA4:
        .string "We haven{APOSTROPHE}t seen each other in a long time.\0"
        .align 2,0

        .global SickWorry_80EAFD4
	SickWorry_80EAFD4:
        .string "I{APOSTROPHE}m sick with worry...\0"
        .align 2,0

        .global FaintedInside_80EAFF0
	FaintedInside_80EAFF0:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} may have fainted inside..."
        .align 2,0

        .global HasntReturned_80EB014
	HasntReturned_80EB014:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} hasn{APOSTROPHE}t returned!\0"
        .align 2,0

        .global WantToHelp_80EB030
	WantToHelp_80EB030:
        .string "I want to help {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global InTrouble_80EB048
	InTrouble_80EB048:
        .string "Hurry{COMMA} {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is in trouble...\0"
        .align 2,0

        .global WaitingForever_80EB06C
	WaitingForever_80EB06C:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} has been waiting forever...\0"
        .align 2,0

        .global WaitingInDungeon_80EB090
	WaitingInDungeon_80EB090:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is waiting in the dungeon.\0"
        .align 2,0

        .global TooWeak_80EB0B4
	TooWeak_80EB0B4:
        .string "I{APOSTROPHE}m too weak. It{APOSTROPHE}s not possible.\0"
        .align 2,0

        .global OwnPower_80EB0DC
	OwnPower_80EB0DC:
        .string "I can{APOSTROPHE}t go on my own power...\0"
        .align 2,0

        .global GoMyself_80EB0FC
	GoMyself_80EB0FC:
        .string "I can{APOSTROPHE}t go by myself...\0"
        .align 2,0

        .global WorriedAbout_80EB118
	WorriedAbout_80EB118:
        .string "I{APOSTROPHE}m worried about {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}...\0"
        .align 2,0

        .global WantMeet_80EB138
	WantMeet_80EB138:
        .string "I want to meet with {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}.\0"
        .align 2,0

        .global PromisedMeet_80EB158
	PromisedMeet_80EB158:
        .asciz "We promised to meet in the dungeon!"
        .align 2,0

        .global WaitingForMe_80EB17C
	WaitingForMe_80EB17C:
        .string "{COLOR_1 YELLOW}%s{END_COLOR_TEXT_1} is waiting for me!\0"
        .align 2,0


	.global gUnknown_80EB198
gUnknown_80EB198: @ 80EB198
        .4byte PleaseTakeMeToSee
        .4byte PleaseTakeMeThere
        .4byte PleaseEscortMe
        .4byte SomeonePleaseEscort

        .global SomeonePleaseEscort
        SomeonePleaseEscort:
        .string "Someone{COMMA} please escort me!\0"
        .align 2,0

        .global PleaseEscortMe
        PleaseEscortMe:
        .asciz "Please escort me there!"
        .align 2,0

        .global PleaseTakeMeThere
        PleaseTakeMeThere:
        .asciz "Please take me there with you!"
        .align 2,0

        .global PleaseTakeMeToSee
        PleaseTakeMeToSee:
        .string "Please take me to see {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gUnknown_80EB220
gUnknown_80EB220: @ 80EB220
@ replacing .incbin "baserom.gba", 0x000eb220, 0xd0
        .4byte TakeMeet_80EB2CC
        .4byte Escort_80EB2AC
        .4byte HelpMeet_80EB294
        .4byte WantMeet_80EB274
        .4byte Worried_80EB250
        .4byte Without_80EB238

        .global Without_80EB238
	Without_80EB238:
        .string "Without {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}{COMMA} I...\0"
        .align 2,0

        .global Worried_80EB250
	Worried_80EB250:
        .string "I{APOSTROPHE}m so worried about {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}...\0"
        .align 2,0

        .global WantMeet_80EB274
	WantMeet_80EB274:
        .string "I really want to meet {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global HelpMeet_80EB294
	HelpMeet_80EB294:
        .string "Help me meet {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global Escort_80EB2AC
	Escort_80EB2AC:
        .string "Please escort me to my {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

        .global TakeMeet_80EB2CC
	TakeMeet_80EB2CC:
        .string "Please! Take me to meet {COLOR_1 YELLOW}%s{END_COLOR_TEXT_1}!\0"
        .align 2,0

	.global gUnknown_80EB2F0
gUnknown_80EB2F0: @ 80EB2F0
@ replacing .incbin "baserom.gba", 0x000eb2f0, 0x108
        .4byte WeInLove_80EB3CC
        .4byte WeBelong_80EB3A4
        .4byte WePromised_80EB37C
        .4byte MeansEverything_80EB35C
        .4byte NoGood_80EB334
        .4byte Lonely_80EB308

        .global Lonely_80EB308
        Lonely_80EB308:
        .string "I{APOSTROPHE}m very lonely! Please take me with you!\0"
        .align 2,0

        .global NoGood_80EB334
        NoGood_80EB334:
        .string "It{APOSTROPHE}s no good if we{APOSTROPHE}re not together!\0"
        .align 2,0

        .global MeansEverything_80EB35C
        MeansEverything_80EB35C:
        .asciz "This means everything to me!"
        .align 2,0

        .global WePromised_80EB37C
        WePromised_80EB37C:
        .string "We{APOSTROPHE}ve promised our futures together.\0"
        .align 2,0

        .global WeBelong_80EB3A4
        WeBelong_80EB3A4:
        .string "We belong together! Please escort me!\0"
        .align 2,0

        .global WeInLove_80EB3CC
        WeInLove_80EB3CC:
        .string "We{APOSTROPHE}re in love! Please{COMMA} take me there!\0"
        .align 2,0

@ Item Delivery Mission Text
	.global gUnknown_80EB3F8
gUnknown_80EB3F8: @ 80EB3F8
    .4byte sUnknown_80EB708
    .4byte sUnknown_80EB6E4
    .4byte sUnknown_80EB6C0
    .4byte sUnknown_80EB6A0
    .4byte sUnknown_80EB67C
    .4byte sUnknown_80EB654
    .4byte sUnknown_80EB638
    .4byte sUnknown_80EB618
    .4byte sUnknown_80EB5F8
    .4byte sUnknown_80EB5D4
    .4byte sUnknown_80EB5B4
    .4byte sUnknown_80EB590
    .4byte sUnknown_80EB568
    .4byte sUnknown_80EB54C
    .4byte sUnknown_80EB524
    .4byte sUnknown_80EB500
    .4byte sUnknown_80EB4E0
    .4byte sUnknown_80EB4C0
    .4byte sUnknown_80EB4AC
    .4byte sUnknown_80EB494
    .4byte sUnknown_80EB470
    .4byte sUnknown_80EB450

sUnknown_80EB450: @ 80EB450
    .string "Is it true about the {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}?\0"
    .align 2, 0

sUnknown_80EB470: @ 80EB470
    .string "The item {COLOR_1 GREEN}%s{END_COLOR_TEXT_1} is the in thing!\0"
    .align 2, 0

sUnknown_80EB494: @ 80EB494
    .string "Wanted: my own {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
    .align 2, 0

sUnknown_80EB4AC: @ 80EB4AC
    .string "I lost my {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
    .align 2, 0

sUnknown_80EB4C0: @ 80EB4C0
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1} wanted for nostalgia.\0"
    .align 2, 0

sUnknown_80EB4E0: @ 80EB4E0
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1} wanted to test effects.\0"
    .align 2, 0

sUnknown_80EB500: @ 80EB500
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}{APOSTROPHE}s texture is comforting.\0"
    .align 2, 0

sUnknown_80EB524: @ 80EB524
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}--it{APOSTROPHE}s my mom{APOSTROPHE}s favorite.\0"
    .align 2, 0

sUnknown_80EB54C: @ 80EB54C
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1} makes me strong.\0"
    .align 2, 0

sUnknown_80EB568: @ 80EB568
    .string "I can{APOSTROPHE}t sleep without it: {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
    .align 2, 0

sUnknown_80EB590: @ 80EB590
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}--I get scared without it!\0"
    .align 2, 0

sUnknown_80EB5B4: @ 80EB5B4
    .string "Hard-to-find {COLOR_1 GREEN}%s{END_COLOR_TEXT_1} sought.\0"
    .align 2, 0

sUnknown_80EB5D4: @ 80EB5D4
    .string "I can{APOSTROPHE}t find one more {COLOR_1 GREEN}%s{END_COLOR_TEXT_1}.\0"
    .align 2, 0

sUnknown_80EB5F8: @ 80EB5F8
    .string "Help this {COLOR_1 GREEN}%s{END_COLOR_TEXT_1} collector!\0"
    .align 2, 0

sUnknown_80EB618: @ 80EB618
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}! Seeking in quantity!\0"
    .align 2, 0

sUnknown_80EB638: @ 80EB638
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1} wanted as a charm.\0"
    .align 2, 0

sUnknown_80EB654: @ 80EB654
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}--I can{APOSTROPHE}t leave without it.\0"
    .align 2, 0

sUnknown_80EB67C: @ 80EB67C
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}--I{APOSTROPHE}d love to utilize one!\0"
    .align 2, 0

sUnknown_80EB6A0: @ 80EB6A0
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1} wanted for exploration.\0"
    .align 2, 0

sUnknown_80EB6C0: @ 80EB6C0
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1} wanted after long search.\0"
    .align 2, 0

sUnknown_80EB6E4: @ 80EB6E4
    .string "{COLOR_1 GREEN}%s{END_COLOR_TEXT_1}--it{APOSTROPHE}s convenient to have.\0"
    .align 2, 0

sUnknown_80EB708: @ 80EB708
    .string "Having one {COLOR_1 GREEN}%s{END_COLOR_TEXT_1} is reassuring.\0"
    .align 2, 0

	.global gUnknown_80EB72C
gUnknown_80EB72C: @ 80EB72C
    .4byte sUnknown_80EBA00
    .4byte sUnknown_80EB9E8
    .4byte sUnknown_80EB9D0
    .4byte sUnknown_80EB9BC
    .4byte sUnknown_80EB9A0
    .4byte sUnknown_80EB97C
    .4byte sUnknown_80EB95C
    .4byte sUnknown_80EB930
    .4byte sUnknown_80EB90C
    .4byte sUnknown_80EB8E8
    .4byte sUnknown_80EB8D0
    .4byte sUnknown_80EB8AC
    .4byte sUnknown_80EB890
    .4byte sUnknown_80EB86C
    .4byte sUnknown_80EB850
    .4byte sUnknown_80EB9A0
    .4byte sUnknown_80EB82C
    .4byte sUnknown_80EB818
    .4byte sUnknown_80EB800
    .4byte sUnknown_80EB7D8
    .4byte sUnknown_80EB7A8
    .4byte sUnknown_80EB784

sUnknown_80EB784: @ 80EB784
    .string "Please contact me if you find it!\0"
    .align 2, 0

sUnknown_80EB7A8: @ 80EB7A8
    .string "Please help! I{APOSTROPHE}ll make it worth your time!\0"
    .align 2, 0

sUnknown_80EB7D8: @ 80EB7D8
    .string "Please help! I{APOSTROPHE}m offering a reward!\0"
    .align 2, 0

sUnknown_80EB800: @ 80EB800
    .string "Please! Please help me!\0"
    .align 2, 0

sUnknown_80EB818: @ 80EB818
    .string "Please help me out!\0"
    .align 2, 0

sUnknown_80EB82C: @ 80EB82C
    .string "Please! I need some cooperation!\0"
    .align 2, 0

sUnknown_80EB850: @ 80EB850
    .string "Please share a little bit!\0"
    .align 2, 0

sUnknown_80EB86C: @ 80EB86C
    .string "Please help! You{APOSTROPHE}re my only hope!\0"
    .align 2, 0

sUnknown_80EB890: @ 80EB890
    .string "Please! I need your help!\0"
    .align 2, 0

sUnknown_80EB8AC: @ 80EB8AC
    .string "Please help! I{APOSTROPHE}m counting on you!\0"
    .align 2, 0

sUnknown_80EB8D0: @ 80EB8D0
    .string "Please search for it!\0"
    .align 2, 0

sUnknown_80EB8E8: @ 80EB8E8
    .string "Please let me know if you find one!\0"
    .align 2, 0

sUnknown_80EB90C: @ 80EB90C
    .string "I{APOSTROPHE}m looking forward to your help!\0"
    .align 2, 0

sUnknown_80EB930: @ 80EB930
    .string "Please! I{APOSTROPHE}m offering a generous reward!\0"
    .align 2, 0

sUnknown_80EB95C: @ 80EB95C
    .string "Please help! Reward offered!\0"
    .align 2, 0

sUnknown_80EB97C: @ 80EB97C
    .string "Please! I must have one delivered!\0"
    .align 2, 0

sUnknown_80EB9A0: @ 80EB9A0
    .string "Please share one with me!\0"
    .align 2, 0

sUnknown_80EB9BC: @ 80EB9BC
    .string "Please give me one!\0"
    .align 2, 0

sUnknown_80EB9D0: @ 80EB9D0
    .string "Please find one for me!\0"
    .align 2, 0

sUnknown_80EB9E8: @ 80EB9E8
    .string "Please trade me one!\0"
    .align 2, 0

sUnknown_80EBA00: @ 80EBA00
    .string "Please! May I have one?\0"
    .align 2, 0
