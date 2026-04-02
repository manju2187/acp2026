#!/usr/bin/env bats

@test "student 1 longer" {
    run ./act7 <<< "Rahul
Amit"
    [ "$status" -eq 0 ]
    [[ "$output" == *"student 1"* ]]
}

@test "student 2 longer" {
    run ./act7 <<< "Ram
Krishna"
    [ "$status" -eq 0 ]
    [[ "$output" == *"student 2"* ]]
}

@test "equal length act7" {
    run ./act7 <<< "Ravi
Aman"
    [ "$status" -eq 0 ]
    [[ "$output" == *"equal"* || "$output" == *"same"* ]]
}

@test "single character act7" {
    run ./act7 <<< "A
B"
    [ "$status" -eq 0 ]
}

@test "long act7" {
    run ./act7 <<< "Alexander
Bob"
    [ "$status" -eq 0 ]
    [[ "$output" == *"student 1"* ]]
}