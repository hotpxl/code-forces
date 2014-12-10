exception InvalidInput

let (|>) x f = f x

let rec makeList = fun len f ->
  if len = 0 then
    []
  else
    (f ()) :: (makeList (len - 1) f)

let findAppearance = fun records n ->
  let all = Big_int.pred_big_int (Big_int.shift_left_big_int Big_int.unit_big_int (n + 1)) in
  let show = List.fold_left (fun accum (_, id) ->
      Big_int.shift_left_big_int Big_int.unit_big_int id
      |> Big_int.or_big_int accum
    ) Big_int.unit_big_int records
  in
  (show, Big_int.sub_big_int all show)

let findXMan = fun records n ->
  let all = Big_int.pred_big_int (Big_int.shift_left_big_int Big_int.unit_big_int (n + 1)) in
  List.fold_left (fun (onlineSet, x, xOnline) (goOnline, id) ->
    if goOnline then
      let onlineSet' =
        Big_int.shift_left_big_int Big_int.unit_big_int id
        |> Big_int.or_big_int onlineSet
      in
      let x' = if id <> x && not xOnline then -1 else x in
      let xOnline' = if id = x then true else xOnline in
      (onlineSet', x', xOnline')
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
      let nowEmpty = Big_int.eq_big_int Big_int.zero_big_int onlineSet' in
      let x' =
        if exists then
          x
        else
          if nowEmpty then
            id
          else
            -1
      in
      let xOnline' = if id = x || not exists then false else xOnline in
      (onlineSet', x', xOnline')
  ) (Big_int.zero_big_int, 0, true) records

let findNormalLeader = fun records possible ->
  List.fold_left (fun (onlineSet, possible) (goOnline, id) ->
    if goOnline then
      let onlineSet' = IntSet.add id onlineSet in
      let possible' =
        if not (IntSet.is_empty onlineSet) then
          IntSet.remove id possible
        else
          IntSet.singleton id
          |> IntSet.inter possible
      in
      (onlineSet', possible')
    else
      let onlineSet' = IntSet.remove id onlineSet in
      let possible' =
        if not (IntSet.is_empty onlineSet') then
          IntSet.remove id possible
        else
          possible
      in
      (onlineSet', possible')
  ) (IntSet.empty, possible) records

let printRes = fun result ->
  let l = IntSet.fold (fun ele l ->
    ele :: l
  ) result []
  |> List.rev
  in
  print_int (List.length l)
  |> print_newline;
  List.iter (fun ele -> Printf.printf "%d " ele) l

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
  let (_, xMan, _) = findXMan records in
  (* Not found *)
  (match xMan with
  | 0 ->
    let (_, ld) = findNormalLeader records show in
    printRes (IntSet.union hidden ld)
  | -1 ->
    printRes hidden
  | _ ->
    printRes (IntSet.add xMan hidden)
  )
  |> print_newline
