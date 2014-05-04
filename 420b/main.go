package main

import (
  "fmt"
)

const maxIndex = 1563

type Status [maxIndex]int64

func (s *Status) init(num uint32) {
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
  var participantNum, messageNum int32
  var online, notPresent Status
  fmt.Scanf("%d %d", &participantNum, &messageNum)
  notPresent.init(uint32(participantNum))
  _ = online
  fmt.Println(notPresent[0])
}
