# TP_Grammaire-Langage

[![Build Status](https://travis-ci.org/heptastique/TP_Grammaire-Langage.svg?branch=master)](https://travis-ci.org/heptastique/TP_Grammaire-Langage)
[![Build status](https://ci.appveyor.com/api/projects/status/qukii1w1kmxf9864?svg=true)](https://ci.appveyor.com/project/heptastique/tp-grammaire-langage)

## How to compile
- Run make
```
$ make
```
## Usage
- Run TPLG
```
$ ./TPLG
```
- and enter an expression
- examples of valid expressions
```
5+5
2*3
5+5*5
3*4+3
5*(4+4)
```
- examples of invalid expressions
```
a
Erreur lexer.
```
```
33++
Erreur automate.
```
```
(5+3
Erreur automate.
```
```
5+3)
Erreur automate.
```
## Debugging
- Edit debug.h and uncomment the line
```
//#define DEBUG
```
