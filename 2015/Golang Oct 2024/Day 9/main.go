package main

import (
	"bufio"
	"log"
	"os"
)

type flights struct{
	to int
	from int
	dist int

}


func main() {

	path := "../textFiles/"
	fileName := "day9Test.txt"

	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	flights :=make([]flights,0 )

	for scanner.Scan() {
		text := scanner.Text()
		log.Println(text)
		flight.Push(getFlight(text))
	}

}

func getFlight(text string) -> flight {
	panic("unimplemented")
}



func partOne()