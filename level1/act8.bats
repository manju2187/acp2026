#!/usr/bin/env bats

@test "basic word hello" {
    run ./act8 <<< "hello"
    [ "$status" -eq 0 ]
    [[ "$output" == *"vowels = 2"* ]]
    [[ "$output" == *"consonants = 3"* ]]
}

@test "all vowels" {
    run ./act8 <<< "aeiou"
    [ "$status" -eq 0 ]
    [[ "$output" == *"vowels = 5"* ]]
    [[ "$output" == *"consonants = 0"* ]]
}

@test "all consonants" {
    run ./act8 <<< "bcdfg"
    [ "$status" -eq 0 ]
    [[ "$output" == *"vowels = 0"* ]]
    [[ "$output" == *"consonants = 5"* ]]
}

@test "mixed case" {
    run ./act8 <<< "ApPlE"
    [ "$status" -eq 0 ]
    [[ "$output" == *"vowels = 2"* ]]
    [[ "$output" == *"consonants = 3"* ]]
}

@test "single character vowel" {
    run ./act8 <<< "a"
    [ "$status" -eq 0 ]
    [[ "$output" == *"vowels = 1"* ]]
}

@test "single character consonant" {
    run ./act8 <<< "z"
    [ "$status" -eq 0 ]
    [[ "$output" == *"consonants = 1"* ]]
}