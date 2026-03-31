#!/usr/bin/env bats

@test "normal case" {
    run ./act6 <<< "3
10
20
30"
    [ "$status" -eq 0 ]
    [[ "$output" == *"60"* ]]
}

@test "single player" {
    run ./act6 <<< "1
50"
    [ "$status" -eq 0 ]
    [[ "$output" == *"50"* ]]
}

@test "zero players" {
    run ./act6 <<< "0"
    [ "$status" -eq 0 ]
}

@test "multiple values" {
    run ./act6 <<< "5
1
2
3
4
5"
    [ "$status" -eq 0 ]
    [[ "$output" == *"15"* ]]
}