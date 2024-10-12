package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"slices"
)

func main() {

	path := "../textFiles/"
	fileName := "day5final.txt"
	partOne(path, fileName)
	// //fileName = "day3Test.txt"
	// partTwo(path, fileName)
}

func partOne(path, fileName string) {
	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)
	cnt := 0
	for scanner.Scan() {
		text := scanner.Text()
		if isNice(text) {
			//fmt.Println(text, " is nice")
			cnt++

		} else {
			//fmt.Println(text, " is naughty")
		}
	}
	fmt.Println("answer to day 5 part 1:", cnt)
}

func isNice(str string) bool {

	return hasAtLeastThreeVowels(str) && twoLettersNextToEachOther(str) && doesntHaveCertainStrings(str)
}

func hasAtLeastThreeVowels(str string) bool {

	vowels := []rune{'a', 'e', 'i', 'o', 'u'}
	vowelCount := make(map[rune]int)
	for _, c := range str {
		if slices.Contains(vowels, c) {
			vowelCount[c]++
		}

	}

	sum := 0
	for _, val := range vowelCount {
		sum += val
	}
	//fmt.Println("has at least three vowels", sum)
	return sum >= 3
}

func twoLettersNextToEachOther(str string) bool {

	for i, _ := range str {
		if i < len(str)-1 {
			if str[i] == str[i+1] {
				return true
			}
		}

	}
	return false
}

func doesntHaveCertainStrings(s string) bool {
	badStrings := []string{"ab", "cd", "pq", "xy"}
	for i, _ := range s {
		if i < len(s)-1 {
			if slices.Contains(badStrings, s[i:i+2]) {
				return false
			}
		}

	}
	return true
}
