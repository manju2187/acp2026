#!/usr/bin/env bats

@test "basic act5" {
    run ./act5 <<< "hello
world"
    [ "$status" -eq 0 ]
    [[ "$output" == *"world"* ]]
    [[ "$output" == *"hello"* ]]
}

@test "same strings" {
    run ./act5 <<< "test
test"
    [ "$status" -eq 0 ]
    [[ "$output" == *"test"* ]]
}

@test "short strings" {
    run ./act5 <<< "a
b"
    [ "$status" -eq 0 ]
    [[ "$output" == *"b"* ]]
    [[ "$output" == *"a"* ]]
}