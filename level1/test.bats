#!/usr/bin/env bats

@test "normal test" {
    run ./demo7 <<< "3
10
20
30"
    [ "$status" -eq 0 ]
    [[ "$output" == *"60"* ]]
}

@test "single player" {
    run ./demo7 <<< "1
50"
    [[ "$output" == *"50"* ]]
}

@test "zero player" {
    run ./demo7 <<< "0"
    [[ "$output" == *"no players"* ]]
}