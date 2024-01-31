
08049000 <_start>:
 8049000:	b8 04 00 00 00       	mov    $0x4,%eax
 8049005:	bb 01 00 00 00       	mov    $0x1,%ebx
 804900a:	b9 00 a0 04 08       	mov    $0x804a000,%ecx
 804900f:	ba 0c 00 00 00       	mov    $0xc,%edx
 8049014:	cd 80                	int    $0x80
 8049016:	b8 03 00 00 00       	mov    $0x3,%eax
 804901b:	31 db                	xor    %ebx,%ebx
 804901d:	b9 21 a1 04 08       	mov    $0x804a121,%ecx
 8049022:	ba 20 00 00 00       	mov    $0x20,%edx
 8049027:	cd 80                	int    $0x80

08049029 <check>:
 8049029:	83 f8 20             	cmp    $0x20,%eax
 804902c:	0f 85 39 03 00 00    	jne    804936b <wrong>
 8049032:	a1 21 a1 04 08       	mov    0x804a121,%eax
 8049037:	8b 0d 25 a1 04 08    	mov    0x804a125,%ecx
 804903d:	8b 15 29 a1 04 08    	mov    0x804a129,%edx
 8049043:	8b 1d 2d a1 04 08    	mov    0x804a12d,%ebx
 8049049:	8b 25 31 a1 04 08    	mov    0x804a131,%esp
 804904f:	8b 2d 35 a1 04 08    	mov    0x804a135,%ebp
 8049055:	8b 35 39 a1 04 08    	mov    0x804a139,%esi
 804905b:	8b 3d 3d a1 04 08    	mov    0x804a13d,%edi
 8049061:	66 0f ba fe 08       	btc    $0x8,%si
 8049066:	80 c2 fb             	add    $0xfb,%dl
 8049069:	d3 c2                	rol    %cl,%edx
 804906b:	80 e9 83             	sub    $0x83,%cl
 804906e:	66 29 fb             	sub    %di,%bx
 8049071:	80 ec fc             	sub    $0xfc,%ah
 8049074:	05 73 13 95 ef       	add    $0xef951373,%eax
 8049079:	35 fa 21 88 3c       	xor    $0x3c8821fa,%eax
 804907e:	66 31 da             	xor    %bx,%dx
 8049081:	66 81 ec f5 df       	sub    $0xdff5,%sp
 8049086:	86 d6                	xchg   %dl,%dh
 8049088:	d0 c6                	rol    %dh
 804908a:	66 d3 cf             	ror    %cl,%di
 804908d:	66 81 c5 2a f6       	add    $0xf62a,%bp
 8049092:	01 c6                	add    %eax,%esi
 8049094:	80 c3 65             	add    $0x65,%bl
 8049097:	c1 ca 03             	ror    $0x3,%edx
 804909a:	87 f7                	xchg   %esi,%edi
 804909c:	0f bb fb             	btc    %edi,%ebx
 804909f:	66 0f ba f9 0e       	btc    $0xe,%cx
 80490a4:	81 f5 22 f3 1c 68    	xor    $0x681cf322,%ebp
 80490aa:	f6 d1                	not    %cl
 80490ac:	66 c1 c8 08          	ror    $0x8,%ax
 80490b0:	66 29 f4             	sub    %si,%sp
 80490b3:	c1 c5 0d             	rol    $0xd,%ebp
 80490b6:	66 87 fe             	xchg   %di,%si
 80490b9:	66 0f ba fd 0a       	btc    $0xa,%bp
 80490be:	0f ba f9 18          	btc    $0x18,%ecx
 80490c2:	31 e2                	xor    %esp,%edx
 80490c4:	80 f4 aa             	xor    $0xaa,%ah
 80490c7:	66 81 c6 7e a3       	add    $0xa37e,%si
 80490cc:	66 81 ed bd 75       	sub    $0x75bd,%bp
 80490d1:	28 d1                	sub    %dl,%cl
 80490d3:	c0 c3 05             	rol    $0x5,%bl
 80490d6:	28 fb                	sub    %bh,%bl
 80490d8:	2d a3 5f 50 f5       	sub    $0xf5505fa3,%eax
 80490dd:	01 e0                	add    %esp,%eax
 80490df:	80 c4 62             	add    $0x62,%ah
 80490e2:	4a                   	dec    %edx
 80490e3:	81 ee ba 0c d3 22    	sub    $0x22d30cba,%esi
 80490e9:	87 ea                	xchg   %ebp,%edx
 80490eb:	66 81 f2 9e 0b       	xor    $0xb9e,%dx
 80490f0:	80 c3 83             	add    $0x83,%bl
 80490f3:	00 f4                	add    %dh,%ah
 80490f5:	69 d2 21 73 f3 0d    	imul   $0xdf37321,%edx,%edx
 80490fb:	00 f9                	add    %bh,%cl
 80490fd:	80 c1 0b             	add    $0xb,%cl
 8049100:	01 ef                	add    %ebp,%edi
 8049102:	80 c1 25             	add    $0x25,%cl
 8049105:	30 e3                	xor    %ah,%bl
 8049107:	0f ba fd 08          	btc    $0x8,%ebp
 804910b:	d1 c7                	rol    %edi
 804910d:	35 f7 6f fd 4c       	xor    $0x4cfd6ff7,%eax
 8049112:	66 29 e1             	sub    %sp,%cx
 8049115:	c0 c1 04             	rol    $0x4,%cl
 8049118:	66 c1 ce 05          	ror    $0x5,%si
 804911c:	66 c1 c2 07          	rol    $0x7,%dx
 8049120:	86 c7                	xchg   %al,%bh
 8049122:	66 87 fa             	xchg   %di,%dx
 8049125:	66 81 f5 f4 fc       	xor    $0xfcf4,%bp
 804912a:	c0 c4 04             	rol    $0x4,%ah
 804912d:	0f c9                	bswap  %ecx
 804912f:	c1 c2 13             	rol    $0x13,%edx
 8049132:	c1 c3 17             	rol    $0x17,%ebx
 8049135:	c1 c2 14             	rol    $0x14,%edx
 8049138:	66 81 c2 72 99       	add    $0x9972,%dx
 804913d:	66 69 e4 bd 43       	imul   $0x43bd,%sp,%sp
 8049142:	01 cd                	add    %ecx,%ebp
 8049144:	66 0f bb d6          	btc    %dx,%si
 8049148:	66 0f bb cb          	btc    %cx,%bx
 804914c:	00 c1                	add    %al,%cl
 804914e:	66 87 f7             	xchg   %si,%di
 8049151:	0f bb ea             	btc    %ebp,%edx
 8049154:	66 81 c6 91 14       	add    $0x1491,%si
 8049159:	66 81 f2 f8 dc       	xor    $0xdcf8,%dx
 804915e:	66 87 fd             	xchg   %di,%bp
 8049161:	0f bb ce             	btc    %ecx,%esi
 8049164:	66 4f                	dec    %di
 8049166:	66 0f ba fd 06       	btc    $0x6,%bp
 804916b:	29 e3                	sub    %esp,%ebx
 804916d:	f6 d6                	not    %dh
 804916f:	28 d3                	sub    %dl,%bl
 8049171:	00 ca                	add    %cl,%dl
 8049173:	f7 de                	neg    %esi
 8049175:	66 c1 cc 05          	ror    $0x5,%sp
 8049179:	81 c3 6c 66 8e 8e    	add    $0x8e8e666c,%ebx
 804917f:	c0 cf 04             	ror    $0x4,%bh
 8049182:	80 eb c7             	sub    $0xc7,%bl
 8049185:	66 31 d9             	xor    %bx,%cx
 8049188:	04 e8                	add    $0xe8,%al
 804918a:	87 e6                	xchg   %esp,%esi
 804918c:	2d c4 7b 25 74       	sub    $0x74257bc4,%eax
 8049191:	f7 d5                	not    %ebp
 8049193:	28 cb                	sub    %cl,%bl
 8049195:	c1 c8 11             	ror    $0x11,%eax
 8049198:	0f ba fc 11          	btc    $0x11,%esp
 804919c:	66 81 f6 5b 6e       	xor    $0x6e5b,%si
 80491a1:	66 01 ee             	add    %bp,%si
 80491a4:	81 f1 75 ff a0 8f    	xor    $0x8fa0ff75,%ecx
 80491aa:	c0 cb 07             	ror    $0x7,%bl
 80491ad:	81 ef 8a 71 8d db    	sub    $0xdb8d718a,%edi
 80491b3:	66 29 f0             	sub    %si,%ax
 80491b6:	80 c1 88             	add    $0x88,%cl
 80491b9:	66 c1 c5 06          	rol    $0x6,%bp
 80491bd:	80 c1 a9             	add    $0xa9,%cl
 80491c0:	80 f6 3a             	xor    $0x3a,%dh
 80491c3:	66 0f ba fd 02       	btc    $0x2,%bp
 80491c8:	01 f3                	add    %esi,%ebx
 80491ca:	66 0f ba fa 0c       	btc    $0xc,%dx
 80491cf:	66 29 e2             	sub    %sp,%dx
 80491d2:	81 e9 80 23 a2 17    	sub    $0x17a22380,%ecx
 80491d8:	66 c1 c8 05          	ror    $0x5,%ax
 80491dc:	80 f2 b6             	xor    $0xb6,%dl
 80491df:	66 0f bb ef          	btc    %bp,%di
 80491e3:	4d                   	dec    %ebp
 80491e4:	c0 c1 06             	rol    $0x6,%cl
 80491e7:	66 0f ba fb 0f       	btc    $0xf,%bx
 80491ec:	81 ed 4d ad ac 38    	sub    $0x38acad4d,%ebp
 80491f2:	66 31 e1             	xor    %sp,%cx
 80491f5:	66 0f bb ee          	btc    %bp,%si
 80491f9:	87 e3                	xchg   %esp,%ebx
 80491fb:	c1 c0 16             	rol    $0x16,%eax
 80491fe:	66 31 f1             	xor    %si,%cx
 8049201:	c0 c4 07             	rol    $0x7,%ah
 8049204:	66 81 f1 21 ae       	xor    $0xae21,%cx
 8049209:	66 c1 c5 09          	rol    $0x9,%bp
 804920d:	66 49                	dec    %cx
 804920f:	66 81 c5 4b a2       	add    $0xa24b,%bp
 8049214:	66 31 f9             	xor    %di,%cx
 8049217:	80 c2 58             	add    $0x58,%dl
 804921a:	66 69 ff 67 93       	imul   $0x9367,%di,%di
 804921f:	0f ba fc 01          	btc    $0x1,%esp
 8049223:	66 0f ba fe 0a       	btc    $0xa,%si
 8049228:	81 ed 6a 89 52 c3    	sub    $0xc352896a,%ebp
 804922e:	66 81 c7 80 13       	add    $0x1380,%di
 8049233:	c0 c9 02             	ror    $0x2,%cl
 8049236:	81 f3 38 9d 5a f1    	xor    $0xf15a9d38,%ebx
 804923c:	f6 df                	neg    %bh
 804923e:	0f bb ee             	btc    %ebp,%esi
 8049241:	66 c1 c2 0d          	rol    $0xd,%dx
 8049245:	66 81 c2 90 f6       	add    $0xf690,%dx
 804924a:	c1 c5 02             	rol    $0x2,%ebp
 804924d:	66 93                	xchg   %ax,%bx
 804924f:	d0 c7                	rol    %bh
 8049251:	66 81 f5 c2 99       	xor    $0x99c2,%bp
 8049256:	29 c4                	sub    %eax,%esp
 8049258:	86 c8                	xchg   %cl,%al
 804925a:	66 0f bb fa          	btc    %di,%dx
 804925e:	81 ee 69 92 83 b7    	sub    $0xb7839269,%esi
 8049264:	87 fc                	xchg   %edi,%esp
 8049266:	30 e1                	xor    %ah,%cl
 8049268:	69 c0 9f 96 02 e1    	imul   $0xe102969f,%eax,%eax
 804926e:	66 0f ba fc 0c       	btc    $0xc,%sp
 8049273:	66 f7 d9             	neg    %cx
 8049276:	0f bb d7             	btc    %edx,%edi
 8049279:	31 dd                	xor    %ebx,%ebp
 804927b:	66 0f bb e5          	btc    %sp,%bp
 804927f:	66 c1 c4 04          	rol    $0x4,%sp
 8049283:	30 d8                	xor    %bl,%al
 8049285:	66 d1 c9             	ror    %cx
 8049288:	66 81 f1 55 2d       	xor    $0x2d55,%cx
 804928d:	66 81 e9 d0 eb       	sub    $0xebd0,%cx
 8049292:	66 31 e8             	xor    %bp,%ax
 8049295:	66 94                	xchg   %ax,%sp
 8049297:	0f bb d1             	btc    %edx,%ecx
 804929a:	80 c3 d9             	add    $0xd9,%bl
 804929d:	c0 cb 06             	ror    $0x6,%bl
 80492a0:	31 fa                	xor    %edi,%edx
 80492a2:	fe c6                	inc    %dh
 80492a4:	66 0f ba fa 0b       	btc    $0xb,%dx
 80492a9:	66 29 ea             	sub    %bp,%dx
 80492ac:	2c 0c                	sub    $0xc,%al
 80492ae:	80 c4 ce             	add    $0xce,%ah
 80492b1:	66 0f ba fc 04       	btc    $0x4,%sp
 80492b6:	c0 c8 07             	ror    $0x7,%al
 80492b9:	81 c2 69 60 30 43    	add    $0x43306069,%edx
 80492bf:	66 81 f2 7f 47       	xor    $0x477f,%dx
 80492c4:	66 81 e9 ab f8       	sub    $0xf8ab,%cx
 80492c9:	86 c3                	xchg   %al,%bl
 80492cb:	00 d3                	add    %dl,%bl
 80492cd:	66 c1 c1 07          	rol    $0x7,%cx
 80492d1:	80 ea 30             	sub    $0x30,%dl
 80492d4:	66 0f bb c3          	btc    %ax,%bx
 80492d8:	66 87 dc             	xchg   %bx,%sp
 80492db:	31 d0                	xor    %edx,%eax
 80492dd:	0f ba fe 04          	btc    $0x4,%esi
 80492e1:	46                   	inc    %esi
 80492e2:	00 c6                	add    %al,%dh
 80492e4:	29 df                	sub    %ebx,%edi
 80492e6:	66 81 ed 8a 54       	sub    $0x548a,%bp
 80492eb:	c1 c9 02             	ror    $0x2,%ecx
 80492ee:	00 dc                	add    %bl,%ah
 80492f0:	66 c1 cb 05          	ror    $0x5,%bx
 80492f4:	c0 c1 05             	rol    $0x5,%cl
 80492f7:	c1 c1 1e             	rol    $0x1e,%ecx
 80492fa:	81 ea e5 f7 e1 f7    	sub    $0xf7e1f7e5,%edx
 8049300:	c0 c1 02             	rol    $0x2,%cl
 8049303:	81 f2 87 89 da 21    	xor    $0x21da8987,%edx
 8049309:	66 0f bb c8          	btc    %cx,%ax
 804930d:	0f ba fc 1e          	btc    $0x1e,%esp
 8049311:	3d 41 79 52 d3       	cmp    $0xd3527941,%eax
 8049316:	75 53                	jne    804936b <wrong>
 8049318:	81 f9 1a 56 f0 99    	cmp    $0x99f0561a,%ecx
 804931e:	75 4b                	jne    804936b <wrong>
 8049320:	81 fa d6 92 f3 a0    	cmp    $0xa0f392d6,%edx
 8049326:	75 43                	jne    804936b <wrong>
 8049328:	81 fb a2 8c 28 48    	cmp    $0x48288ca2,%ebx
 804932e:	75 3b                	jne    804936b <wrong>
 8049330:	81 fc e2 a3 a7 20    	cmp    $0x20a7a3e2,%esp
 8049336:	75 33                	jne    804936b <wrong>
 8049338:	81 fd 5d 8c 61 a7    	cmp    $0xa7618c5d,%ebp
 804933e:	75 2b                	jne    804936b <wrong>
 8049340:	81 fe 08 0e de 68    	cmp    $0x68de0e08,%esi
 8049346:	75 23                	jne    804936b <wrong>
 8049348:	81 ff ec 8e a6 50    	cmp    $0x50a68eec,%edi
 804934e:	75 1b                	jne    804936b <wrong>

08049350 <ok>:
 8049350:	b8 04 00 00 00       	mov    $0x4,%eax
 8049355:	bb 01 00 00 00       	mov    $0x1,%ebx
 804935a:	b9 0c a0 04 08       	mov    $0x804a00c,%ecx
 804935f:	ba 0e 00 00 00       	mov    $0xe,%edx
 8049364:	cd 80                	int    $0x80
