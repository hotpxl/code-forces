open Str

let print_tuple = fun tuple ->
  let (x, y) = tuple in
  Printf.printf "%d %d\n" x y

let rec print_list = fun l ->
  match l with
  | hd :: tl ->
    print_int hd;
    print_char ' ';
    print_list tl;
  | _ -> ()

let rec find_max_gap = fun l cur_max ->
  match l with
  | hd :: mid :: tl ->
    let diff = mid - hd in
    if diff < cur_max then
      find_max_gap (mid :: tl) cur_max
    else
      find_max_gap (mid :: tl) diff
  | _ -> cur_max

let rec get_last = fun l ->
  match l with
  | [x] ->
    Some x
  | _ :: tl ->
    get_last tl
  | _ -> None

exception Invalid_input

let find_max_gap_including_head_and_tail = fun l e ->
  match get_last l with
  | Some last ->
    List.hd (List.fast_sort (fun i j ->
      if i < j then
        1
      else
        -1
    ) ([(float_of_int (List.hd l)); (float_of_int (e - last)); (float_of_int (find_max_gap l 0)) /. 2.0])
    )
  | None -> raise Invalid_input

let () =
  let (num_of_lanterns, len_of_street) = (fun line ->
    match line with
    | hd :: tl -> (int_of_string hd, int_of_string (List.hd tl))
    | _ -> raise Invalid_input
  ) (Str.split (Str.regexp " +") (read_line ()))
  in
  let lanterns = List.fast_sort (fun i j ->
    i - j
  ) (List.map int_of_string (Str.split (Str.regexp " +") (read_line ())))
  in
  print_float (find_max_gap_including_head_and_tail lanterns len_of_street);
  print_newline ()

