#!/usr/bin/env bats

@test "normal case 11 act4" {
    run ./act4 <<< "A 1 10
B 2 20
C 3 30
D 4 40
E 5 50
F 6 60
G 7 70
H 8 80
I 9 90
J 10 100
K 11 110"
    [ "$status" -eq 0 ]
    [[ "$output" == *"60"* ]]
}

@test "all zero runs" {
    run ./act4 <<< "A 1 0
B 2 0
C 3 0
D 4 0
E 5 0
F 6 0
G 7 0
H 8 0
I 9 0
J 10 0
K 11 0"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* ]]
}

@test "all same runs" {
    run ./act4 <<< "A 1 50
B 2 50
C 3 50
D 4 50
E 5 50
F 6 50
G 7 50
H 8 50
I 9 50
J 10 50
K 11 50"
    [ "$status" -eq 0 ]
    [[ "$output" == *"50"* ]]
}

@test "mixed values" {
    run ./act4 <<< "A 1 5
B 2 15
C 3 25
D 4 35
E 5 45
F 6 55
G 7 65
H 8 75
I 9 85
J 10 95
K 11 105"
    [ "$status" -eq 0 ]
    [[ "$output" == *"55"* ]]
}