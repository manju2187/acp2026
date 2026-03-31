#!/usr/bin/env bats

@test "normal case below 50 (free scheme)" {
    run ./act2 <<< "40
10"
    [ "$status" -eq 0 ]
    [[ "$output" == *"0"* ]]
}

@test "between 50 and 100 (normal billing)" {
    run ./act2 <<< "80
10"
    [ "$status" -eq 0 ]
    [[ "$output" == *"800"* ]]
}

@test "above 100 (extra charge applied)" {
    run ./act2 <<< "120
10"
    [ "$status" -eq 0 ]
    [[ "$output" == *"High consumption alert"* ]]
}

@test "edge case exactly 100 units" {
    run ./act2 <<< "100
10"
    [ "$status" -eq 0 ]
    [[ "$output" == *"1000"* ]]
}