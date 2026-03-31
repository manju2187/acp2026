#!/usr/bin/env bats

@test "normal case multiple consumers" {
    run ./act3 <<< "3
1 100
2 200
3 150"
    [ "$status" -eq 0 ]
    [[ "$output" == *"2"* ]]
}

@test "all same units" {
    run ./act3 <<< "3
1 100
2 100
3 100"
    [ "$status" -eq 0 ]
    [[ "$output" == *"1"* ]]
}

@test "single consumer" {
    run ./act3 <<< "1
5 250"
    [ "$status" -eq 0 ]
    [[ "$output" == *"5"* ]]
}

@test "highest is last consumer" {
    run ./act3 <<< "3
1 50
2 60
3 200"
    [ "$status" -eq 0 ]
    [[ "$output" == *"3"* ]]
}