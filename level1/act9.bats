#!/usr/bin/env bats

@test "normal case 2 employees" {
    run ./act9 <<< "2
<<<<<<< HEAD
145
manju
40000
156
darshan
50000"
=======
145 manju 40000
156 darshan 50000"
>>>>>>> a69296efa42ba496a65c0c8a8562db3b3c2bdcc5
    [ "$status" -eq 0 ]
    [[ "$output" == *"90000"* ]]
}

@test "single employee" {
    run ./act9 <<< "1
<<<<<<< HEAD
101
rahul
25000"
=======
101 Rahul 25000"
>>>>>>> a69296efa42ba496a65c0c8a8562db3b3c2bdcc5
    [ "$status" -eq 0 ]
    [[ "$output" == *"25000"* ]]
}

@test "zero employees" {
    run ./act9 <<< "0"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* ]]
}

@test "multiple employees" {
    run ./act9 <<< "3
<<<<<<< HEAD
101
a
10000
102
b
20000
103
c
30000"
=======
101 A 10000
102 B 20000
103 C 30000"
>>>>>>> a69296efa42ba496a65c0c8a8562db3b3c2bdcc5
    [ "$status" -eq 0 ]
    [[ "$output" == *"60000"* ]]
}

<<<<<<< HEAD
@test "large values" {
    run ./act9 <<< "2
201
x
100000
202
y
200000"
=======
@test "large salary values" {
    run ./act9 <<< "2
201 X 100000
202 Y 200000"
>>>>>>> a69296efa42ba496a65c0c8a8562db3b3c2bdcc5
    [ "$status" -eq 0 ]
    [[ "$output" == *"300000"* ]]
}