#!/usr/bin/env bats

@test "normal temperature test" {
    run ./act1 <<< "10
20
30
25
15
5
12"
    [ "$status" -eq 0 ]
    [[ "$output" == *"30"* ]]
    [[ "$output" == *"5"* ]]
}

@test "all same values" {
    run ./act1 <<< "10
10
10
10
10
10
10"
    [ "$status" -eq 0 ]
    [[ "$output" == *"10"* ]]
}

@test "negative temperatures" {
    run ./act1 <<< "-5
-10
0
3
2
-1
-7"
    [ "$status" -eq 0 ]
    [[ "$output" == *"3"* ]]
    [[ "$output" == *"-10"* ]]
}

@test "mixed values" {
    run ./act1 <<< "1.5
2.3
0.5
4.2
3.1
-1.0
2.0"
    [ "$status" -eq 0 ]
    [[ "$output" == *"4.2"* ]]
    [[ "$output" == *"-1.0"* ]]
}