open Set

exception Invalid_input

module IntSet = Set.Make(
  struct
    let compare = Pervasives.compare
    type t = int
  end
)

let (|>) x f = f x

let rec make_list = fun len f ->
  if len = 0 then
    []
  else
    (f ()) :: (make_list (len - 1) f)

let find_never_appeared = fun records ->
  List.fold_left (fun accum (_, ele) ->
    IntSet.add ele accum
  ) IntSet.empty records

let find_possible_leader = fun records ->
  List

let () =
  let (n, m) = read_line ()
  |> Str.split (Str.regexp " +")
  |> List.map int_of_string
  |> fun li ->
    match li with
    | a :: [b] ->
      (a, b)
    | _ ->
      raise Invalid_input
  in
  let records = make_list m (fun () ->
    read_line ()
    |> Str.split (Str.regexp " +")
    |> fun li -> match li with
      | a :: [b] ->
        ((if a = "+" then 1 else 0), (int_of_string b))
      | _ ->
        raise Invalid_input
  )
  in
  ignore (find_never_appeared records);
  ()
