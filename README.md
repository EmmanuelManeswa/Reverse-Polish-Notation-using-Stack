# Reverse-Polish-Notation-using-Stack

Supports single values[0-9], meaning if you try to use 2/more valued numbers, each digit is treated as
if it's on it's own.

Sample Output:

                SUPPORTED OPERATORS { (), +, -, *, /, $(power) }
                SUPPORTED NUMBERS [0-9]

                1. Enter Infix to convert.
                2. Exit
        Choice[1,2]: 1

        Infix expression: ((1+2)*3-(4/5))$(6+7)

        Postfix expression: 12+3*45/-67+$

                1. Enter Infix to convert.
                2. Exit
        Choice[1,2]: 1

        Infix expression: ((1+2)*3-(4/5))$6+7)

        Error: Missing '('.

                1. Enter Infix to convert.
                2. Exit
        Choice[1,2]: 1

        Infix expression: ((1+2)*3-(4/5))$(6+7

        Error!: Missing ')'.

                1. Enter Infix to convert.
                2. Exit
        Choice[1,2]: 2
