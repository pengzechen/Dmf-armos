qemu-system-aarch64 -m 4G -smp 1 -cpu cortex-a72 -nographic  -M virt,gic_version=2 -M virtualization=on -kernel build/kernel.elf
set enable: reg: 0, mask: 0x1
set enable: reg: 0, mask: 0x2
set enable: reg: 0, mask: 0x4
set enable: reg: 0, mask: 0x8
set enable: reg: 0, mask: 0x10
set enable: reg: 0, mask: 0x20
set enable: reg: 0, mask: 0x40
set enable: reg: 0, mask: 0x80
set enable: reg: 0, mask: 0x100
set enable: reg: 0, mask: 0x200
set enable: reg: 0, mask: 0x400
set enable: reg: 0, mask: 0x800
set enable: reg: 0, mask: 0x1000
set enable: reg: 0, mask: 0x2000
set enable: reg: 0, mask: 0x4000
set enable: reg: 0, mask: 0x8000
set enable: reg: 0, mask: 0x10000
set enable: reg: 0, mask: 0x20000
set enable: reg: 0, mask: 0x40000
set enable: reg: 0, mask: 0x80000
set enable: reg: 0, mask: 0x100000
set enable: reg: 0, mask: 0x200000
set enable: reg: 0, mask: 0x400000
set enable: reg: 0, mask: 0x800000
set enable: reg: 0, mask: 0x1000000
set enable: reg: 0, mask: 0x2000000
set enable: reg: 0, mask: 0x4000000
set enable: reg: 0, mask: 0x8000000
set enable: reg: 0, mask: 0x10000000
set enable: reg: 0, mask: 0x20000000
set enable: reg: 0, mask: 0x40000000
set enable: reg: 0, mask: 0x80000000
    gicd enable ok
    gicc enable ok
    irq numbers: 288
    cpu num: 1
    gich enable ok
timer frq: 62500000
set enable: reg: 0, mask: 0x40000000
get enable: reg: 0, mask: 40000000, value: ffffffff
timer enabled successfully ...
io, gic, timer, init ok...

    Initialize vtcr...
vtcr val: 0x1355c
Initialize EPT...
EPT root address : 0x4241c000
ept_L2_root : 0x4241d000
ept_L3_root : 0x42425000
LPAE_L1_SIZE : 8
LPAE_L2_SIZE : 4096
LPAE_L3_SIZE : 2097152
    Initialize trap...
HCR : 0x8027603b
Copy guest kernel image from 40089c00 to 70200000 (37142528 bytes): 0x90011b88 / 0x94012325
Copy end : 0x90011b88 / 0x94012325

Hello Hyper:
there's some hyper tests: 
scrlr_el2: 0x1
hcr_el2: 0x8027603b
read_vttbr_el2: 0x4241c000
cacheline_bytes: 4

id: 0, elr: 0x40080198
id: 1, elr: 0x70200000
current task id: 0


NN   NN  iii               bb        OOOOO    SSSSS
NNN  NN       mm mm mmmm   bb       OO   OO  SS
NN N NN  iii  mmm  mm  mm  bbbbbb   OO   OO   SSSSS
NN  NNN  iii  mmm  mm  mm  bb   bb  OO   OO       SS
NN   NN  iii  mmm  mm  mm  bbbbbb    OOOO0    SSSSS
              ___    ____    ___    ___
             |__ \  / __ \  |__ \  |__ \
             __/ / / / / /  __/ /  __/ /
            / __/ / /_/ /  / __/  / __/
           /____/ \____/  /____/ /____/

arch = aarch64
platform = qemu-virt-arm
build_mode = debug
log_level = info

Initializing kernel heap at: [0xffff000072572060, 0xffff000072972060)
[INFO  nimbos] Logging is enabled.
Initializing frame allocator at: [PA:0x72973000, PA:0x78000000)
Mapping .text: [0xffff000070200000, 0xffff000070270000)
Mapping .rodata: [0xffff000070270000, 0xffff000070281000)
Mapping .data: [0xffff000070281000, 0xffff00007256c000)
Mapping .bss: [0xffff000072570000, 0xffff000072973000)
Mapping boot stack: [0xffff00007256c000, 0xffff000072570000)
Mapping physical memory: [0xffff000072973000, 0xffff000078000000)
Mapping MMIO: [0xffff000009000000, 0xffff000009001000)
Mapping MMIO: [0xffff000008000000, 0xffff000008010000)
Mapping MMIO: [0xffff000008040000, 0xffff000008050000)
      >>> gicd emu read GICD_TYPER
      <<< gicd emu write GICD_ICENABLER(0)
      <<< gicd emu write GICD_ICPENDER(0)
      <<< gicd emu write GICD_ICENABLER(i)
      <<< gicd emu write GICD_ICPENDER(i)
      <<< gicd emu write GICD_ICENABLER(i)
      <<< gicd emu write GICD_ICPENDER(i)
      <<< gicd emu write GICD_ICENABLER(i)
      <<< gicd emu write GICD_ICPENDER(i)
      <<< gicd emu write GICD_ICENABLER(i)
      <<< gicd emu write GICD_ICPENDER(i)
      >>> gicd emu read GICD_TYPER
      <<< gicd emu write GICD_CTLR
Initializing gic done.
      <<< gicd emu write GICD_ICENABLER(i)
Initializing uart done.
gpa: 8000100, r: 8000000, len: 4, int id: 27
      <<< gicd emu write GICD_ISENABLER(0)
Initializing timer done.
Initializing task manager...
/**** APPS ****
cyclictest
exit
fantastic_text
forktest
forktest2
forktest_simple
forktest_simple_c
forktree
hello_c
hello_world
matrix
sleep
sleep_simple
stack_overflow
thread_simple
user_shell
usertests
yield
**************/
Running tasks...
test kernel task: pid = TaskId(2), arg = 0xdead
[  7.532398 INFO  nimbos::task::structs][0:2] task exit with code 0
test kernel task: pid = TaskId(3), arg = 0xbeef
[  7.573352 INFO  nimbos::task::structs][0:3] task exit with code 0
[  7.575381 INFO  nimbos::arch::aarch64::context][0:4] user task start: entry=0x215bec, ustack=0xfffffffff000, kstack=0xffff000072968000
Rust user shell
>> usertests
[ 23.850562 INFO  nimbos::arch::aarch64::context][0:5] user task start: entry=0x216278, ustack=0xffffffffeac0, kstack=0xffff000072964000
Usertests: Running 'exit':
[ 23.923112 INFO  nimbos::arch::aarch64::context][0:6] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
I am the parent. Forking the child...
I am the parent, fork a child pid 7
I am the parent, waiting now..
[ 23.976158 INFO  nimbos::arch::aarch64::context][0:7] user task start: entry=0x214058, ustack=0xffffffffedb0, kstack=0xffff00007296c000
I am the child.
[ 23.981279 INFO  nimbos::task::structs][0:7] task exit with code -66436
waitpid 7 ok.
exit passed!
[ 23.989708 INFO  nimbos::task::structs][0:6] task exit with code 0
Usertests: Test 'exit' in Process 6 exited with code 0.
Usertests: Running 'fantastic_text':
[ 24.041225 INFO  nimbos::arch::aarch64::context][0:8] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
Hello, Rust OSes!
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
regular underline reverse strikethrough
[ 24.114854 INFO  nimbos::task::structs][0:8] task exit with code 0
Usertests: Test 'fantastic_text' in Process 8 exited with code 0.
Usertests: Running 'forktest':
[ 24.131656 INFO  nimbos::arch::aarch64::context][0:9] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
forked child pid = [ 24.185871 INFO  nimbos::arch::aarch64::context][0:10] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007296c000
I am child 0
[ 24.191450 INFO  nimbos::task::structs][0:10] task exit with code 0
10
forked child pid = 11
forked child pid = 12
forked child pid = 13
[ 24.251335 INFO  nimbos::arch::aarch64::context][0:11] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072944000
I am child 1
[ 24.256832 INFO  nimbos::task::structs][0:11] task exit with code 0
[ 24.261088 INFO  nimbos::arch::aarch64::context][0:12] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072948000
I am child 2
[ 24.266738 INFO  nimbos::task::structs][0:12] task exit with code 0
[ 24.304403 INFO  nimbos::arch::aarch64::context][0:13] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007294c000
I am child 3
[ 24.310859 INFO  nimbos::task::structs][0:13] task exit with code 0
forked child pid = 14
forked child pid = 15
forked child pid = 16
forked child pid = 17
[ 24.378375 INFO  nimbos::arch::aarch64::context][0:14] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072950000
I am child 4
[ 24.384074 INFO  nimbos::task::structs][0:14] task exit with code 0
[ 24.388376 INFO  nimbos::arch::aarch64::context][0:15] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072954000
I am child 5
[ 24.394023 INFO  nimbos::task::structs][0:15] task exit with code 0
[ 24.398874 INFO  nimbos::arch::aarch64::context][0:16] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072958000
I am child 6
[ 24.438688 INFO  nimbos::task::structs][0:16] task exit with code 0
[ 24.443978 INFO  nimbos::arch::aarch64::context][0:17] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007295c000
I am child 7
[ 24.449680 INFO  nimbos::task::structs][0:17] task exit with code 0
forked child pid = 18
forked child pid = 19
forked child pid = 20
forked child pid = 21
[ 24.520483 INFO  nimbos::arch::aarch64::context][0:18] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072904000
I am child 8
[ 24.525945 INFO  nimbos::task::structs][0:18] task exit with code 0
[ 24.530513 INFO  nimbos::arch::aarch64::context][0:19] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072908000
I am child 9
[ 24.535909 INFO  nimbos::task::structs][0:19] task exit with code 0
[ 24.574794 INFO  nimbos::arch::aarch64::context][0:20] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007290c000
I am child 10
[ 24.581212 INFO  nimbos::task::structs][0:20] task exit with code 0
[ 24.586177 INFO  nimbos::arch::aarch64::context][0:21] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072910000
I am child 11
[ 24.592184 INFO  nimbos::task::structs][0:21] task exit with code 0
forked child pid = 22
forked child pid = 23
forked child pid = 24
forked child pid = 25
[ 24.662311 INFO  nimbos::arch::aarch64::context][0:22] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072914000
I am child 12
[ 24.668488 INFO  nimbos::task::structs][0:22] task exit with code 0
[ 24.706488 INFO  nimbos::arch::aarch64::context][0:23] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072918000
I am child 13
[ 24.713368 INFO  nimbos::task::structs][0:23] task exit with code 0
[ 24.718113 INFO  nimbos::arch::aarch64::context][0:24] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007291c000
I am child 14
[ 24.724131 INFO  nimbos::task::structs][0:24] task exit with code 0
[ 24.729476 INFO  nimbos::arch::aarch64::context][0:25] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072920000
I am child 15
[ 24.736273 INFO  nimbos::task::structs][0:25] task exit with code 0
forked child pid = 26
forked child pid = 27
forked child pid = [ 24.794182 INFO  nimbos::arch::aarch64::context][0:26] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072924000
I am child 16
[ 24.800219 INFO  nimbos::task::structs][0:26] task exit with code 0
[ 24.805090 INFO  nimbos::arch::aarch64::context][0:27] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072928000
I am child 17
[ 24.843988 INFO  nimbos::task::structs][0:27] task exit with code 0
[ 24.849388 INFO  nimbos::arch::aarch64::context][0:28] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007292c000
I am child 18
[ 24.855263 INFO  nimbos::task::structs][0:28] task exit with code 0
28
forked child pid = 29
forked child pid = 30
forked child pid = 31
[ 24.928863 INFO  nimbos::arch::aarch64::context][0:29] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072930000
I am child 19
[ 24.934881 INFO  nimbos::task::structs][0:29] task exit with code 0
[ 24.938883 INFO  nimbos::arch::aarch64::context][0:30] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072934000
I am child 20
[ 24.978202 INFO  nimbos::task::structs][0:30] task exit with code 0
[ 24.983229 INFO  nimbos::arch::aarch64::context][0:31] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072938000
I am child 21
[ 24.988864 INFO  nimbos::task::structs][0:31] task exit with code 0
forked child pid = 32
forked child pid = 33
forked child pid = 34
forked child pid = 35
[ 25.056846 INFO  nimbos::arch::aarch64::context][0:32] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072940000
I am child 22
[ 25.062964 INFO  nimbos::task::structs][0:32] task exit with code 0
[ 25.067219 INFO  nimbos::arch::aarch64::context][0:33] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072584000
I am child 23
[ 25.107796 INFO  nimbos::task::structs][0:33] task exit with code 0
[ 25.112772 INFO  nimbos::arch::aarch64::context][0:34] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072588000
I am child 24
[ 25.118491 INFO  nimbos::task::structs][0:34] task exit with code 0
[ 25.123911 INFO  nimbos::arch::aarch64::context][0:35] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007258c000
I am child 25
[ 25.129987 INFO  nimbos::task::structs][0:35] task exit with code 0
forked child pid = 36
forked child pid = 37
forked child pid = 38
forked child pid = [ 25.197408 INFO  nimbos::arch::aarch64::context][0:36] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072590000
I am child 26
[ 25.203411 INFO  nimbos::task::structs][0:36] task exit with code 0
[ 25.207706 INFO  nimbos::arch::aarch64::context][0:37] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072594000
I am child 27
[ 25.247619 INFO  nimbos::task::structs][0:37] task exit with code 0
[ 25.252601 INFO  nimbos::arch::aarch64::context][0:38] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff000072598000
I am child 28
[ 25.258370 INFO  nimbos::task::structs][0:38] task exit with code 0
[ 25.263744 INFO  nimbos::arch::aarch64::context][0:39] user task start: entry=0x2137b8, ustack=0xffffffffed90, kstack=0xffff00007259c000
I am child 29
[ 25.269818 INFO  nimbos::task::structs][0:39] task exit with code 0
39
forktest passed!
[ 25.387711 INFO  nimbos::task::structs][0:9] task exit with code 0
Usertests: Test 'forktest' in Process 9 exited with code 0.
Usertests: Running 'forktest2':
[ 25.410818 INFO  nimbos::arch::aarch64::context][0:40] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
[ 25.469321 INFO  nimbos::arch::aarch64::context][0:41] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007295c000
pid 41 sleep for 1512 ms
[ 25.531126 INFO  nimbos::arch::aarch64::context][0:42] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007296c000
pid 42 sleep for 1885 ms
[ 25.538498 INFO  nimbos::arch::aarch64::context][0:43] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072970000
pid 43 sleep for 1329 ms
[ 25.545781 INFO  nimbos::arch::aarch64::context][0:44] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072954000
pid 44 sleep for 1726 ms
[ 25.586664 INFO  nimbos::arch::aarch64::context][0:45] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072944000
pid 45 sleep for 1132 ms
[ 25.661292 INFO  nimbos::arch::aarch64::context][0:46] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072948000
pid 46 sleep for 1630 ms
[ 25.668536 INFO  nimbos::arch::aarch64::context][0:47] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007294c000
pid 47 sleep for 1918 ms
[ 25.675783 INFO  nimbos::arch::aarch64::context][0:48] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072950000
pid 48 sleep for 1676 ms
[ 25.716728 INFO  nimbos::arch::aarch64::context][0:49] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072908000
pid 49 sleep for 1995 ms
[ 25.724510 INFO  nimbos::arch::aarch64::context][0:50] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007290c000
pid 50 sleep for 1970 ms
[ 25.801024 INFO  nimbos::arch::aarch64::context][0:51] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072910000
pid 51 sleep for 1042 ms
[ 25.808003 INFO  nimbos::arch::aarch64::context][0:52] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072914000
pid 52 sleep for 1502 ms
[ 25.814947 INFO  nimbos::arch::aarch64::context][0:53] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072918000
pid 53 sleep for 1873 ms
[ 25.855432 INFO  nimbos::arch::aarch64::context][0:54] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072920000
pid 54 sleep for 1821 ms
[ 25.862480 INFO  nimbos::arch::aarch64::context][0:55] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072924000
pid 55 sleep for 1117 ms
[ 25.869795 INFO  nimbos::arch::aarch64::context][0:56] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072928000
pid 56 sleep for 1689 ms
[ 25.876945 INFO  nimbos::arch::aarch64::context][0:57] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007292c000
pid 57 sleep for 1248 ms
[ 25.918729 INFO  nimbos::arch::aarch64::context][0:58] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072934000
pid 58 sleep for 1790 ms
[ 25.991900 INFO  nimbos::arch::aarch64::context][0:59] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072938000
pid 59 sleep for 1051 ms
[ 25.999047 INFO  nimbos::arch::aarch64::context][0:60] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007293c000
pid 60 sleep for 1059 ms
[ 26.006057 INFO  nimbos::arch::aarch64::context][0:61] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072940000
pid 61 sleep for 1301 ms
[ 26.013118 INFO  nimbos::arch::aarch64::context][0:62] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072588000
pid 62 sleep for 1630 ms
[ 26.054511 INFO  nimbos::arch::aarch64::context][0:63] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007258c000
pid 63 sleep for 1968 ms
[ 26.061811 INFO  nimbos::arch::aarch64::context][0:64] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072590000
pid 64 sleep for 1656 ms
[ 26.068592 INFO  nimbos::arch::aarch64::context][0:65] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff000072594000
pid 65 sleep for 1119 ms
[ 26.076725 INFO  nimbos::arch::aarch64::context][0:66] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff00007259c000
pid 66 sleep for 1945 ms
[ 26.130464 INFO  nimbos::arch::aarch64::context][0:67] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff0000725a0000
pid 67 sleep for 1290 ms
[ 26.137273 INFO  nimbos::arch::aarch64::context][0:68] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff0000725a4000
pid 68 sleep for 1267 ms
[ 26.144402 INFO  nimbos::arch::aarch64::context][0:69] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff0000725a8000
pid 69 sleep for 1088 ms
[ 26.151369 INFO  nimbos::arch::aarch64::context][0:70] user task start: entry=0x213e14, ustack=0xffffffffecc0, kstack=0xffff0000725ac000
pid 70 sleep for 1905 ms
pid 45 OK! expect sleep 1132 ms, actual sleep 1142 ms
[ 26.733333 INFO  nimbos::task::structs][0:45] task exit with code 0
pid 51 OK! expect sleep 1042 ms, actual sleep 1062 ms
[ 26.867266 INFO  nimbos::task::structs][0:51] task exit with code 0
pid 43 OK! expect sleep 1329 ms, actual sleep 1334 ms
[ 26.877009 INFO  nimbos::task::structs][0:43] task exit with code 0
pid 41 OK! expect sleep 1512 ms, actual sleep 1529 ms
[ 27.003029 INFO  nimbos::task::structs][0:41] task exit with code 0
pid 55 OK! expect sleep 1117 ms, actual sleep 1146 ms
[ 27.012491 INFO  nimbos::task::structs][0:55] task exit with code 0
pid 60 OK! expect sleep 1059 ms, actual sleep 1067 ms
[ 27.070620 INFO  nimbos::task::structs][0:60] task exit with code 0
pid 59 OK! expect sleep 1051 ms, actual sleep 1086 ms
[ 27.081687 INFO  nimbos::task::structs][0:59] task exit with code 0
pid 57 OK! expect sleep 1248 ms, actual sleep 1257 ms
[ 27.137959 INFO  nimbos::task::structs][0:57] task exit with code 0
pid 65 OK! expect sleep 1119 ms, actual sleep 1133 ms
[ 27.205922 INFO  nimbos::task::structs][0:65] task exit with code 0
pid 69 OK! expect sleep 1088 ms, actual sleep 1126 ms
[ 27.274176 INFO  nimbos::task::structs][0:69] task exit with code 0
pid 46 OK! expect sleep 1630 ms, actual sleep 1635 ms
[ 27.300664 INFO  nimbos::task::structs][0:46] task exit with code 0
pid 52 OK! expect sleep 1502 ms, actual sleep 1535 ms
[ 27.347087 INFO  nimbos::task::structs][0:52] task exit with code 0
pid 61 OK! expect sleep 1301 ms, actual sleep 1353 ms
[ 27.363005 INFO  nimbos::task::structs][0:61] task exit with code 0
pid 48 OK! expect sleep 1676 ms, actual sleep 1731 ms
[ 27.410802 INFO  nimbos::task::structs][0:48] task exit with code 0
pid 68 OK! expect sleep 1267 ms, actual sleep 1272 ms
[ 27.414101 INFO  nimbos::task::structs][0:68] task exit with code 0
pid 67 OK! expect sleep 1290 ms, actual sleep 1294 ms
[ 27.428780 INFO  nimbos::task::structs][0:67] task exit with code 0
pid 42 OK! expect sleep 1885 ms, actual sleep 1945 ms
[ 27.480476 INFO  nimbos::task::structs][0:42] task exit with code 0
pid 44 OK! expect sleep 1726 ms, actual sleep 1915 ms
[ 27.498885 INFO  nimbos::task::structs][0:44] task exit with code 0
pid 56 OK! expect sleep 1689 ms, actual sleep 1698 ms
[ 27.572325 INFO  nimbos::task::structs][0:56] task exit with code 0
pid 47 OK! expect sleep 1918 ms, actual sleep 1950 ms
[ 27.623148 INFO  nimbos::task::structs][0:47] task exit with code 0
pid 62 OK! expect sleep 1630 ms, actual sleep 1671 ms
[ 27.688703 INFO  nimbos::task::structs][0:62] task exit with code 0
pid 50 OK! expect sleep 1970 ms, actual sleep 1979 ms
[ 27.708085 INFO  nimbos::task::structs][0:50] task exit with code 0
pid 53 OK! expect sleep 1873 ms, actual sleep 1942 ms
[ 27.761493 INFO  nimbos::task::structs][0:53] task exit with code 0
pid 64 OK! expect sleep 1656 ms, actual sleep 1715 ms
[ 27.781081 INFO  nimbos::task::structs][0:64] task exit with code 0
pid 49 OK! expect sleep 1995 ms, actual sleep 2114 ms
[ 27.835401 INFO  nimbos::task::structs][0:49] task exit with code 0
pid 58 OK! expect sleep 1790 ms, actual sleep 1967 ms
[ 27.889751 INFO  nimbos::task::structs][0:58] task exit with code 0
pid 54 OK! expect sleep 1821 ms, actual sleep 2051 ms
[ 27.910773 INFO  nimbos::task::structs][0:54] task exit with code 0
pid 63 OK! expect sleep 1968 ms, actual sleep 1976 ms
[ 28.034432 INFO  nimbos::task::structs][0:63] task exit with code 0
pid 66 OK! expect sleep 1945 ms, actual sleep 2010 ms
[ 28.091396 INFO  nimbos::task::structs][0:66] task exit with code 0
pid 70 OK! expect sleep 1905 ms, actual sleep 1959 ms
[ 28.115097 INFO  nimbos::task::structs][0:70] task exit with code 0
forktest2 test passed!
[ 28.229107 INFO  nimbos::task::structs][0:40] task exit with code 0
Usertests: Test 'forktest2' in Process 40 exited with code 0.
Usertests: Running 'forktest_simple':
[ 28.303311 INFO  nimbos::arch::aarch64::context][0:71] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
parent start, pid = 71!
hello parent process, parent pid = 71, child pid = 72!
[ 28.376146 INFO  nimbos::task::structs][0:71] task exit with code 0
Usertests: Test 'forktest_simple' in Process 71 exited with code 0.
Usertests: Running 'hello_world':
[ 28.447363 INFO  nimbos::arch::aarch64::context][0:72] user task start: entry=0x213468, ustack=0xffffffffee30, kstack=0xffff0000725ac000
hello child process, child pid = 72!
[ 28.454044 INFO  nimbos::task::structs][0:72] task exit with code 100
[ 28.455616 INFO  nimbos::arch::aarch64::context][0:73] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
Hello world from user mode program!
[ 28.518205 INFO  nimbos::task::structs][0:73] task exit with code 0
Usertests: Test 'hello_world' in Process 73 exited with code 0.
Usertests: Running 'matrix':
[ 28.647396 INFO  nimbos::arch::aarch64::context][0:74] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
[ 28.727081 INFO  nimbos::arch::aarch64::context][0:75] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff0000725ac000
pid 75 is running (4490 times)!.
[ 28.837493 INFO  nimbos::arch::aarch64::context][0:76] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff00007292c000
[ 28.841734 INFO  nimbos::arch::aarch64::context][0:77] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072924000
[ 28.846301 INFO  nimbos::arch::aarch64::context][0:78] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072928000
[ 28.850551 INFO  nimbos::arch::aarch64::context][0:79] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff0000725a4000
pid 76 is running (6000 times)!.
pid 77 is running (3440 times)!.
pid 78 is running (1840 times)!.
pid 79 is running (6000 times)!.
[ 29.043096 INFO  nimbos::arch::aarch64::context][0:80] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff0000725a8000
[ 29.047286 INFO  nimbos::arch::aarch64::context][0:81] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff00007296c000
[ 29.051769 INFO  nimbos::arch::aarch64::context][0:82] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072934000
[ 29.055990 INFO  nimbos::arch::aarch64::context][0:83] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072938000
[ 29.060263 INFO  nimbos::arch::aarch64::context][0:84] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff00007293c000
pid 80 is running (7240 times)!.
pid 81 is running (9290 times)!.
pid 82 is running (7840 times)!.
pid 83 is running (5240 times)!.
pid 84 is running (6240 times)!.
[ 29.609322 INFO  nimbos::arch::aarch64::context][0:85] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072940000
[ 29.613316 INFO  nimbos::arch::aarch64::context][0:86] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff0000725b8000
[ 29.651409 INFO  nimbos::arch::aarch64::context][0:87] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff0000725bc000
[ 29.655559 INFO  nimbos::arch::aarch64::context][0:88] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff0000725c0000
pid 85 is running (4890 times)!.
pid 86 is running (6410 times)!.
pid 87 is running (9640 times)!.
pid 88 is running (7290 times)!.
[ 30.409355 INFO  nimbos::arch::aarch64::context][0:89] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072584000
[ 30.413464 INFO  nimbos::arch::aarch64::context][0:90] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072588000
[ 30.417530 INFO  nimbos::arch::aarch64::context][0:91] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072590000
[ 30.421927 INFO  nimbos::arch::aarch64::context][0:92] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072594000
pid 89 is running (9210 times)!.
pid 90 is running (410 times)!.
pid 91 is running (6490 times)!.
pid 92 is running (2760 times)!.
[ 31.369326 INFO  nimbos::arch::aarch64::context][0:93] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072598000
[ 31.373288 INFO  nimbos::arch::aarch64::context][0:94] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff00007259c000
[ 31.411396 INFO  nimbos::arch::aarch64::context][0:95] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072904000
[ 31.415594 INFO  nimbos::arch::aarch64::context][0:96] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072908000
pid 93 is running (5210 times)!.
pid 94 is running (4000 times)!.
pid 95 is running (3360 times)!.
pid 96 is running (10 times)!.
[ 32.569299 INFO  nimbos::arch::aarch64::context][0:97] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff00007290c000
[ 32.573376 INFO  nimbos::arch::aarch64::context][0:98] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072910000
[ 32.579867 INFO  nimbos::arch::aarch64::context][0:99] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072918000
[ 32.583888 INFO  nimbos::arch::aarch64::context][0:100] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff00007291c000
[ 32.587969 INFO  nimbos::arch::aarch64::context][0:101] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072920000
[ 32.592166 INFO  nimbos::arch::aarch64::context][0:102] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072944000
fork ok.
pid 96 done!.
[ 33.671396 INFO  nimbos::task::structs][0:96] task exit with code 0
pid 97 is running (6000 times)!.
pid 98 is running (8490 times)!.
pid 99 is running (3960 times)!.
pid 100 is running (4890 times)!.
pid 101 is running (3440 times)!.
pid 102 is running (8440 times)!.
[ 33.988434 INFO  nimbos::arch::aarch64::context][0:103] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072948000
[ 33.992737 INFO  nimbos::arch::aarch64::context][0:104] user task start: entry=0x214e98, ustack=0xffffffffee00, kstack=0xffff000072950000
pid 103 is running (6360 times)!.
pid 104 is running (9690 times)!.
pid 90 done!.
[ 57.961593 INFO  nimbos::task::structs][0:90] task exit with code 0
pid 78 done!.
[151.206642 INFO  nimbos::task::structs][0:78] task exit with code 0
pid 92 done!.
[216.623922 INFO  nimbos::task::structs][0:92] task exit with code 0
pid 95 done!.
[250.562662 INFO  nimbos::task::structs][0:95] task exit with code 0
pid 77 done!.
[252.341172 INFO  nimbos::task::structs][0:77] task exit with code 0
pid 101 done!.
[260.494565 INFO  nimbos::task::structs][0:101] task exit with code 0
pid 99 done!.
[285.729320 INFO  nimbos::task::structs][0:99] task exit with code 0
pid 94 done!.
[296.633542 INFO  nimbos::task::structs][0:94] task exit with code 0
pid 75 done!.
[321.144888 INFO  nimbos::task::structs][0:75] task exit with code 0
pid 83 done!.
[339.412161 INFO  nimbos::task::structs][0:83] task exit with code 0
pid 85 done!.
[339.481713 INFO  nimbos::task::structs][0:85] task exit with code 0
pid 100 done!.
[339.943851 INFO  nimbos::task::structs][0:100] task exit with code 0
pid 93 done!.
[346.652827 INFO  nimbos::task::structs][0:93] task exit with code 0
pid 79 done!.
[369.388766 INFO  nimbos::task::structs][0:79] task exit with code 0
pid 76 done!.
[373.117659 INFO  nimbos::task::structs][0:76] task exit with code 0
pid 97 done!.
[380.620051 INFO  nimbos::task::structs][0:97] task exit with code 0
pid 103 done!.
[385.973172 INFO  nimbos::task::structs][0:103] task exit with code 0
pid 84 done!.
[386.799875 INFO  nimbos::task::structs][0:84] task exit with code 0
pid 86 done!.
[386.855234 INFO  nimbos::task::structs][0:86] task exit with code 0
pid 91 done!.
[390.509459 INFO  nimbos::task::structs][0:91] task exit with code 0
pid 80 done!.
[407.790088 INFO  nimbos::task::structs][0:80] task exit with code 0
pid 88 done!.
[412.390529 INFO  nimbos::task::structs][0:88] task exit with code 0
pid 82 done!.
[415.494086 INFO  nimbos::task::structs][0:82] task exit with code 0
pid 98 done!.
[427.071482 INFO  nimbos::task::structs][0:98] task exit with code 0
pid 102 done!.
[427.623630 INFO  nimbos::task::structs][0:102] task exit with code 0
pid 89 done!.
[434.014018 INFO  nimbos::task::structs][0:89] task exit with code 0
pid 81 done!.
[435.760237 INFO  nimbos::task::structs][0:81] task exit with code 0
pid 87 done!.
[436.115542 INFO  nimbos::task::structs][0:87] task exit with code 0
pid 104 done!.
[436.643122 INFO  nimbos::task::structs][0:104] task exit with code 0
matrix passed!
[436.705866 INFO  nimbos::task::structs][0:74] task exit with code 0
Usertests: Test 'matrix' in Process 74 exited with code 0.
Usertests: Running 'sleep':
[436.778786 INFO  nimbos::arch::aarch64::context][0:105] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
[436.849081 INFO  nimbos::arch::aarch64::context][0:106] user task start: entry=0x214070, ustack=0xffffffffeea0, kstack=0xffff000072590000
sleep 1 x 1 seconds.
sleep 2 x 1 seconds.
sleep 3 x 1 seconds.
sleep 4 x 1 seconds.
sleep 5 x 1 seconds.
[441.916712 INFO  nimbos::task::structs][0:106] task exit with code 0
use 5104597 usecs.
sleep passed!
[441.948627 INFO  nimbos::task::structs][0:105] task exit with code 0
Usertests: Test 'sleep' in Process 105 exited with code 0.
Usertests: Running 'sleep_simple':
[442.054719 INFO  nimbos::arch::aarch64::context][0:107] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
into sleep test!
current time_usec = 442084370
time_msec = 443136731 after sleeping 1 seconds, delta = 52361us!
simple_sleep passed!
[443.138312 INFO  nimbos::task::structs][0:107] task exit with code 0
Usertests: Test 'sleep_simple' in Process 107 exited with code 0.
Usertests: Running 'stack_overflow':
[443.209386 INFO  nimbos::arch::aarch64::context][0:108] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
It should trigger segmentation fault!
d = 0
d = 1
d = 2
d = 3
d = 4
d = 5
d = 6
d = 7
d = 8
d = 9
d = 10
d = 11
d = 12
d = 13
d = 14
d = 15
d = 16
d = 17
d = 18
d = 19
d = 20
d = 21
d = 22
d = 23
d = 24
d = 25
d = 26
d = 27
d = 28
d = 29
d = 30
d = 31
d = 32
d = 33
d = 34
d = 35
d = 36
d = 37
d = 38
d = 39
d = 40
d = 41
d = 42
d = 43
d = 44
d = 45
d = 46
d = 47
d = 48
d = 49
d = 50
d = 51
d = 52
d = 53
d = 54
d = 55
d = 56
d = 57
d = 58
d = 59
d = 60
d = 61
d = 62
d = 63
d = 64
d = 65
d = 66
d = 67
d = 68
d = 69
d = 70
d = 71
d = 72
d = 73
d = 74
d = 75
d = 76
d = 77
d = 78
d = 79
d = 80
d = 81
d = 82
d = 83
d = 84
d = 85
d = 86
d = 87
d = 88
d = 89
d = 90
d = 91
d = 92
d = 93
d = 94
d = 95
d = 96
d = 97
d = 98
d = 99
d = 100
d = 101
d = 102
d = 103
d = 104
d = 105
d = 106
d = 107
d = 108
d = 109
d = 110
d = 111
d = 112
d = 113
d = 114
d = 115
d = 116
d = 117
d = 118
d = [443.340978 WARN  nimbos::arch::aarch64::trap][0:108] Page Fault @ 0x2202ec, FAR=0xffffffffafe0, ISS=0x47, kernel killed it.
[443.342815 INFO  nimbos::task::structs][0:108] task exit with code -1
Usertests: Test 'stack_overflow' in Process 108 exited with code -1.
Usertests: Running 'yield':
[443.414141 INFO  nimbos::arch::aarch64::context][0:109] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
Hello, I am process 109.
Back in process 109, iteration 0.
Back in process 109, iteration 1.
Back in process 109, iteration 2.
Back in process 109, iteration 3.
Back in process 109, iteration 4.
yield passed!
[443.483682 INFO  nimbos::task::structs][0:109] task exit with code 0
Usertests: Test 'yield' in Process 109 exited with code 0.
Usertests: Running 'thread_simple':
[443.555281 INFO  nimbos::arch::aarch64::context][0:110] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
[443.632999 INFO  nimbos::arch::aarch64::context][0:111] user task start: entry=0x2146d4, ustack=0x2368f0, kstack=0xffff000072590000
test user thread: pid = 111, arg = [443.640847 INFO  nimbos::arch::aarch64::context][0:112] user task start: entry=0x2146d4, ustack=0x23a8f0, kstack=0xffff00007292c000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 200
test user thread: pid = 112, arg = 0xbeef, sp = 0xdead, sp = 0x2367a0, global_var = 0
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 0x23a7a0, global_var = 300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 1900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 2000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 2100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 2200
test user thread: pid = 112, arg = 0x800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 2400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 2500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 2600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 2700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 2800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 2900
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3000
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3300
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 3700
test user thread: pid = 111, arg = 0xdeadbeef, sp = 0x23a7a0, global_var = 2300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 3900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 4900
test user thread: pid = 112, arg = 0xbeef, sp = 0x2367a0, global_var = 3800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5300
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 5900
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6000
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6300
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 6900
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 7000
test user thread: pid = , sp = 0x23a7a0, global_var = 5000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 7900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 8900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 9000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 9100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 9200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 111, arg = 0xdead, sp = 0x2367a0, global_var = 7100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 9400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 9500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 9600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 9700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 9800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 9900
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 10000
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 10100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 10200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 10300
test user thread: pid = 111, arg = 0xdead, sp = 0x9300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 10500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 10600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 10700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 10800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 10900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 11800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 2367a0, global_var = 10400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12000
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12300
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 12900
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13000
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13300
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 13900
test user thread: pid = 111, arg = 11900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 14900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 15900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 0xdead, sp = 0x2367a0, global_var = 14000
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16300
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 16900
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 17000
test user thread: pid = 11116000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17400
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17500
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17600
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17700
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17800
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 17900
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 18000
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 18100
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 18200
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 18300
test user thread: pid = 112, arg = 0xbeef, sp = 0x23a7a0, global_var = 18400
[444.188787 INFO  nimbos::task::structs][0:112] task exit with code -112
, arg = 0xdead, sp = 0x2367a0, global_var = 17100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 18500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 18600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 18700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 18800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 18900
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19000
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19100
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19200
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19300
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19400
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19500
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19600
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19700
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19800
test user thread: pid = 111, arg = 0xdead, sp = 0x2367a0, global_var = 19900
[444.247671 INFO  nimbos::task::structs][0:111] task exit with code -111
thread 111 exited with -111.
thread 112 exited with -112.
main thread exited.
[444.253018 INFO  nimbos::task::structs][0:110] task exit with code 0
Usertests: Test 'thread_simple' in Process 110 exited with code 0.
Usertests: Running 'cyclictest':
[444.442263 INFO  nimbos::arch::aarch64::context][0:113] user task start: entry=0x213d5c, ustack=0xffffffffecf0, kstack=0xffff000072580000
T:0 (0) P:0 I:1000 C:0 Min:10000 Act:0 Avg:0 Max:0
T:0 (114) P:0 I:1000 C:30307 Min:10 Act:605 Avg:2669 Max:36450
[541.259926 INFO  nimbos::task::structs][0:113] task exit with code 0
Usertests: Test 'cyclictest' in Process 113 exited with code 0.
usertests passed!
[541.263721 INFO  nimbos::task::structs][0:5] task exit with code 0
Shell: Process 5 exited with code 0
>> 
>> 
>> [541.327980 INFO  nimbos::task::structs][0:114] task exit with code 0