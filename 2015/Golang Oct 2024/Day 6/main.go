package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

var lights = make([][]bool, 1000)
var lights2 = make([][]int, 1000)

func main() {

	for i := range lights {
		lights[i] = make([]bool, 1000)
	}

	for i := range lights2 {
		lights2[i] = make([]int, 1000)
	}

	path := "../textFiles/"
	fileName := "day6final.txt"

	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		text := scanner.Text()
		readLine(text)

	}
	fmt.Println("answer to day 6 part 1:", countNuberOfLightsTurnedOn())
	fmt.Println("answer to day 6 part 2:", countNuberOfLightsTurnedOn2())
	//fmt.Println("number of lightsTurned on:", countNuberOfLightsTurnedOn())

}

func readLine(line string) {
	x1 := 0
	y1 := 0
	x2 := 0
	y2 := 0

	if strings.Contains(line, "turn on") {
		//fmt.Println(line[8:])
		//fmt.Println(strings.Split(line[8:], " "))
		x1, y1 = getCoordinates(strings.Split(line[8:], " ")[0])
		x2, y2 = getCoordinates(strings.Split(line[8:], " ")[2])
		flipLights(x1, y1, x2, y2, false, true)
		flipLightsPt2(x1, y1, x2, y2, false, true)

	} else if strings.Contains(line, "toggle") {
		fmt.Println(line[7:])
		x1, y1 = getCoordinates(strings.Split(line[7:], " ")[0])
		x2, y2 = getCoordinates(strings.Split(line[7:], " ")[2])
		flipLights(x1, y1, x2, y2, true, false)
		flipLightsPt2(x1, y1, x2, y2, true, false)

	} else if strings.Contains(line, "turn off") {
		fmt.Println(line[9:])
		x1, y1 = getCoordinates(strings.Split(line[9:], " ")[0])
		x2, y2 = getCoordinates(strings.Split(line[9:], " ")[2])
		flipLights(x1, y1, x2, y2, false, false)
		flipLightsPt2(x1, y1, x2, y2, false, false)

	}
}

// func readLinePt2(line string) {
// 	x1 := 0
// 	y1 := 0
// 	x2 := 0
// 	y2 := 0
// 	if strings.Contains(line, "turn on") {
// 		fmt.Println(line[8:])
// 		fmt.Println(strings.Split(line[8:], " "))
// 		x1, y1 = getCoordinates(strings.Split(line[8:], " ")[0])
// 		x2, y2 = getCoordinates(strings.Split(line[8:], " ")[2])
// 		flipLightsPt2(x1, y1, x2, y2, false, true)
// 	} else if strings.Contains(line, "toggle") {
// 		fmt.Println(line[7:])
// 		x1, y1 = getCoordinates(strings.Split(line[7:], " ")[0])
// 		x2, y2 = getCoordinates(strings.Split(line[7:], " ")[2])
// 		flipLightsPt2(x1, y1, x2, y2, true, false)
// 	} else if strings.Contains(line, "turn off") {
// 		fmt.Println(line[9:])
// 		x1, y1 = getCoordinates(strings.Split(line[9:], " ")[0])
// 		x2, y2 = getCoordinates(strings.Split(line[9:], " ")[2])
// 		flipLightsPt2(x1, y1, x2, y2, false, false)
// 	}
// }

func getCoordinates(s string) (int, int) {
	x, _ := strconv.Atoi(strings.Split(s, ",")[0])
	y, _ := strconv.Atoi(strings.Split(s, ",")[1])
	return x, y
}

func flipLights(xStart, yStart, xStop, yStop int, isToggle bool, newValue bool) {
	for i := xStart; i <= xStop; i++ {
		for j := yStart; j <= yStop; j++ {
			if isToggle {
				lights[i][j] = !lights[i][j]
			} else {
				lights[i][j] = newValue
			}

		}
	}
}

func flipLightsPt2(xStart, yStart, xStop, yStop int, isToggle bool, newValue bool) {
	for i := xStart; i <= xStop; i++ {
		for j := yStart; j <= yStop; j++ {
			if isToggle {
				lights2[i][j] += 2
			} else if newValue {
				lights2[i][j] += 1
			} else {

				lights2[i][j] -= 1
				if lights2[i][j] < 0 {
					lights2[i][j] = 0
				}
			}

		}
	}
}

func countNuberOfLightsTurnedOn() int {

	cnt := 0

	for i := range lights {
		for j := range lights[0] {
			if lights[i][j] {
				cnt++
			}

		}
	}

	return cnt
}

func countNuberOfLightsTurnedOn2() int {

	cnt := 0

	for i := range lights2 {
		for j := range lights2[0] {
			cnt += lights2[i][j]

		}
	}

	return cnt
}
