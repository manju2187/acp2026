#!/usr/bin/env bats

@test "normal case" {
    run ./prob1 <<< "5
10
20
30
40
50"
    [ "$status" -eq 0 ]
    [[ "$output" == *"50"* ]]
    [[ "$output" == *"10"* ]]
}

@test "single student" {
    run ./prob1 <<< "1
75"
    [ "$status" -eq 0 ]
    [[ "$output" == *"75"* ]]
}

@test "all same prob1" {
    run ./prob1 <<< "3
50
50
50"
    [ "$status" -eq 0 ]
    [[ "$output" == *"50"* ]]
}

@test "descending order" {
    run ./prob1 <<< "4
90
80
70
60"
    [ "$status" -eq 0 ]
    [[ "$output" == *"90"* ]]
    [[ "$output" == *"60"* ]]
}

@test "decimal values" {
    run ./prob1 <<< "3
12.5
45.7
30.2"
    [ "$status" -eq 0 ]
    [[ "$output" == *"45.7"* || "$output" == *"45"* ]]
}