#!/usr/bin/env bats

@test "normal case 2 employees" {
    run ./act9 <<< "2
145 manju 40000
156 darshan 50000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"90000"* ]]
}

@test "single employee" {
    run ./act9 <<< "1
101 Rahul 25000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"25000"* ]]
}

@test "zero employees" {
    run ./act9 <<< "0"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* ]]
}

@test "multiple employees" {
    run ./act9 <<< "3
101 A 10000
102 B 20000
103 C 30000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"60000"* ]]
}

@test "large salary values" {
    run ./act9 <<< "2
201 X 100000
202 Y 200000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"300000"* ]]
}