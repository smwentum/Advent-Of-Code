package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
	path := "../textFiles/"
	fileName := "day3final.txt"
	partOne(path, fileName)
	//fileName = "day3Test.txt"
	partTwo(path, fileName)
}

func partOne(path, fileName string) {

	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		fmt.Println("The answer to Day3Part1", getNumberOfHouseWhoGotAPresent(scanner.Text()))
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

func partTwo(path, fileName string) {

	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		fmt.Println("The answer to Day3Part1", getNumberOfHouseWhoGotAPresentPart2(scanner.Text()))
	}

}

func getNumberOfHouseWhoGotAPresentPart2(directions string) int {

	x := 0
	y := 0
	xRobo := 0
	yRobo := 0

	houses := make(map[string]int)
	houses[getStringFromTwoInts(x, y)] += 2

	for i, c := range directions {
		if i%2 == 0 {
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
		} else {
			switch c {
			case '^':
				yRobo += 1
			case 'v':
				yRobo -= 1
			case '>':
				xRobo += 1
			case '<':
				xRobo -= 1
			}
			houses[getStringFromTwoInts(xRobo, yRobo)]++
		}
	}

	return len(houses)
}
