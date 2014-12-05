let compute_layer = fun i ->
  (1 + i) * i / 2

let rec try_with = fun target sum cur ->
  let new_sum = sum + compute_layer cur in
  if target < new_sum then
    cur - 1
  else
    try_with target new_sum (cur + 1)

let test = fun target ->
  try_with target 0 1

let () =
  Printf.printf "%d\n" (test (read_int ()))
