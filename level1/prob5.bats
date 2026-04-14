#!/usr/bin/env bats

@test "normal swap check" {
    run ./prob5 <<< "Alice
20
Bob
25"
    [ "$status" -eq 0 ]

    [[ "$output" == *"Alice"* ]]
    [[ "$output" == *"Bob"* ]]
    [[ "$output" == *"25"* ]]
    [[ "$output" == *"20"* ]]
}

@test "swap correctness order" {
    run ./prob5 <<< "A
10
B
20"
    [ "$status" -eq 0 ]

    [[ "$output" == *"details of swapped first student"* ]]
    [[ "$output" == *"B"* ]]
    [[ "$output" == *"20"* ]]
}

@test "same values" {
    run ./prob5 <<< "Same
30
Same
30"
    [ "$status" -eq 0 ]

    [[ "$output" == *"Same"* ]]
    [[ "$output" == *"30"* ]]
}

@test "edge ages" {
    run ./prob5 <<< "X
0
Y
100"
    [ "$status" -eq 0 ]

    [[ "$output" == *"0"* ]]
    [[ "$output" == *"100"* ]]
}

@test "short names" {
    run ./prob5 <<< "A
1
B
2"
    [ "$status" -eq 0 ]

    [[ "$output" == *"A"* ]]
    [[ "$output" == *"B"* ]]
}