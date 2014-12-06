exception Invalid_input

let (|>) x f = f x

let rec make_list = fun len f ->
  if len = 0 then
    []
  else
    (f ()) :: (make_list (len - 1) f)

let rec count_essay = fun maximum_grade target l ->
  let open Int64 in
  if (compare target zero) <= 0 then
    zero
  else
    let (grade, essay) = List.hd l in
    let grade_up = sub maximum_grade (of_int grade) in
    if (compare grade_up target) <= 0 then
      (add (mul grade_up (of_int essay)) (count_essay maximum_grade (sub target grade_up) (List.tl l)))
    else
      (mul target (of_int essay))

let () =
  let (n, r, avg) = read_line ()
    |> Str.split (Str.regexp " +")
    |> List.map int_of_string
    |> fun li ->
      match li with
      | a :: b :: [c] ->
        (a, b, c)
      | _ ->
        raise Invalid_input
  in
  let exams = make_list n (fun () ->
    read_line ()
    |> Str.split (Str.regexp " +")
    |> List.map int_of_string
    |> fun li ->
      match li with
      | a :: [b] ->
        (a, b)
      | _ ->
        raise Invalid_input
  )
  |> List.fast_sort (fun (_, a) (_, b) -> a - b)
  in
  let current_score = exams
  |> List.fold_left (fun sum (a, _) -> Int64.(add sum (of_int a))) Int64.zero
  in
  exams
  |> count_essay (Int64.of_int r) Int64.(sub (mul (of_int n) (of_int avg)) current_score)
  |> Int64.to_string
  |> print_string
  |> print_newline

