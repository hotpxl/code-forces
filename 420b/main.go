package main

import (
  "os"
  "bufio"
  "fmt"
  "strings"
  "strconv"
)

const maxIndex = 1563

type Status [maxIndex]int64

func (s *Status) init(num uint) {
  high := num / 64
  for i := high; 0 < i; i-- {
    s[i] = -1
  }
  if high == 0 {
    s[0] = ((1 << num) - 1) << 1
  } else {
    s[0] = -2
  }
}

func main() {
  bio := bufio.NewReader(os.Stdin)
  str, _ := bio.ReadString('\n')
  strSplit := strings.Fields(str)
  participantNum, _ := strconv.ParseUint(strSplit[0], 0, 0)
  messageNum := strSplit[1]
  online := new(Status)
  notPresent := new(Status)
  str, _ = bio.ReadString('\n')
  strSplit = strings.Fields(str)
  flag := strSplit[0]
  num, _ := strconv.ParseUint(strSplit[1], 0, 0)
  num = 1 << num
  fmt.Println(participantNum, messageNum)
}
