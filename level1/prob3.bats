#!/usr/bin/env bats

@test "normal case" {
    run ./prob3 <<< "3
10 10 5
8 10 4
6 10 3"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* || "$output" == *"1"* ]]
}

@test "highest is last floor" {
    run ./prob3 <<< "3
5 5 2
6 6 3
10 10 5"
    [ "$status" -eq 0 ]
    [[ "$output" == *"2"* ]]
}

@test "single floor" {
    run ./prob3 <<< "1
10 10 5"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* ]]
}

@test "all same cost" {
    run ./prob3 <<< "3
10 10 5
10 10 5
10 10 5"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* ]]
}

@test "decimal values" {
    run ./prob3 <<< "2
10.5 10 5
8.2 10 4"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* ]]
}