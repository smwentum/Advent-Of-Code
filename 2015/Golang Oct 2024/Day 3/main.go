package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	path := "C:\\Users\\Sai Wentum\\Documents\\Programming Projects\\Advent Of Code\\2015\\Golang Oct 2024\\textFiles\\"
	fileName := "day3final.txt"
	partOne(path, fileName)
	//fileName = "day3Test.txt"
	//PartTwo(path, fileName)
}

func partOne(path, fileName string) {

	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		fmt.Println("The answer to Day1Part1", getNumberOfHouseWhoGotAPresent(scanner.Text()))
	}

}

func getNumberOfHouseWhoGotAPresent(directions string) int {

	x := 0
	y := 0

	houses := make(map[string]int)
	houses[getStringFromTwoInts(x, y)]++
	for _, c := range directions {

		switch c {
		case '^':
			y += 1
		case 'v':
			y -= 1
		case '>':
			x += 1
		case '<':
			x -= 1
		}
		houses[getStringFromTwoInts(x, y)]++
	}

	return len(houses)
}
func getStringFromTwoInts(row, col int) string {
	return fmt.Sprintf("%d,%d", row, col)
}
