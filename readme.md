# infix to postfix notation

Parser / converter, recognizes very simple infix expressions
and outputs the equivalent postfix expression.

Uses a rough implementation of Dijkstra's "shunting yard" algorithm.

Knows only real numbers and `+`, `-`, `/`, `*` operators.


## Build:
With [premake](https://premake.github.io/) installed, in project's directory:
```shell
premake gmake2 --file=./build/premake5.lua
make
```

## Usage:
```shell
./bin/shunting-yard <infix expression>

./bin/shunting-yard --help
```
