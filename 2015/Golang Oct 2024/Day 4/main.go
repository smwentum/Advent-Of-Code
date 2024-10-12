package main

import (
	"bufio"
	"crypto/md5"
	"encoding/hex"
	"fmt"
	"log"
	"os"
	"strconv"
)

func main() {
	path := "C:\\Users\\Sai Wentum\\Documents\\Programming Projects\\Advent Of Code\\2015\\Golang Oct 2024\\textFiles\\"
	fileName := "day4final.txt"
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
		fmt.Println(
			"The answer to Day2Part1",
			findFirstSpecialMD5Hash(scanner.Text()),
		)
	}
}

func findFirstSpecialMD5Hash(s string) int {
	i := 1
	for {
		hash := GetMD5Hash(s + strconv.Itoa(i))
		//fmt.Println("the value is i:", i, " :", hash[0:5])
		if hash[0:5] == "00000" {
			//fmt.Println("the value is i:", i, " :", hash[0:5])
			return i
		}
		i += 1
	}

}

func partTwo(path, fileName string) {
	file, err := os.Open(path + fileName)

	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		fmt.Println(
			"The answer to Day4Part2",
			findFirstSpecialMD5HashPt2(scanner.Text()),
		)
	}
}

func findFirstSpecialMD5HashPt2(s string) int {
	i := 1
	for {
		hash := GetMD5Hash(s + strconv.Itoa(i))
		//fmt.Println("the value is i:", i, " :", hash[0:5])
		if hash[0:6] == "000000" {
			//fmt.Println("the value is i:", i, " :", hash[0:5])
			return i
		}
		i += 1
	}

}
func GetMD5Hash(text string) string {
	hash := md5.Sum([]byte(text))
	return hex.EncodeToString(hash[:])
}
