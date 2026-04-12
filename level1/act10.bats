#!/usr/bin/env bats

@test "normal case" {
    run ./act10 <<< "3
101 Delhi 5000
102 Mumbai 7000
103 Goa 6000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"102"* ]]
}

@test "single act10" {
    run ./act10 <<< "1
201 Dubai 15000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"201"* ]]
}

@test "last act10 highest" {
    run ./act10 <<< "3
1 A 100
2 B 200
3 C 300"
    [ "$status" -eq 0 ]
    [[ "$output" == *"3"* ]]
}

@test "first act10 highest" {
    run ./act10 <<< "3
10 X 900
20 Y 100
30 Z 200"
    [ "$status" -eq 0 ]
    [[ "$output" == *"10"* ]]
}

@test "all same prices" {
    run ./act10 <<< "3
1 A 500
2 B 500
3 C 500"
    [ "$status" -eq 0 ]
    [[ "$output" == *"1"* ]]
}