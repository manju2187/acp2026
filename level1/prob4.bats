#!/usr/bin/env bats

@test "some modern prob4" {
    run ./prob4 <<< "1 Swift 2020 500000
2 Tesla 2023 2000000
3 BMW 2024 3000000
4 Alto 2019 300000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"Tesla"* ]]
    [[ "$output" == *"BMW"* ]]
}

@test "all old prob4" {
    run ./prob4 <<< "1 A 2020 100000
2 B 2021 200000
3 C 2022 300000
4 D 2020 400000"
    [ "$status" -eq 0 ]
    [[ "$output" != *"A"* ]]
    [[ "$output" != *"B"* ]]
}

@test "all modern prob4" {
    run ./prob4 <<< "1 X 2023 100000
2 Y 2024 200000
3 Z 2025 300000
4 W 2026 400000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"X"* ]]
    [[ "$output" == *"Y"* ]]
    [[ "$output" == *"Z"* ]]
    [[ "$output" == *"W"* ]]
}

@test "boundary year 2022" {
    run ./prob4 <<< "1 A 2022 100000
2 B 2023 200000
3 C 2021 300000
4 D 2024 400000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"B"* ]]
    [[ "$output" == *"D"* ]]
    [[ "$output" != *"A"* ]]
}

@test "mixed case" {
    run ./prob4 <<< "1 car1 2018 10000
2 car2 2023 20000
3 car3 2022 15000
4 car4 2025 30000"
    [ "$status" -eq 0 ]
    [[ "$output" == *"car2"* ]]
    [[ "$output" == *"car4"* ]]
}