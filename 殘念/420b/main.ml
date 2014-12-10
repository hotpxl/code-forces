exception InvalidInput

let (|>) x f = f x

let rec makeList = fun len f ->
  if len = 0 then
    []
  else
    (f ()) :: (makeList (len - 1) f)

let printRes = fun result ->
  let rec printOne = fun number n ->
    let newNumber = Big_int.shift_right_big_int number 1 in
    if Big_int.eq_big_int number Big_int.zero_big_int then
      []
    else if Big_int.eq_big_int (Big_int.and_big_int Big_int.unit_big_int number) Big_int.zero_big_int then
      printOne newNumber (n + 1)
    else
      n :: (printOne newNumber (n + 1))
  in
  let l = printOne (Big_int.shift_right_big_int result 1) 1 in
  print_int (List.length l) |> print_newline;
  List.iter (fun ele -> Printf.printf "%d " ele) l
  |> print_newline

let findAppearance = fun records n ->
  let all = Big_int.pred_big_int (Big_int.shift_left_big_int Big_int.unit_big_int (n + 1)) in
  let show = List.fold_left (fun accum (_, id) ->
      Big_int.shift_left_big_int Big_int.unit_big_int id
      |> Big_int.or_big_int accum
    ) Big_int.unit_big_int records
  in
  (show, Big_int.sub_big_int all show)

let findLastXMan = fun records n ->
  let all = Big_int.pred_big_int (Big_int.shift_left_big_int Big_int.unit_big_int (n + 1)) in
  List.fold_left (fun (onlineSet, x) (goOnline, id) ->
    if goOnline then
      let onlineSet' =
        Big_int.shift_left_big_int Big_int.unit_big_int id
        |> Big_int.or_big_int onlineSet
      in
      (onlineSet', x)
    else
      let onlineSet' =
        Big_int.shift_left_big_int Big_int.unit_big_int id
        |> Big_int.xor_big_int all
        |> Big_int.and_big_int onlineSet
      in
      let exists =
        Big_int.shift_left_big_int Big_int.unit_big_int id
        |> Big_int.and_big_int onlineSet
        |> Big_int.eq_big_int Big_int.zero_big_int
        |> not
      in
      let x' = if exists then x else id in
      (onlineSet', x')
  ) (Big_int.zero_big_int, 0) records

let findLeader = fun records possible n ->
  let all = Big_int.pred_big_int (Big_int.shift_left_big_int Big_int.unit_big_int (n + 1)) in
  let rec process = fun records onlineSet possible ->
      match records with
      | (goOnline, id) :: tl ->
        if goOnline then
          let onlineSet' =
            Big_int.shift_left_big_int Big_int.unit_big_int id
            |> Big_int.or_big_int onlineSet
          in
          if Big_int.eq_big_int Big_int.zero_big_int onlineSet && id <> possible then
            -1
          else
            process tl onlineSet' possible
        else
          let onlineSet' =
            Big_int.shift_left_big_int Big_int.unit_big_int id
            |> Big_int.xor_big_int all
            |> Big_int.and_big_int onlineSet
          in
          if not (Big_int.eq_big_int Big_int.zero_big_int onlineSet') && id = possible then
            -1
          else
            process tl onlineSet' possible
      | [] ->
        possible
  in
  process records (Big_int.shift_left_big_int Big_int.unit_big_int possible) possible

let () =
  let (n, m) = read_line ()
  |> Str.split (Str.regexp " +")
  |> List.map int_of_string
  |> fun li ->
    match li with
    | a :: [b] ->
      (a, b)
    | _ ->
      raise InvalidInput
  in
  let records = makeList m (fun () ->
    read_line ()
    |> Str.split (Str.regexp " +")
    |> fun li -> match li with
      | a :: [b] ->
        (a = "+", int_of_string b)
      | _ ->
        raise InvalidInput
  )
  |> List.rev
  in
  let (show, hidden) = findAppearance records n in
  let (_, xMan) = findLastXMan records n in
  let possible =
    if xMan = 0 then
      let (_, id) = List.hd records in
      id
    else
      xMan
  in
  let res = findLeader records possible n in
  if res = -1 then
    printRes hidden
  else
    Big_int.shift_left_big_int Big_int.unit_big_int res
    |> Big_int.or_big_int hidden
    |> printRes
