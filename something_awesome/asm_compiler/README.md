---
# This is purely for pandoc, ignore this.
title: README
author: Hannah Ivy
header-includes:
geometry: "left=3cm,right=3cm,top=1cm,bottom=2cm"
date: \today
output:
  pdf_document:
    md_extensions: auto_identifiers
urlcolor: cyan
colorlinks: true
---

# ASM Compiler for 4001 and 4001

By \[Hannah Ivy](https://www.hannahi.com) <contact@hannahi.com>

This is compiled in to a .pdf using `pandoc ./README.md -o README.pdf`.

The program is run like so:

```
usage: python3 ./asm_4xxx.py \[-h] \[--verbose] processor filename outfile

usage: asm_4xxx.py \[-h] \[--verbose] processor filename outfile


positional arguments:
  processor      Processor: eg 4001, 4003
  filename       The file name to convert from
  outfile        The file name to convert to

optional arguments:
  -h, --help     show this help message and exit
  --verbose, -v  Shows the asm and instruction for each as it goes along.```
```

## Instruction Sets

### 4001

| Machine Code |  Instruction  | Description     |    Long Description        |
|--------------|---------------|-----------------|----------------------------|
|       0      |      hlt      |   Halt          | Stop the program           |
|       1      |     add 1     |   rax = rax+1   | Increase rax by 1          |
|       2      |     add 2     |   rax = rax+2   | Increase rax by 2          |
|       3      |     add 4     |   rax = rax+4   | Increase rax by 4          |
|       4      |     add 8     |   rax = rax+8   | Increase rax by 8          |
|       7      |      prt      |   Print rax     | Print the contents of rax  |

### 4003

| Machine Code |  Instruction      |         Description       |
|--------------|-------------------|---------------------------|
|       0      |      hlt          |          Halt             |
|       1      |     add rax, 1    |         rax = rax+1       |
|       2      |     sub rax, 1    |         rax = rax-1       |
|       3      |     add rbx, 1    |         rbx = rbx+1       |
|       4      |     sub rbx, 1    |         rax = rax-1       |
|       5      |    XCHG rax rbx   |      Swap rax <-> rbx     |
|       6      |      BEL          |         Ring Bell         |
|       7      |      prt          |         Print rax         |
|       8      |     jne rax 0 X   |  Jump to X if rax not 0   |
|       9      |      JE rax 0 X   |   Jump to X if rax == 0   |

# 4004

| Machine Code | Instruction         | Description            |
|--------------|---------------------|------------------------|
| 0            | hlt                 | Halt                   |
| 1            | add %rax $1         | rax = rax+1            |
| 2            | sub %rax $1         | rax = rax-1            |
| 3            | add %rbx $1         | rbx = rbx+1            |
| 4            | sub %rbx $1         | rax = rax-1            |
| 5            | add %rax %rbx       | rax = rax + rbx        |
| 6            | sub %rax %rbx       | rax = rax - rbx        |
| 7            | prt                 | Print rax              |
| 8            | jne %rax [label]    | Jump to X if rax not 0 |
| 9            | je %rax [label]     | Jump to X if rax == 0  |
| 10           | mov $val %rax       | rax = $val             |
| 11           | mov $val %rbx       | rbx = $val             |
| 12           | mov %rax [address]  | rax -> [address]       |
| 13           | mov %rax [address]  | rbx -> [address]       |
| 14           | xchg %rax [address] | rax <-> [address]      |
| 15           | xchg %rbx [address] | rbx <-> [address]      |

# 8005

| Machine Code | Instruction         | Description            |
|--------------|---------------------|------------------------|
| 0            | hlt                 | Halt                   |
| 1            | add %rax $1         | rax = rax+1            |
| 2            | sub %rax $1         | rax = rax-1            |
| 3            | add %rbx $1         | rbx = rbx+1            |
| 4            | sub %rbx $1         | rax = rax-1            |
| 5            | add %rax %rbx       | rax = rax + rbx        |
| 6            | sub %rax %rbx       | rax = rax - rbx        |
| 7            | prt                 | Print rax              |
| 8            | jne %rax [label]    | Jump to X if rax not 0 |
| 9            | je %rax [label]     | Jump to X if rax == 0  |
| 10           | mov $val %rax       | rax = $val             |
| 11           | mov $val %rbx       | rbx = $val             |
| 12           | mov %rax [address]  | rax -> [address]       |
| 13           | mov %rax [address]  | rbx -> [address]       |
| 14           | xchg %rax [address] | rax <-> [address]      |
| 15           | xchg %rbx [address] | rbx <-> [address]      |
| 16           | bel                 | Ring bell (yay!)       |
| 17           | prta                | Print rax as ascii     |
