exception Invalid_input

type status =
  | Stable
  | Safe

let (|>) x f = f x

let rec make_list = fun len f ->
  if len = 0 then
    []
  else
    f () :: make_list (len - 1) f

let rec prepend_list_to_list_of_list = fun li acc ->
  match li, acc with
  | h1 :: t1, h2 :: t2 -> (h1 :: h2) :: (prepend_list_to_list_of_list t1 t2)
  | _ -> acc

let string_to_list = fun s ->
  let len = String.length s in
  let rec do_string_to_list = fun s i ->
    if i < len then
      s.[i] :: do_string_to_list s (i + 1)
    else
      []
  in
  do_string_to_list s 0

let read_input = fun n m ->
  let rec do_read_input = fun i acc ->
    if i < n then
      let current_line =
        read_line ()
        |> string_to_list
      in
      prepend_list_to_list_of_list current_line acc
      |> do_read_input (i + 1)
    else
      acc
  in
  make_list m (fun () -> [])
  |> do_read_input 0

let process_one_column = fun status chars ->
  let rec need_to_remove = fun s_list c_list ->
    match s_list, c_list with
    | h1 :: (m1 :: t1 as p1), h2 :: (m2 :: t2 as p2) ->
      if h1 = Stable && h2 < m2 then
        true
      else
        need_to_remove p1 p2
    | _ ->
      false
  in
  if need_to_remove status chars then
    status, true
  else
    let rec get_new_status = fun s_list c_list ->
      match s_list, c_list with
      | h1 :: (m1 :: t1 as p1), h2 :: (m2 :: t2 as p2) ->
        let new_s =
          if h1 = Safe || m2 < h2 then
            Safe
          else
            Stable
        in
        new_s :: get_new_status p1 p2
      | hd :: [], _ ->
        [hd]
      | _ ->
        raise Invalid_input
    in
    (get_new_status status chars), false

let process_all_columns = fun n input ->
  let initial = make_list n (fun () -> Stable) in
  let rec do_process = fun status count input ->
    match input with
    | hd :: tl ->
      let new_status, removed = process_one_column status hd in
      let new_count = if removed then count + 1 else count in
      do_process new_status new_count tl
    | _ ->
      count
  in
  do_process initial 0 input

let () =
  let (n, m) =
    read_line ()
    |> Str.split (Str.regexp " +")
    |> List.map int_of_string
    |> fun li ->
        match li with
        | a :: [b] -> (a, b)
        | _ -> raise Invalid_input
  in
  let input = read_input n m in
  process_all_columns n input
  |> print_int
  |> print_newline
