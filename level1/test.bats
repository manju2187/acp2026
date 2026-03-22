#!/usr/bin/env bats

@test "normal input test" {
    run ./demo9 <<< "3
1 A 10
2 B 20
3 C 30"
    [ "$status" -eq 0 ]
    [[ "$output" == *"1 A 10"* ]]
    [[ "$output" == *"2 B 20"* ]]
    [[ "$output" == *"3 C 30"* ]]
}

@test "single student test" {
    run ./demo9 <<< "1
5 X 50"
    [ "$status" -eq 0 ]
    [[ "$output" == *"5 X 50"* ]]
}

@test "zero student test" {
    run ./demo9 <<< "0"
    [ "$status" -eq 0 ]
}