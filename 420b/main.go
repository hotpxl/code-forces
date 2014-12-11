package main

import (
  "fmt"
  "strings"
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

func (s *Status) off(num uint32) {
  index := num / 64
  num = 1 << (num % 64)
  s[index] &= ^int64(num)
}

func (s *Status) on(num uint32) {
  index := num / 64
  num = 1 << (num % 64)
  s[index] |= int64(num)
}

func (s *Status) test(num uint32) bool {
  index := num / 64
  num = 1 << (num % 64)
  return (s[index] & int64(num)) != 0
}

func (s *Status) nonZero() bool {
  for i := 0; i < maxIndex; i++ {
    if s[i] != 0 {
      return true
    }
  }
  return false
}

func main() {
  var participantNum, messageNum int32
  var online, notPresent Status
  var flag int8
  var num, possible uint32
  fmt.Scanf("%d %d", &participantNum, &messageNum)
  notPresent.init(uint32(participantNum))
  fmt.Scanf("%c %d", &flag, &num)
  notPresent.off(num)
  possible = num
  if flag == '+' {
    online.on(num)
  }
  for messageNum--; 0 < messageNum; messageNum-- {
    fmt.Scanf("%c %d", &flag, &num)
    notPresent.off(num)
    if flag == '+' {
      if !online.nonZero() && num != possible {
        possible = 0
      }
      online.on(num)
    } else {
      if num != possible {
        if !online.test(num) {
          if !online.nonZero() {
            possible = num
          } else {
            possible = 0
          }
        }
        online.off(num)
      } else {
        online.off(num)
        if online.nonZero() {
          possible = 0
        }
      }
    }
  }
  if online.nonZero() && !online.test(possible) {
    possible = 0
  }
  notPresent.on(possible)
  notPresent.off(0)
  if notPresent.nonZero() {
    boss := make([]string, 0)
    for i := 1; i < 100000; i++ {
      if notPresent.test(uint32(i)) {
        boss = append(boss, fmt.Sprintf("%d", i))
      }
    }
    fmt.Println(len(boss))
    fmt.Println(strings.Join(boss, " "))
  } else {
    fmt.Println(0)
  }
}

