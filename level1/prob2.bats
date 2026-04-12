#!/usr/bin/env bats

@test "prob2 1 highest" {
    run ./prob2 <<< "F1 10 10 5
F2 8 10 4
F3 6 10 3"
    [ "$status" -eq 0 ]
    [[ "$output" == *"F1"* ]]
}

@test "prob2 2 highest" {
    run ./prob2 <<< "F1 5 5 2
F2 10 10 5
F3 6 6 3"
    [ "$status" -eq 0 ]
    [[ "$output" == *"F2"* ]]
}

@test "prob2 3 highest" {
    run ./prob2 <<< "F1 5 5 2
F2 6 6 3
F3 10 10 5"
    [ "$status" -eq 0 ]
    [[ "$output" == *"F3"* ]]
}

@test "all equal costs" {
    run ./prob2 <<< "F1 10 10 5
F2 10 10 5
F3 10 10 5"
    [ "$status" -eq 0 ]
    [[ "$output" == *"F3"* ]]
}

@test "decimal values" {
    run ./prob2 <<< "F1 10.5 10 5
F2 8 10 4
F3 6 10 3"
    [ "$status" -eq 0 ]
    [[ "$output" == *"F1"* ]]
}