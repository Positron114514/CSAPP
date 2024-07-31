# ASM All in one

> In Intel x86 Instruction set

## 1. Suffix

Most commands has Suffix, which marks its operand's type and size.

| Suffix | Full name | Meaning|
|:------:|:------:|:----------|
b | byte | 1 byte  (8)
w | word | 2 bytes (16)
l | long | 4 bytes (32)
q | quard | 8 bytes (64)

## 2. Commands

Commands can be divided into several types, including: 

- information access
- Arithmetic and logic operations

Mostly, the ans is saved in the last reg.

Imm number: `$<number>`. Example: `mov $4, %rax`

### 2.1  information access

- `mov <src> <dest>` : move the value of `<src> `to `<dest>`
- `pushq <reg>`: push the value of the `<reg>` to the stack
- `popq <reg>`: pop the first element from the stack and save to `<reg>`

### 2.2 Arithmetic and logic operations

This type can be divided into:

- Load effective address
- 1-elem operations
- 2-elem operations
- shift operations

#### 2.2.1 Load effective address

`leaq <addrExp>, <reg>`: calculate the value of `<addrExp>` and save to `<reg>`

This command is used by gcc to solve some complex calculates because `leaq` follows the syntax of address expressions. See this in [lea.s](./lea.s)

#### 2.2.2 1/2-elem operations

- 1-elem: 
  - `inc <reg>`: same as reg++
  - `dec <reg>`: same as reg--
  - `neg <reg>`: -`<reg>`
  - `not <reg>`: ~
- 2-elem
  - `add S, D`: D += S 
  - `sub S, D`: D -= S 
  - `imul S, D`: D *= S 
  - `xor S, D`: D = D ^ S 
  - `or S, D`: D = D | S 
  - `and S, D`: D = S & D 

#### 2.2.3 shift operations

- `sal k, D`: D = D << k
- `shl k, D`: D = D << k
- `sar k, D`: D = D >> k
- `shr k, D`: D = D >>> k

#### 2.2.4 special operations

x86-64 supports mult of two 64-bit number, which creates an 128-bit number.

the result will be saved in `%rax : %rdx`

- `imulq S`: S * R[%rax] (signed)
- `mulq S`: S * R[%rax] (unsigned)
- `clto`: %rax -> 128-bit (symbol expanshion)
- `idivq S`: signed div. %rax: quotient; %rdx: remainder
- `divq S`: unsigned div

%rax: low; %rdx: high

## 2.3 Control

