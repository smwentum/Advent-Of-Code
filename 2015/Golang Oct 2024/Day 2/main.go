package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	path := "../textFiles/"
	fileName := "day2Final.txt"
	PartOne(path, fileName)
	//fileName = "day2part1test.txt"
	PartTwo(path, fileName)
}

func PartOne(path, fileName string) {
	//fmt.Println(path + fileName)
	//fmt.Println()
	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)
	sum := 0
	for scanner.Scan() {
		dimensions := strings.Split(scanner.Text(), "x")

		sum += getWrappingPaperDimensions(getNumberReturn0IfError(dimensions[0]),
			getNumberReturn0IfError(dimensions[1]),
			getNumberReturn0IfError(dimensions[2]))
	}
	fmt.Println("Answer to Day 2 Part 1:", sum)

}

func getNumberReturn0IfError(s string) int {
	n, err := strconv.Atoi(s)

	if err != nil {
		log.Fatal(err)
		return 0
	}
	return n
}

func getWrappingPaperDimensions(length, width, height int) int {
	totalWrappingPaper := 2*(length*width+length*height+width*height) + min(length*width, min(length*height, width*height))

	return totalWrappingPaper
}

func PartTwo(path, fileName string) {
	//fmt.Println(path + fileName)
	//fmt.Println()
	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)
	sum := 0
	for scanner.Scan() {
		dimensions := strings.Split(scanner.Text(), "x")

		sum += getWrappingRibbonDimensions(getNumberReturn0IfError(dimensions[0]),
			getNumberReturn0IfError(dimensions[1]),
			getNumberReturn0IfError(dimensions[2]))
	}
	fmt.Println("Answer to Day 2 Part 2:", sum)

}

func getWrappingRibbonDimensions(length, width, height int) int {
	totalWrappingRibbon := length*width*height + 2*min(length+width, min(length+height, width+height))

	return totalWrappingRibbon
}
