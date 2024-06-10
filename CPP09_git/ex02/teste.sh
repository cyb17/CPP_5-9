#!/bin/bash

# Compiler le programme
make
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Définir une fonction pour tester un cas et afficher les résultats
test_case() {
    local description=$1
    shift
    local args=("$@")

    echo "Testing: $description"
    ./PmergeMe "${args[@]}"
    local result=$?
    if [ $result -eq 0 ]; then
        echo "Result: Success"
    else
        echo "Result: Failure (exit code $result)"
    fi
    echo ""
}

# Cas de test
test_case "./PmergeMe" ""
test_case "./PmergeMe" "  		"
test_case "./PmergeMe" -1 2 jkl
test_case "./PmergeMe" "1   5" 9 4 7
test_case "./PmergeMe" 2147483648 3 5 9 7 6
test_case "./PmergeMe" 214748365476578769647 3 5 9 7 6

test_case "./PmergeMe" 3
test_case "./PmergeMe" 8 3
test_case "./PmergeMe" 3 4 5 6 7
test_case "./PmergeMe" 3 5 9 7 6
test_case "./PmergeMe" 2147483647 3 5 9 7 6
test_case "./PmergeMe" `shuf -i 1-100000 -n 100 | tr "\n" " "`
test_case "./PmergeMe" `shuf -i 1-100000 -n 500 | tr "\n" " "`
test_case "./PmergeMe" `shuf -i 1-100000 -n 1000 | tr "\n" " "`
test_case "./PmergeMe" `shuf -i 1-100000 -n 3000 | tr "\n" " "`

# Fin des tests
echo "All tests completed."