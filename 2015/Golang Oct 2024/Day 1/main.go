package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {

	path := "C:\\Users\\Sai Wentum\\Documents\\Programming Projects\\Advent Of Code\\2015\\Golang Oct 2024\\textFiles\\"
	fileName := "day1Part1Final.txt"
	dayOne(path, fileName)
}

func dayOne(path, fileName string) {
	//fmt.Println(path + fileName)
	//fmt.Println()
	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	if scanner.Scan() {
		floorDirections := scanner.Text
		fmt.Println("Answer to Day 1 Part 1:", getFloor(floorDirections()))
	}
}

func getFloor(floorInstuctions string) int {
	answer := 0

	for _, c := range floorInstuctions {
		if c == ')' {
			answer--
		} else {
			answer++
		}
	}

	return answer
}
