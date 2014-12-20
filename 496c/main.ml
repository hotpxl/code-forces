exception Invalid_input

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
  ignore (List.map (List.map print_char) input)
