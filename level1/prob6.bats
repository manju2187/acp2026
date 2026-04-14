#!/usr/bin/env bats

@test "normal case 2 prob6s" {
    run ./prob6 <<< "2
101 dolo 2027
102 para 2026"
    [ "$status" -eq 0 ]
    [[ "$output" == *"dolo"* ]]
    [[ "$output" == *"para"* ]]
}

@test "single prob6" {
    run ./prob6 <<< "1
201 crocin 2025"
    [ "$status" -eq 0 ]
    [[ "$output" == *"crocin"* ]]
}

@test "zero prob6s" {
    run ./prob6 <<< "0"
    [ "$status" -eq 0 ]
}

@test "multiple prob6s" {
    run ./prob6 <<< "3
1 A 2024
2 B 2025
3 C 2026"
    [ "$status" -eq 0 ]
    [[ "$output" == *"A"* ]]
    [[ "$output" == *"B"* ]]
    [[ "$output" == *"C"* ]]
}

@test "large expiry years" {
    run ./prob6 <<< "2
10 X 2030
20 Y 2040"
    [ "$status" -eq 0 ]
    [[ "$output" == *"2030"* ]]
    [[ "$output" == *"2040"* ]]
}